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


		int height(node_pointer curr) {
			if (curr == NULL)
				return 0;
			return curr->height;
		}


		node_pointer deleteNodeHelper(node_pointer curr, value_type key) {
			node_pointer p = NULL;
			int updatedBf = 0;

			// search the key
			while (curr && curr->data != key) {
				if (key < curr->data)
					curr = curr->left;
				else
					curr = curr->right;
			}
			if (curr == NULL) return (curr);

			// the key has been found, now delete it
			std::cout << "Found" << std::endl;
			p = curr->parent;
			if (p) {
				if (p->left == curr)
					++updatedBf;
				else if (p->right == curr)
					--updatedBf;
			}

			// case 3: has both children
			if (curr->left && curr->right) {
				node_pointer temp = minimum(curr->right);
				curr->data = temp->data;
				p = temp->parent;
				if (p) {
					if (p->left == temp)
						++updatedBf;
					else if (p->right == temp)
						--updatedBf;
				}
				delete temp;
				p->bf += updatedBf;
				if (updatedBf > 0)
					p->left = NULL;
				else
					p->right = NULL;
			}
			else {
				// case 1: curr is a leaf node
				if (curr->left == NULL && curr->right == NULL) {
					if (updatedBf)
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
				p->bf += updatedBf;
				if (updatedBf > 0)
					p->left = NULL;
				else
					p->right = NULL;
			}


			std::cout << "before rebalancing" << std::endl;
			this->printTree();
			std::cout << "----------" << std::endl;
			if (p)
				this->updateBalance(p);
			
			return (curr);
		}

		node_pointer deleteNode (value_type key) {
			node_pointer deletedNode = deleteNodeHelper(this->_root, key);
			return (deletedNode);
		}

	private:
		void prettyPrint(node_pointer curr, std::string indent, bool last) const {
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

				this->prettyPrint(curr->left, indent, false);
				this->prettyPrint(curr->right, indent, true);
			}
		}

		void print2D(node_pointer root, int space) const {
			// Base case
			if (root == NULL)
				return ;

			// Increase distance between levels
			space += COUNT;

			// Process right child first
			print2D(root->right, space);

			// Print current node after space
			// count
			std::cout << std::endl;
			for (int i = COUNT; i < space; i++)
				std::cout << " ";
			std::cout << root->data << " (BF: " << root->bf << ")" << std::endl;

			// Process left child
			print2D(root->left, space);
		}

	public:
		void printTree() const {
			this->print2D(this->_root, 0);
			// this->prettyPrint(this->_root, "", true);
		}
};

} // END NAMESPACE FT

#endif
