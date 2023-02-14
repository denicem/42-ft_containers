#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

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
		node_pointer minimum(node_pointer curr) {
			while (curr->left != NULL) {
				curr = curr->left;
			}
			return (curr);
		}

		node_pointer search(value_type& key) const {
			node_pointer curr = this->_root;
			while (curr && curr->data != key) {
				if (key < curr->data)
					curr = curr->left;
				else
					curr = curr->right;
			}
			return (curr);
		}

		node_pointer deleteNode (value_type key) {
			// node_pointer deletedNode = deleteNodeHelper(this->_root, key);

			(void) key;
			std::cout << "Delete function NOT IMPLEMENTED.... yet." << std::endl;
			return (NULL);

			// return (deletedNode);
		}

	private:
		void print2D(node_pointer curr, int space) const {
			// Base case
			if (curr == NULL)
				return ;

			// Increase distance between levels
			space += COUNT;

			// Process right child first
			print2D(curr->right, space);

			// Print current node after space
			// count
			std::cout << std::endl;
			for (int i = COUNT; i < space; i++)
				std::cout << " ";
			std::cout << curr->data << " (BF: " << getBalanceFactor(curr) << ", H: " << getHeight(curr) << ")" << std::endl;

			// Process left child
			print2D(curr->left, space);
		}

	public:
		void printTree() const {
			this->print2D(this->_root, 0);
		}
};

} // END NAMESPACE FT

#endif
