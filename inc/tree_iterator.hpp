#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "Node.hpp"
#include "AVLTree.hpp"
#include "iterator_traits.hpp"

namespace ft {

template < typename Tree, typename T >
class TreeIterator {
	public:
		typedef bidirectional_iterator_tag	iterator_category;
		typedef T				value_type;
		typedef value_type*		pointer;
		// typedef const pointer	const_pointer;
		typedef value_type&		reference;
		// typedef const value_type&	const_reference;
		typedef std::ptrdiff_t	difference_type;
		// typedef TreeIterator<Tree, value_type> iterator;
		// typedef TreeIterator<Tree, const value_type> const_iterator;

		typedef Tree		tree_type;
		typedef ft::Node<value_type> node;
		typedef typename node::node_pointer node_pointer;

	private:
		node_pointer _ptr;

	public:
		// constructors and destructor + assigment operator overload
		TreeIterator(): _ptr(NULL) {}
		TreeIterator(node_pointer ptr): _ptr(ptr) {}
		TreeIterator(const TreeIterator& other): _ptr(other._ptr) {}
		~TreeIterator() {}

		TreeIterator& operator=(const TreeIterator& other) { if (this != &other) this->_ptr = other._ptr; return (*this); }

		operator TreeIterator< Tree, const value_type>() const { return TreeIterator< Tree, const value_type>(reinterpret_cast< ft::Node<const value_type>* >(_ptr)); }

		friend bool operator==(const TreeIterator lhs, const TreeIterator rhs) { return (lhs._ptr == rhs._ptr); }
		friend bool operator!=(const TreeIterator lhs, const TreeIterator rhs) { return (lhs._ptr != rhs._ptr); }

		reference operator*() { return ((this->_ptr)->data); }
		// const_reference operator*() const { return ((this->_ptr)->data); }
		pointer operator->() { return (&(operator*())); }
		// const_pointer operator->() const { return (&(operator*())); }

		TreeIterator& operator++() {
			if (this->_ptr)
				_ptr = successor(_ptr);
			return (*this);
		}
		TreeIterator operator++(int) {
			TreeIterator tmp = *this;
			++this;
			return (tmp);
		}

		TreeIterator& operator--() {
			if (this->_ptr)
				_ptr = predecessor(_ptr);
			return (*this);
		}
		TreeIterator operator--(int) {
			TreeIterator tmp = *this;
			--this;
			return (tmp);
		}
};

} // END NAMESPACE FT

#endif
