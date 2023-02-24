#ifndef NODE_HPP
#define NODE_HPP

namespace ft {

template < typename T >
struct Node {
	typedef T					value_type;
	typedef value_type*			pointer;
	typedef Node<value_type>*	node_pointer;
	typedef Node<const value_type>*	const_node_pointer;

	value_type data;
	node_pointer parent;
	node_pointer left;
	node_pointer right;
	node_pointer _null;

	Node(const value_type& data = value_type()): data(data), parent(NULL), left(NULL), right(NULL) {}
	Node(const Node<value_type>& other): data(other.data), parent(other.parent), left(other.left), right(other.right) {}
	~Node() {}

	Node& operator=(const Node& other) {
		if (this != &other) {
			this->data = other.data;
			this->parent = other.parent;
			this->left = other.left;
			this->right = other.right;
		}
		return (*this);
	}
};

// find the node with the minimum key
template < class NodePointer >
NodePointer min_node(NodePointer curr) {
	// while (curr->left != NULL) {
	while (curr->left != curr->_null) {
		curr = curr->left;
	}
	return (curr);
}

// find the node with the maximum key
template < class NodePointer >
NodePointer max_node(NodePointer curr) {
	// while (curr->right != NULL) {
	while (curr->right != curr->_null) {
		curr = curr->right;
	}
	return (curr);
}

// find the predecessor of a given node
template < class NodePointer >
NodePointer predecessor(NodePointer x) {
	// if the left subtree is not null,
	// the predecessor is the rightmost node in the 
	// left subtree
	// if (x->left != NULL) {
	if (x->left != x->_null) {
		return (max_node(x->left));
	}

	NodePointer y = x->parent;
	// while (y != NULL && x == y->left) {
	while (y != y->_null && x == y->left) {
		x = y;
		y = y->parent;
	}

	return (y);
}

// find the successor of a given node
template < class NodePointer >
NodePointer successor(NodePointer x) {
	// if the right subtree is not null,
	// the successor is the leftmost node in the
	// right subtree
	// if (x->right != NULL) {
	if (x->right != x->_null) {
		return (min_node(x->right));
	}

	// else it is the lowest ancestor of x whose
	// left child is also an ancestor of x.
	NodePointer y = x->parent;
	// while (y != NULL && x == y->right) {
	while (y != y->_null && x == y->right) {
		x = y;
		y = y->parent;
	}

	return (y);
}

} // END NAMESPACE FT

#endif
