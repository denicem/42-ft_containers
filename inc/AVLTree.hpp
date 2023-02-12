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
		typedef T											value_type;
		typedef ft::Node<value_type>						node;
		typedef typename node::node_pointer				node_pointer;

	private:
		node_pointer _root;
	
	public:
		AVLTree(): _root(NULL) {}

		node_pointer getRoot() const { return (this->_root); }

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

			// update the balance factor
			x->bf = x->bf - 1 - std::max(0, y->bf);
			y->bf = y->bf - 1 + std::min(0, x->bf);
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

			// update the balance factor
			x->bf = x->bf + 1 - std::min(0, y->bf);
			y->bf = y->bf + 1 + std::max(0, x->bf);
		}

		void rebalance(node_pointer curr) {
			if (curr->bf > 0) {
				if (curr->right->bf < 0) {
					std::cout << "right left rotate" << std::endl;
					rightRotate(curr->right);
					leftRotate(curr);
				} else {
					std::cout << "left rotate" << std::endl;
					leftRotate(curr);
				}
			} 
			else if (curr->bf < 0) {
				if (curr->left->bf > 0) {
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
			if (curr->bf < -1 || curr->bf > 1) {
				this->rebalance(curr);
				std::cout << "Rebalancing needed." << std::endl;
				return ;
			}
			if (curr->parent != NULL) {
				if (curr == curr->parent->left)
					curr->parent->bf -= 1;
				if (curr == curr->parent->right)
					curr->parent->bf += 1;
				if (curr->parent->bf != 0)
					this->updateBalance(curr->parent);
			}
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

		node_pointer deleteNodeHelper(node_pointer curr, value_type key) {
			node_pointer p;
			// search the key
			if (curr == NULL) return (curr);
			else if (key < curr->data) curr->left = deleteNodeHelper(curr->left, key);
			else if (key > curr->data) curr->right = deleteNodeHelper(curr->right, key);
			else {
				// the key has been found, now delete it
				p = curr->parent;
				// case 1: curr is a leaf node
				if (curr->left == NULL && curr->right == NULL) {
					delete curr;
					curr = NULL;
				}

				// case 2: curr has only one child
				else if (curr->left == NULL) {
					node_pointer temp = curr;
					curr = curr->right;
					delete temp;
				}

				else if (curr->right == NULL) {
					node_pointer temp = curr;
					curr = curr->left;
					delete temp;
				}

				// case 3: has both children
				else {
					node_pointer temp = minimum(curr->right);
					curr->data = temp->data;
					curr->right = deleteNodeHelper(curr->right, temp->data);
				}

			} 

			// Write the update balance logic here 
			// YOUR CODE HERE
			if (p)
				updateBalance(p);
			// updateBalance(curr);

			return (curr);
		}

		node_pointer deleteNodeHelper2(node_pointer curr, value_type key) {
			node_pointer p;

			if (curr == NULL)
				return NULL;
			else
				if (key > curr->data) {
					curr->right = deleteNodeHelper2(curr->right, key);
					if (curr->bf > 1) {
						if (curr->left->bf >= 0)
							rightRotate(curr);
						else {
							leftRotate(curr->left);
							rightRotate(curr);
						}
					}
				}
				else
					if (key < curr-> data) {
						curr->left = deleteNodeHelper2(curr->left, key);
						if (curr->bf < -1) {
							if (curr->right->bf <= 0)
								leftRotate(curr);
							else {
								rightRotate(curr->right);
								leftRotate(curr);
							}
						}
					}
					else {
						if (curr->right != NULL) {
							p = curr->right;

							while(p->left != NULL)
								p = p->left;

							curr->data = p->data;
							curr->right = deleteNodeHelper2(curr->right, p->data);

							if (curr->bf > 1) {
								if (curr->left->bf >= 0)
									rightRotate(curr);
								else {
									leftRotate(curr->left);
									rightRotate(curr);
								}
							}
						}
						else
							return (curr->left);
					}
			// curr->ht = height(curr);
			return (curr);
		}

		node_pointer deleteNode (value_type key) {
			node_pointer deletedNode = deleteNodeHelper(this->_root, key);
			// node_pointer deletedNode = deleteNodeHelper2(this->_root, key);
			return (deletedNode);
		}

		void printHelper(node_pointer curr, std::string indent, bool last) const {
			// print the tree structure on the screen
			if (curr != NULL) {
				std::cout << indent;
				if (last) {
					std::cout << "R----";
					indent += "     ";
				}
				else {
					std::cout << "L----";
					indent += "|    ";
				}
				std::cout << curr->data << "( BF = " << curr->bf <<")" << std::endl;

				this->printHelper(curr->left, indent, false);
				this->printHelper(curr->right, indent, true);
			}
		}

		void prettyPrint() const {
			this->printHelper(this->_root, "", true);
		}

		void print2DUtil(node_pointer root, int space) const {
			// Base case
			if (root == NULL)
				return ;

			// Increase distance between levels
			space += COUNT;

			// Process right child first
			print2DUtil(root->right, space);

			// Print current node after space
			// count
			std::cout << std::endl;
			for (int i = COUNT; i < space; i++)
				std::cout << " ";
			std::cout << root->data << "(bf: " << root->bf << ")" << std::endl;

			// Process left child
			print2DUtil(root->left, space);
		}

		// Wrapper over print2DUtil()
		void print2D() const {
			// Pass initial space count as 0
			print2DUtil(this->_root, 0);
		}
};

} // END NAMESPACE FT

#endif
