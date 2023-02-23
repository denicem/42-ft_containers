#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "test_general.hpp"
#include "Node.hpp"
#include "tree_iterator.hpp"
#include "reverse_iterator.hpp"

#define COUNT 10

#include <iostream>
#include <algorithm>

namespace ft {

template <	typename T,
			class Compare = std::less<T>,
			class Alloc = std::allocator<T>
		 >
class AVLTree {
	public:
		/*
		** ----------------------- MEMBER TYPES -----------------------
		*/
		typedef T							value_type;
		typedef ft::Node<value_type>		node;
		typedef typename node::node_pointer	node_pointer;
		typedef typename node::const_node_pointer	const_node_pointer;

		typedef Compare						key_compare;
		typedef Alloc						allocator_type;
		typedef typename allocator_type::template rebind<node>::other	node_allocator_type;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename node_allocator_type::size_type	size_type;
		typedef typename node_allocator_type::difference_type	difference_type;

		typedef ft::TreeIterator<AVLTree, value_type> iterator;
		typedef ft::TreeIterator<AVLTree, const value_type> const_iterator;
		typedef ft::ReverseIterator<iterator> reverse_iterator;
		typedef ft::ReverseIterator<const_iterator> const_reverse_iterator;

	private:
		key_compare _comp;
		allocator_type _alloc;
		node_allocator_type _node_alloc;
		node_pointer _root;
		size_type _size;
	
	public:
		AVLTree(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type(),
				const node_allocator_type& node_alloc = node_allocator_type())
		: _comp(comp), _alloc(alloc), _node_alloc(node_alloc), _root(), _size(0) {}

		AVLTree(const AVLTree& other): _root(other._root) {} // NOTE: not sure about this yet!

		node_pointer getRoot() const { return (this->_root); }

		int getBalanceFactor(node_pointer curr) const {
			int rightHeight = curr ? getHeight(curr->right) : 0;
			int leftHeight = curr ? getHeight(curr->left) : 0;
			return (rightHeight - leftHeight);
		}

		int getHeight(node_pointer curr) const {
			if (curr == NULL)
				return (0);
			return ( 1 + std::max( getHeight(curr->right), getHeight(curr->left) ) );
		}

		void leftRotate(node_pointer x) {
			node_pointer y = x->right;
			x->right = y->left;
			if (y->left != NULL) {
				y->left->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL) {
				this->_root = y;
			} else if (x == x->parent->left) {
				x->parent->left = y;
			} else {
				x->parent->right = y;
			}
			y->left = x;
			x->parent = y;
		} 

		void rightRotate(node_pointer x) {
			node_pointer y = x->left;
			x->left = y->right;
			if (y->right != NULL) {
				y->right->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL) {
				this->_root = y;
			} else if (x == x->parent->right) {
				x->parent->right = y;
			} else {
				x->parent->left = y;
			}
			y->right = x;
			x->parent = y;
		}

		void rebalance(node_pointer curr) {
			if (getBalanceFactor(curr) > 0) {
				if (getBalanceFactor(curr->right) < 0) {
					// std::cout << "right left rotate" << std::endl;
					rightRotate(curr->right);
					leftRotate(curr);
				} else {
					// std::cout << "left rotate" << std::endl;
					leftRotate(curr);
				}
			} 
			else if (getBalanceFactor(curr) < 0) {
				if (getBalanceFactor(curr->left) > 0) {
					// std::cout << "left right rotate" << std::endl;
					leftRotate(curr->left);
					rightRotate(curr);
				} else {
					// std::cout << "right rotate" << std::endl;
					rightRotate(curr);
				}
			}
		}

		void updateBalance(node_pointer curr) {
			if (getBalanceFactor(curr) < -1 || getBalanceFactor(curr) > 1) {
				// std::cout << "Rebalancing needed." << std::endl;
				this->rebalance(curr);
			}
			if (curr->parent != NULL)
				updateBalance(curr->parent);
		}

		ft::pair<iterator, bool> insert(const value_type& key) {
			// PART 1: Ordinary BST insert
			node_pointer curr = this->search(key);
			if (curr)
				return (ft::pair<iterator, bool>(iterator(curr), false));
			curr = this->_node_alloc.allocate(1);
			this->_alloc.construct(&(curr->data), value_type(key));

			node_pointer y = NULL;
			node_pointer x = this->_root;

			while (x != NULL) {
				y = x;
				if (this->_comp(curr->data, x->data))
					x = x->left;
				else
					x = x->right;
			}

			// y is parent of x
			curr->parent = y;
			if (y == NULL)
				this->_root = curr;
			else if (this->_comp(curr->data, y->data))
				y->left = curr;
			else
				y->right = curr;

			// PART 2: re-balance the node if necessary
			++this->_size;
			this->updateBalance(curr);
			return (ft::pair<iterator, bool>(iterator(curr), true));
		}

		node_pointer searchHelper(node_pointer curr, value_type& key) const {
			while (curr) {
				if (this->_comp(key, curr->data))
					curr = curr->left;
				else if (this->_comp(curr->data, key))
					curr = curr->right;
				else
					break;
			}
			return (curr);
		}

		node_pointer search(value_type key) const {
			return (searchHelper(this->_root, key));
		}

		void removeChild(node_pointer& parent, node_pointer& child) {
			if (parent->left == child)
				parent->left = NULL;
			else if (parent->right == child)
				parent->right = NULL;
		}

		void destroyNode(node_pointer curr) {
			if (curr) {
				this->_alloc.destroy(&(curr->data));
				this->_node_alloc.deallocate(curr, 1);
			}
		}

		void copyData(node_pointer dest, node_pointer src) {
			this->_alloc.destroy(&(dest->data));
			this->_alloc.construct(&(dest->data), value_type(src->data));
		}

		node_pointer deleteNodeHelper(node_pointer curr, value_type key) {
			curr = searchHelper(curr, key);
			if (!curr) return (NULL);

			node_pointer prev = curr->parent;

			// case 1: leaf node
			if (!curr->left && !curr->right) {
				std::cout << "case 1" << std::endl;
				if (prev)
					removeChild(prev, curr);
				else 
					this->_root = NULL;
			}
			
			// case 2: node has one child
			else if (!curr->right) {
				std::cout << "case 2: left child" << std::endl;
				node_pointer tmp = curr->left;
				copyData(curr, tmp);
				curr->left = NULL;
				curr = tmp;
			}
			else if (!curr->left) {
				std::cout << "case 2: right child" << std::endl;
				node_pointer tmp = curr->right;
				copyData(curr, tmp);
				curr->right = NULL;
				curr = tmp;
			}

			// case 3: node has two children
			else {
				std::cout << "case 3" << std::endl;
				node_pointer tmp = min_node(curr->right);
				copyData(curr, tmp);
				curr = deleteNodeHelper(curr->right, curr->data);
			}

			return (curr);
		}

		void deleteNode (value_type key) {
			node_pointer deletedNode = deleteNodeHelper(this->_root, key);
			if (deletedNode) {
				if (deletedNode->parent)
					updateBalance(deletedNode->parent);
				else if (this->_root)
					updateBalance(this->_root);
				this->destroyNode(deletedNode);
				--this->_size;
			}
			else
				std::cout << "Key not found." << std::endl;
		}

		void clearHelper(node_pointer curr) {
			if (!curr)
				return ;
			clearHelper(curr->right);
			clearHelper(curr->left);
			destroyNode(curr);
		}

		void clear() {
			clearHelper(this->_root);
			this->_root = NULL;
		}

	private:
		std::string getColorStr(int color) const {
			switch(color) {
				case 0: return (LIGHTGREEN);
				case 1: return (LIGHTBLUE);
				case 2: return (LIGHTYELLOW);
				case 3: return (LIGHTMAGENTA);
				case 4: return (LIGHTCYAN);
				default: return ("");
			}
		}

		void print2D(node_pointer curr, int space, std::string dir, int color = 0) const {
			// Base case
			if (curr == NULL)
				return ;

			// Increase distance between levels
			space += COUNT;

			// Process right child first
			print2D(curr->right, space, "v ", (color + 1) % 5);

			// Print current node after space
			// count
			std::cout << std::endl;
			for (int i = COUNT; i < space; i++)
				std::cout << " ";
			std::cout << getColorStr(color) << dir << curr->data << " (BF: " << getBalanceFactor(curr) << ", H: " << getHeight(curr) << ") " << RESET << std::endl;

			// Process left child
			print2D(curr->left, space, "^ ", (color + 1) % 5);
		}

	public:
		void printTree() const {
			this->print2D(this->_root, 0, "");
		}

		void compareNodes(node_pointer n1, node_pointer n2) {
			if (_comp.operator()(n1->data, n2->data))
				std::cout << "n1 < n2";
			else
				std::cout << "n1 > n2";
			std::cout << std::endl;
		}

	public:
		size_type size() const { return (this->_size); }
		bool empty() const { return (!this->_size); }

	public:
		iterator begin() { return ( this->empty() ? this->end() : iterator(min_node(this->_root)) ); }
		const_iterator begin() const { return ( this->empty() ? this->end() : const_iterator(min_node(this->_root)) ); }
		iterator end() { if (this->empty()) return (NULL); return ( iterator(max_node(this->_root)->right) ); } // TODO: find better solution for protection
		const_iterator end() const { if (this->empty()) return (NULL); return ( const_iterator(max_node(this->_root)->right) ); }

		reverse_iterator rbegin() { return (reverse_iterator(end())); }
		const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); }
		reverse_iterator rend() { return (reverse_iterator(begin())); }
		const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); }

		template < typename Key >
		iterator find(Key key) {
			node_pointer curr = this->_root;
				while (curr) {
				if (this->_comp(key, curr->data))
					curr = curr->left;
				else if (this->_comp(curr->data, key))
					curr = curr->right;
				else
					break;
			}
			return (iterator(curr));
		}
};

} // END NAMESPACE FT

#endif
