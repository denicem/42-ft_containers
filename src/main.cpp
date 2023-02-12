/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:27:59 by dmontema          #+#    #+#             */
/*   Updated: 2023/02/11 23:15:26 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include "utility.hpp"

#include "Node.hpp"
#include "AVLTree.hpp"

#include <iostream>

#include "Vect3.hpp"

// #include "test_general.hpp"
// #include "test_vector.hpp"

int main() {
	std::cout << "Hello ft_containers." << std::endl << std::endl;

	// vectorTestConstructors();
	// vectorTestPushBack();
	// vectorTestAssign();
	// vectorTestSwap();
	// vectorTestInsert();
	// vectorTestResize();
	// vectorTestErase();

	// std::vector<int> v1(5, 42);
	// ft::vector<int> fv1(5, 42);
	// assert(v1.size() == fv1.size(), true);
	// assert(v1.size() != fv1.size(), true);
	// assert(v1.size() >= fv1.size(), true);
	// assert(v1.size() > fv1.size(), true);
	// assert(v1.size() <= fv1.size(), true);
	// assert(v1.size() < fv1.size(), true);
	// measureTime(&vector_test_basic_std, &vector_test_basic_ft);

	// ft::vector<int> v1 = createFtVectorInt(10);
	// ft::vector<int> v2 = createFtVectorInt(7);

	// print_container(v1, true);
	// print_container(v2, true);

	// std::cout << "\nv2 = v1\n" << std::endl;
	// v2 = v1;

	// print_container(v1, true);
	// print_container(v2, true);

	// ft::vector<int>::reverse_iterator rit = v1.rbegin();
	// std::cout << *rit << std::endl;


	// ft::vector<int> fv1;
	// std::vector<int> v2 = createStdVectorInt(5);
	// fv1.insert(fv1.begin(), 5, -1);
	// print_container(fv1, true);
	// fv1.insert(fv1.begin(), 5, 42);
	// print_container(fv1, true);

	
	// ft::pair<std::string, int> pr = ft::make_pair(std::string("Hello"), 42);
	// ft::pair<std::string, int> pr = ft::make_pair("Hello", 42); // NOTE: this works in the std:: version why?
	// ft::pair<std::string, int> pr = ft::make_pair(std::string("Hello"), 42);

	// std::cout << pr.first << ": " << pr.second << std::endl;

	ft::AVLTree<int> avl_int;
	// ft::AVLTree< ft::pair<std::string, int> > avl_pair;

	// avl_int.prettyPrint();
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

	// avl_pair.insert(ft::make_pair(std::string("Hello"), 42));
	// avl_pair.insert(ft::make_pair(std::string("Romyyy"), 42));
	// avl_pair.insert(ft::make_pair(std::string("DNC"), 42));

	// std::cout << avl_int.getRoot()->data << std::endl;
	// std::cout << avl_pair.getRoot()->data.first << ": " << avl_pair.getRoot()->data.second << std::endl;

	// avl_int.prettyPrint();
	// avl_int.print2D();
	// avl_pair.print2D();

	int input;
	while (std::cin >> input && input != 0) {
		avl_int.insert(input);
		avl_int.print2D();
	}

	return (0);
}
