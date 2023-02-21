#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "Node.hpp"
#include "AVLTree.hpp"
#include "iterator_traits.hpp"

namespace ft {

template < typename T >
class TreeIterator {
	public:
		typedef ft::AVLTree<T>						tree_type;
		typedef typename tree_type::node			node;
		typedef typename tree_type::node_pointer	node_pointer;

		typedef bidirectional_iterator_tag	iterator_category;
		typedef T				value_type;
		typedef value_type*		pointer;
		typedef const pointer	const_pointer;
		typedef value_type&		reference;
		typedef const reference	const_reference;
		typedef std::ptrdiff_t	difference_type;
		typedef TreeIterator<const value_type>	const_iterator;

	private:
		node_pointer _ptr;

	public:
		// constructors and destructor + assigment operator overload
		TreeIterator(): _ptr(NULL) {}
		TreeIterator(const TreeIterator& other): _ptr(other._ptr) {}
		TreeIterator(node_pointer ptr): _ptr(ptr) {}
		~TreeIterator() {}

		TreeIterator& operator=(const TreeIterator& other) { if (this != &other) this->_ptr = other._ptr; return (*this); }

		// a == b
		// a != b
		template < class Iter1, class Iter2 >
		friend bool operator==(const TreeIterator<Iter1> lhs, const TreeIterator<Iter2> rhs) { return (lhs._ptr == rhs._ptr); }
		template < class Iter1, class Iter2 >
		friend bool operator!=(const TreeIterator<Iter1> lhs, const TreeIterator<Iter2> rhs) { return (lhs._ptr != rhs._ptr); }

		// *a
		// a->m
		pointer operator->() { return (this->_ptr); }
		const_pointer operator->() const { return (this->_ptr); }
		reference operator*() { return (*(this->_ptr)); }
		const_reference operator*() const { return (*(this->_ptr)); }

		// ++a
		// a++
		// *a++
		TreeIterator& operator++() { if (!this->_ptr) return (*this); return (TreeIterator(tree_type::successor(this->_ptr))); }
		TreeIterator& operator++(int) { TreeIterator tmp = *this; ++*this; return (tmp); }

		// --a
		// a--
		// *a--
		TreeIterator& operator--() { if (!this->_ptr) return (*this); return (TreeIterator(tree_type::predecessor(this->_ptr))); }
		TreeIterator& operator--(int) { TreeIterator tmp = *this; --*this; return (tmp); }

};

} // END NAMESPACE FT

#endif
