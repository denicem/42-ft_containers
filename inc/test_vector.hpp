#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

#include <vector>
#include "vector.hpp"

#include <iostream>
#include "test_general.hpp"

void vector_test_basic_std() {
	std::vector<int> nbrs;

	nbrs.push_back(42);

	std::cout << nbrs[0] << std::endl;
}

void vector_test_basic_ft() {
	ft::vector<int> nbrs;

	nbrs.push_back(42);

	std::cout << nbrs[0] << std::endl;
}

#endif
