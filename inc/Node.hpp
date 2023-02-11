#ifndef NODE_HPP
#define NODE_HPP

namespace ft {

template < typename T >
struct Node {
	typedef T							value_type;
	typedef value_type*		pointer;
	typedef Node<value_type>*	node_pointer;

	value_type data;
	node_pointer parent;
	node_pointer left;
	node_pointer right;
	int bf;

	Node(): data(value_type()), parent(NULL), left(NULL), right(NULL), bf(0) {}
	Node(const value_type& data): data(data), parent(NULL), left(NULL), right(NULL), bf(0) {}

};

} // END NAMESPACE FT


#endif
