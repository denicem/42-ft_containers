#ifndef TEST_AVLTREE_HPP
#define TEST_AVLTREE_HPP

#include "Node.hpp"
#include "AVLTree.hpp"
#include "utility.hpp"

#include "test_general.hpp"

#include <iostream>
#include <string>

void test_avltree_playground() {
	// ft::AVLTree<int> avl_int;
	// avl_int.insert(50);
	// avl_int.insert(30);
	// avl_int.insert(70);
	// avl_int.insert(23);
	// avl_int.insert(42);
	// avl_int.insert(17);
	// avl_int.insert(35);
	// avl_int.insert(33);
	// avl_int.insert(37);
	// avl_int.insert(48);
	// avl_int.insert(90);
	// avl_int.printTree();

	// std::cout << "MIN: " << avl_int.min_node(avl_int.getRoot())->data << std::endl;
	// std::cout << "MAX: " << avl_int.max_node(avl_int.getRoot())->data << std::endl;
	// std::cout << "PRE - 37: " << avl_int.predecessor(avl_int.search(37))->data << std::endl;
	// std::cout << "SUC - 37: " << avl_int.successor(avl_int.search(37))->data << std::endl;

	// test_interactive();

	// ft::AVLTree<int>::node n1(20);
	// ft::AVLTree<int>::node n2(15);

	// avl_int.compareNodes(&n1, &n2);
}

void pre_insert_interactive(ft::AVLTree<int>& avl_int) {
	// pre inserting
	avl_int.insert(40);
	avl_int.insert(45);
	avl_int.insert(50);
	avl_int.insert(49);
	avl_int.insert(47);

	// // pre inserting 2
	// avl_int.insert(58);
	// avl_int.insert(46);
	// avl_int.insert(43);
	// avl_int.insert(634);
	// avl_int.insert(11);
	// avl_int.insert(10);
	// avl_int.insert(55);
	// avl_int.insert(50);
	// avl_int.insert(66);
	// avl_int.insert(14);

	// // pre inserting 3
	// avl_int.insert(1);
	// avl_int.insert(2);
	// avl_int.insert(3);
	// avl_int.insert(4);
	// avl_int.insert(5);
	// avl_int.insert(10);

	// display tree if pre inserting values
	avl_int.printTree();
	std::cout << std::endl;
}

void test_interactive() {
	std::cout << LIGHTMAGENTA << " <<< Interactive Mode >>> " << RESET << std::endl;
	std::cout << LIGHTBLUE << "Select action to perform followed by a whitespace and then an int value." << std::endl;
	std::cout << "Actions: (i)nsert, (d)elete, (h)elp, (q)uit" << RESET << std::endl;
	std::cout << std::endl;

	ft::AVLTree<int> avl_int;
	pre_insert_interactive(avl_int);

	std::string action;
	std::cout << std::endl << LIGHTGRAY << "---" << RESET << std::endl;
	std::cout << BOLD << LIGHTGREEN << "> " << RESET;
	while (std::cin >> action && action != "q") {
		if (action == "h") {
			std::cout << LIGHTGRAY << "---" << RESET << std::endl;
			std::cout << LIGHTBLUE << "Actions: (i)nsert, (d)elete, (s)earch, (h)elp, (q)uit" << RESET << std::endl;
			std::cout << LIGHTGRAY << "---" << RESET << std::endl;
			std::cout << BOLD << LIGHTGREEN << "> " << RESET;
			continue ;
		}
		if (action != "i" && action != "d" && action != "s"){
			std::cout << LIGHTGRAY << "---" << RESET << std::endl;
			std::cout << LIGHTRED << "Invalid argument. Please try again!" << RESET << std::endl;
			std::cout<< LIGHTGRAY << "---" << RESET << std::endl;
			std::cout << BOLD << LIGHTGREEN << "> " << RESET;
			continue ;
		}
		std::cout << LIGHTGREEN << "> " << RESET;
		int val;
		std::cin >> val;
		std::cout << std::endl << LIGHTGRAY << "---" << RESET << std::endl;
		if (action == "i") {
			std::cout << LIGHTBLUE << "inserting " << val << " ..." << RESET << std::endl;
			avl_int.insert(val);
		}
		else if (action == "d") {
			std::cout << LIGHTBLUE << "deleting " << val << " ..." << RESET << std::endl;
			avl_int.deleteNode(val);
		}
		else {
			ft::AVLTree<int>::node_pointer ptr = avl_int.search(val);
			std::cout << LIGHTBLUE << "searching " << val << " ...: " << RESET;
			if (ptr) std::cout << BOLD << LIGHTGREEN << "FOUND!" << std::endl;
			else std::cout << BOLD << LIGHTRED << "NOT FOUND!" << std::endl;
		}
		std::cout << LIGHTGRAY << "~" << RESET << std::endl;
		avl_int.printTree();
		std::cout << std::endl << LIGHTGRAY << "---" << RESET << std::endl;
		std::cout << BOLD << LIGHTGREEN << "> " << RESET;
	}
	std::cout << LIGHTGRAY << "---" << RESET << std::endl;
	std::cout << LIGHTMAGENTA << "exit Interactive Mode" << RESET << std::endl << std::endl;
}

#endif
