#ifndef MAP_HPP
#define MAP_HPP

#include "utility.hpp"
#include "iterator_traits.hpp"

#include "Node.hpp"
#include "AVLTree.hpp"

namespace ft {

template <	class Key,
			class T,
			class Compare = std::less<Key>,
			class Alloc = std::allocator< ft::pair< const Key, T > >
		 >
class map {

	/* -------------------------------------------------------------------------- */
	/*                                MEMBER TYPES                                */
	/* -------------------------------------------------------------------------- */

	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef ft::pair<const key_type, mapped_type>		value_type;
		typedef Compare										key_compare;
		// typedef --- value_compare; // NOTE: it is on cplusplus.com
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef typename allocator_type::size_type size_type;

	
		/* -------------------------------------------------------------------------- */
		/*                                VALUE COMPARE                               */
		/* -------------------------------------------------------------------------- */

		class value_compare { // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class ft::AVLTree<value_type, value_compare, allocator_type>;

			protected:
				Compare comp;
				value_compare(Compare c = key_compare()) : comp(c) {} // constructed with map's comparison object
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator()(const value_type &x, const value_type &y) const { return comp(x.first, y.first); }
				bool operator()(const key_type& key, const value_type &y) const { return comp(key, y.first); }
				bool operator()(const value_type &x, const key_type& key) const { return comp(x.first, key); }
		};

		typedef ft::AVLTree<value_type, value_compare, allocator_type> tree_type;
		typedef typename tree_type::node node;
		typedef typename tree_type::node_pointer node_pointer;

		typedef typename tree_type::iterator				iterator;
		typedef typename tree_type::const_iterator			const_iterator;
		typedef typename tree_type::reverse_iterator		reverse_iterator;
		typedef typename tree_type::const_reverse_iterator	const_reverse_iterator;

	/* -------------------------------------------------------------------------- */
	/*                              MEMBER VARIABLES                              */
	/* -------------------------------------------------------------------------- */

	private:
		tree_type	_tree;

	/* -------------------------------------------------------------------------- */
	/*                              MEMBER FUNCTIONS                              */
	/* -------------------------------------------------------------------------- */

		/* -------------------------------------------------------------------------- */
		/*                          CONSTRUCTORS & DESTRUCTOR                         */
		/* -------------------------------------------------------------------------- */

		/* ------------------------------ CONSTRUCTORS ------------------------------ */

	public:

		// empty/default constructor
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(tree_type()) { (void) comp; (void) alloc; }
		// range constructor
		// template <class InputIterator>  map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}
		// copy constructor
		// map (const map& x) {}

		/* ------------------------------- DESTRUCTOR ------------------------------- */
		// ~map() {}

		/* --------------------------- ASSIGNMENT OPERATOR -------------------------- */
		// map& operator=(const map& x) {}


		/* -------------------------------------------------------------------------- */
		/*                                  ITERATORS                                 */
		/* -------------------------------------------------------------------------- */

	public:
		iterator begin() { return (this->_tree.begin()); }
		const_iterator begin() const { return (this->_tree.begin()); }
		iterator end() { return (this->_tree.end()); }
		const_iterator end() const { return (this->_tree.end()); }

		reverse_iterator rbegin() { return (this->_tree.rbegin()); }
		const_reverse_iterator rbegin() const { return (this->_tree.rbegin()); }
		reverse_iterator rend() { return (this->_tree.rend()); }
		const_reverse_iterator rend() const { return (this->_tree.rend()); }

		/* -------------------------------------------------------------------------- */
		/*                                  CAPACITY                                  */
		/* -------------------------------------------------------------------------- */

		bool empty() const { return (this->_tree.empty()); }
		size_type size() const { return (this->_tree.size()); }
		// size_type max_size() const {}

		/* -------------------------------------------------------------------------- */
		/*                               ELEMENT ACCESS                               */
		/* -------------------------------------------------------------------------- */

	public:
		mapped_type& operator[](const key_type& k) {
			ft::pair<iterator, bool> res = this->insert(value_type(k, mapped_type()));
			return ( (res.first)->second );
		}

		mapped_type& at(const key_type& k){
			iterator success = this->_tree.find(k);
			if (success == this->end())
				throw std::out_of_range("ft::out_of_range");
			return (success->second);
		}

		// const mapped_type& at(const key_type& k) const{
		// 	iterator success = this->_tree.find(k);
		// 	if (success == this->end())
		// 		throw std::out_of_range("ft::out_of_range");
		// 	return (success->second);
		// }

		/* -------------------------------------------------------------------------- */
		/*                                  MODIFIERS                                 */
		/* -------------------------------------------------------------------------- */

	public:

		/* --------------------------------- INSERTS -------------------------------- */
		// single element
		ft::pair<iterator, bool> insert(const value_type& val) {
			return (this->_tree.insert(val));
		}
		// with hint
		iterator insert(iterator pos, const value_type& val) {
			(void) pos;
			ft::pair<iterator, bool> res = this->insert(val);
			return (res.first);
		}
		// range
		template < class InputIterator > // TODO: test if it works
		void insert(InputIterator first, InputIterator last) {
			for (; first != last; ++first)
				this->insert(*first);
		}
		/* -------------------------------------------------------------------------- */

		/* ---------------------------------- ERASE --------------------------------- */
		// void erase(iterator position) {}
		// size_type erase(const key_type& k) {}
		// void erase(iterator first, iterator last) {}
		/* -------------------------------------------------------------------------- */

		// void swap(map& x) {}
		// void clear();

		/* -------------------------------------------------------------------------- */
		/*                                  OBSERVERS                                 */
		/* -------------------------------------------------------------------------- */

		// key_compare key_comp() const {}
		// value_compare value_comp() const {}

		/* -------------------------------------------------------------------------- */
		/*                                   LOOKUP                                   */
		/* -------------------------------------------------------------------------- */

		iterator find(const key_type& k) { return (this->_tree.find(k)); }
		// const_iterator find(const key_type& k) const {}

		size_type count(const key_type& k) const { return (this->_tree.find(k) != NULL ? 1 : 0); }

		// iterator lower_bound(const key_type& k) {}
		// const_iterator lower_bound(const key_type& k) const {}
		// iterator upper_bound(const key_type& k) {}
		// const_iterator upper_bound(const key_type& k) const {}

		// ft::pair<const_iterator, const_iterator> equal_range (const key_type& k) const {}
		// ft::pair<iterator, iterator> equal_range (const key_type& k) const {}

		/* -------------------------------------------------------------------------- */
		/*                                  ALLOCATOR                                 */
		/* -------------------------------------------------------------------------- */

		// allocator_type get_allocator() const {}

		/* -------------------------- END MEMBER FUNCTIONS -------------------------- */

		/* -------------------------------------------------------------------------- */

		/* -------------------------------------------------------------------------- */
		/*                                    OTHER                                   */
		/* -------------------------------------------------------------------------- */

		void comparePairs(value_type& p1, value_type& p2) {
			node n1(p1);
			node n2(p2);

			this->_tree.compareNodes(&n1, &n2);
		}

		void printMap() const { this->_tree.printTree(); }

}; // END CLASS MAP

} // END NAMESPACE FT

#endif