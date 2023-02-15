#ifndef TEST_AVLTREE_HPP
#define TEST_AVLTREE_HPP

#include "Node.hpp"
#include "AVLTree.hpp"
#include "utility.hpp"

#include "test_general.hpp"

#include <iostream>
#include <string>

void test_interactive() {
	std::cout << LIGHTMAGENTA << " <<< Interactive Mode >>> " << RESET << std::endl;
	std::cout << LIGHTBLUE << "Select action to perform followed by a whitespace and then an int value." << std::endl;
	std::cout << "Actions: (i)nsert, (d)elete, (h)elp, (e)xit" << RESET << std::endl;
	std::cout << std::endl;

	ft::AVLTree<int> avl_int;

	// // pre inserting
	// avl_int.insert(40);
	// avl_int.insert(45);
	// avl_int.insert(50);
	// avl_int.insert(49);
	// avl_int.insert(47);

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

	// // display tree if pre inserting values
	// avl_int.printTree();
	// std::cout << std::endl;

	std::string action;
	std::cout << std::endl << LIGHTGRAY << "---" << RESET << std::endl;
	std::cout << BOLD << LIGHTGREEN << "> " << RESET;
	while (std::cin >> action && action != "q") {
		if (action == "h") {
			std::cout << LIGHTGRAY << "---" << RESET << std::endl;
			std::cout << LIGHTBLUE << "Actions: (i)nsert, (d)elete, (s)earch, (h)elp, (e)xit" << RESET << std::endl;
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

// old interactive mode:
// int input;
// while (std::cin >> input && input != 0) {
// 	char mode;

// 	std::cin >> mode;
// 	if (mode == 'i')
// 		avl_int.insert(input);
// 	if (mode == 'd')
// 	avl_int.deleteNode(input);
// 	avl_int.print2D();
// }

#endif
