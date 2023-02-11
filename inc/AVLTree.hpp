#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "Node.hpp"

namespace ft {

template < typename T >
class AVLTree {
	public:
		/*
		** ----------------------- MEMBER TYPES -----------------------
		*/
		typedef T											value_type;
		typedef ft::Node<value_type>						node;
		typedef typename node::node_pointer				node_pointer;

	private:
		node_pointer _root;
	
	public:
		AVLTree(): _root(NULL) {}

		void insert(value_type key) {
			node_pointer curr = new node(key);
			this->_root = curr;
		}

		node_pointer getRoot() const { return (this->_root); }
};

} // END NAMESPACE FT

#endif
