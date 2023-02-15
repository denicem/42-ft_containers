#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "test_general.hpp"
#include "Node.hpp"

#define COUNT 10

#include <iostream>
#include <algorithm>

namespace ft {

template < typename T >
class AVLTree {
	public:
		/*
		** ----------------------- MEMBER TYPES -----------------------
		*/
		typedef T							value_type;
		typedef ft::Node<value_type>		node;
		typedef typename node::node_pointer	node_pointer;

	private:
		node_pointer _root;
	
	public:
		AVLTree(): _root(NULL) {}

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
					std::cout << "right left rotate" << std::endl;
					rightRotate(curr->right);
					leftRotate(curr);
				} else {
					std::cout << "left rotate" << std::endl;
					leftRotate(curr);
				}
			} 
			else if (getBalanceFactor(curr) < 0) {
				if (getBalanceFactor(curr->left) > 0) {
					std::cout << "left right rotate" << std::endl;
					leftRotate(curr->left);
					rightRotate(curr);
				} else {
					std::cout << "right rotate" << std::endl;
					rightRotate(curr);
				}
			}
		}

		void updateBalance(node_pointer curr) {
			if (getBalanceFactor(curr) < -1 || getBalanceFactor(curr) > 1) {
				std::cout << "Rebalancing needed." << std::endl;
				this->rebalance(curr);
			}
			if (curr->parent != NULL)
				updateBalance(curr->parent);
		}

		void insert(value_type key) {
			// PART 1: Ordinary BST insert
			node_pointer curr = new node(key);

			node_pointer y = NULL;
			node_pointer x = this->_root;

			while (x != NULL) {
				y = x;
				if (curr->data < x->data)
					x = x->left;
				else
					x = x->right;
			}

			// y is parent of x
			curr->parent = y;
			if (y == NULL)
				this->_root = curr;
			else if (curr->data < y->data)
				y->left = curr;
			else
				y->right = curr;

			// PART 2: re-balance the node if necessary
			this->updateBalance(curr);
		}

		// find the node with the minimum key
		node_pointer min_node(node_pointer curr) {
			while (curr->left != NULL) {
				curr = curr->left;
			}
			return (curr);
		}

		// find the node with the maximum key
		node_pointer max_node(node_pointer curr) {
			while (curr->right != NULL) {
				curr = curr->right;
			}
			return (curr);
		}

		node_pointer successor(node_pointer x) {
			// if the right subtree is not null,
			// the successor is the leftmost node in the
			// right subtree
			if (x->right != NULL) {
				return (min_node(x->right));
			}

			// else it is the lowest ancestor of x whose
			// left child is also an ancestor of x.
			node_pointer y = x->parent;
			while (y != NULL && x == y->right) {
				x = y;
				y = y->parent;
			}

			return (y);
		}

		// find the predecessor of a given node
		node_pointer predecessor(node_pointer x) {
			// if the left subtree is not null,
			// the predecessor is the rightmost node in the 
			// left subtree
			if (x->left != NULL) {
				return (max_node(x->left));
			}

			node_pointer y = x->parent;
			while (y != NULL && x == y->left) {
				x = y;
				y = y->parent;
			}

			return (y);
		}

		node_pointer searchHelper(node_pointer curr, value_type& key) const {
			while (curr && curr->data != key) {
				if (key < curr->data)
					curr = curr->left;
				else
					curr = curr->right;
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

		node_pointer deleteNodeHelper(node_pointer curr, value_type key) {
			curr = searchHelper(curr, key);
			if (!curr) return (NULL);

			node_pointer prev = curr->parent;

			// case 1: leaf node
			if (!curr->left && !curr->right) {
				if (prev) {
					removeChild(prev, curr);
				}
				else 
					this->_root = NULL;
			}
			
			// case 2: node has one child
			else if (!curr->right) {
				node_pointer tmp = curr->left;
				curr->data = tmp->data;
				curr->left = NULL;
				curr = tmp;
			}
			else if (!curr->left) {
				node_pointer tmp = curr->right;
				curr->data = tmp->data;
				curr->right = NULL;
				curr = tmp;
			}

			// case 3: node has two children
			else {
				node_pointer tmp = min_node(curr->right);
				curr->data = tmp->data;
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
				delete deletedNode;
			}
			else
				std::cout << "Key not found." << std::endl;
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
};

} // END NAMESPACE FT

#endif
