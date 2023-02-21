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

	/*
	** ----------------------- MEMBER TYPES -----------------------
	*/
	public:
		// typedef Alloc													allocator_type;
		// typedef typename allocator_type::value_type::first_type			key_type; // NOTE: is that possible?
		// typedef typename allocator_type::value_type::second_type		mapped_type; // NOTE: is that possible?
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
		// typedef ft::MapIterator<value_type> 					iterator;
		// typedef ft::MapIterator<const value_type> 			const_iterator;
		// typedef ft::MapIterator<iterator> 					reverse_iterator;
		// typedef ft::MapIterator<const_iterator> 				const_reverse_iterator;
		// typedef typename iterator_traits<iterator>::difference_type	difference_type;
		// typedef typename iterator_traits<iterator>::size_type		size_type;
		typedef typename allocator_type::size_type size_type;

	
		/*
		** ----------------------- VALUE COMPARE -----------------------
		*/
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

		typedef typename tree_type::iterator		iterator;
		// typedef typename tree_type::const_iterator	const_iterator;

	/*
	** --------------------------- MEMBER VARIABLES ---------------------------
	*/
	private:
		tree_type	_tree;

	/*
	** ---------------------------- MEMBER FUNCTIONS ---------------------------
	** ----------------------- CONSTRUCTORS & DESTRUCTOR -----------------------
	*/
	public:
		// empty/default constructor
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(tree_type()) { (void) comp; (void) alloc; }
		// range constructor
		// template <class InputIterator>  map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}
		// copy constructor
		// map (const map& x) {}

		// map& operator=(const map& x) {}

		// ~map() {}

		size_type size() const { return (this->_tree.size()); }

		/* -------------------------------------------------------------------------- */
		/*                               ELEMENT ACCESS                               */
		/* -------------------------------------------------------------------------- */
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

		/* --------------------------------- INSERTS -------------------------------- */
		/* ----------------------------- SINGLE ELEMENT ----------------------------- */
		ft::pair<iterator, bool> insert(const value_type& val) {
			return (this->_tree.insert(val));
		}

		/* -------------------------------- WITH HINT ------------------------------- */
		iterator insert(iterator pos, const value_type& val) {
			(void) pos;
			ft::pair<iterator, bool> res = this->insert(val);
			return (res.first);
		}

		/* ---------------------------------- RANGE --------------------------------- */
		template < class InputIterator > // TODO: test if it works
		void insert(InputIterator first, InputIterator last) {
			for (; first != last; ++first)
				this->insert(*first);
		}
		/* -------------------------------------------------------------------------- */

		void comparePairs(value_type& p1, value_type& p2) {
			node n1(p1);
			node n2(p2);

			this->_tree.compareNodes(&n1, &n2);
		}

		void printMap() const { this->_tree.printTree(); }

	public:
		iterator begin() { return (this->_tree.begin()); }
		iterator end() { return (this->_tree.end()); }
};

} // END NAMESPACE FT

#endif
