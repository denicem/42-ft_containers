#ifndef NODE_HPP
#define NODE_HPP

namespace ft {

template < typename T >
struct Node {
	typedef T					value_type;
	typedef value_type*			pointer;
	typedef Node<value_type>*	node_pointer;

	value_type data;
	node_pointer parent;
	node_pointer left;
	node_pointer right;

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

} // END NAMESPACE FT

#endif
