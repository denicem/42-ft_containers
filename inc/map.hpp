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
		typedef typename allocator_type::const_reference	reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		// typedef ft::MapIterator<value_type> 					iterator;
		// typedef ft::MapIterator<const value_type> 			const_iterator;
		// typedef ft::MapIterator<iterator> 					reverse_iterator;
		// typedef ft::MapIterator<const_iterator> 				const_reverse_iterator;
		// typedef typename iterator_traits<iterator>::difference_type	difference_type;
		// typedef typename iterator_traits<iterator>::size_type		size_type;
	
	/*
	** --------------------------- MEMBER VARIABLES ---------------------------
	*/
	private:
		allocator_type	_alloc;
		// size_type	_size;
		size_t		_size;
		ft::AVLTree	_tree;

	/*
	** ---------------------------- MEMBER FUNCTIONS ---------------------------
	** ----------------------- CONSTRUCTORS & DESTRUCTOR -----------------------
	*/
	public:
		// empty/default constructor
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(0), _tree() {}
		// range constructor
		// template <class InputIterator>  map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}
		// copy constructor
		// map (const map& x) {}

		// ~map() {}
};

} // END NAMESPACE FT

#endif
