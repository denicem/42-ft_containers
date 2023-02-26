/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:27:59 by dmontema          #+#    #+#             */
/*   Updated: 2023/02/26 16:54:27 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <stack>
#include <map>

#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "utility.hpp"

#include "Node.hpp"
#include "AVLTree.hpp"

#include <iostream>

#include "Vect3.hpp"

#include "test_general.hpp"
#include "test_vector.hpp"
#include "test_avltree.hpp"
#include "test_map.hpp"

#define ELEMENTS 1000

void testStdMap() {
	std::map<int, char> intchar;
	for (int i = 0; i < ELEMENTS; ++i)
		intchar[i] = 97 + (i % 26);
}

void testFtMap() {
	ft::map<int, char> intchar;
	for (int i = 0; i < ELEMENTS; ++i)
		intchar[i] = 97 + (i % 26);
}

void testStdVector() {
	std::vector<int> nbrs;
	for (int i = 0; i < ELEMENTS; ++i)
		nbrs.push_back(97 + (i % 26));
}

void testFtVector() {
	ft::vector<int> nbrs;
	for (int i = 0; i < ELEMENTS; ++i)
		nbrs.push_back(97 + (i % 26));
}

int main() {
	std::cout << "Hello ft_containers." << std::endl << std::endl;

	// vectorTestConstructors();
	// vectorTestPushBack();
	// vectorTestAssign();
	// vectorTestSwap();
	// vectorTestInsert();
	// vectorTestResize();
	// vectorTestErase();

	// test_vector_playground();
	// test_avltree_playground();
	// test_interactive();
	// test_pair_playground();
	// test_map_playground();
	// system("leaks ft_containers");

	measureTime(&testStdMap, &testFtMap);
	measureTime(&testStdVector, &testFtVector);

	return (0);
}
