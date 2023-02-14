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
	// avl_int.printTree();
	// std::cout << std::endl;

	// pre inserting 2
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
	// avl_int.printTree();
	// std::cout << std::endl;

	// pre inserting 3
	avl_int.insert(1);
	avl_int.insert(2);
	avl_int.insert(3);
	// avl_int.insert(4);
	// avl_int.insert(5);
	avl_int.printTree();

	std::string action;

	std::cout << LIGHTGREEN << "> " << RESET;
	while (std::cin >> action && action != "e") {
		if (action == "h") {
			std::cout << LIGHTBLUE << "Actions: (i)nsert, (d)elete, (h)elp, (e)xit" << RESET << std::endl;
			std::cout << LIGHTGREEN << "\n> " << RESET;
			continue ;
		}
		if (action != "i" && action != "d" && action != "s"){
			std::cout << LIGHTRED << "Please try again!" << RESET << std::endl;
			std::cout << LIGHTGREEN << "\n> " << RESET;
			continue ;
		}

		std::cout << LIGHTGREEN << "> " << RESET;
		int val;
		std::cin >> val;
		std::cout << std::endl;
		if (action == "i") avl_int.insert(val);
		else if (action == "d") avl_int.deleteNode(val);
		else std::cout << LIGHTBLUE << "Search action not implemented... yet." << RESET << std::endl;
		avl_int.printTree();
		std::cout << LIGHTGREEN << "\n> " << RESET;
	}
	std::cout << LIGHTMAGENTA << "exit Interactive Mode" << RESET << std::endl;
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
