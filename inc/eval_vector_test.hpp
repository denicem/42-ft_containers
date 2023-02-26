#ifndef EVAL_VECTOR_TEST_HPP
#define EVAL_VECTOR_TEST_HPP

#include "stl_mode.hpp"
#include "test_general.hpp"
#include "Vect3.hpp"

#ifndef ELEMENTS
#define ELEMENTS 10000
#endif

#include <iostream>

void test_vector_default_ctor() {
	std::cout << " -- " << __func__ << " -- " << std::endl;

	ft::vector<int> int_v;
	std::cout << "Int vector size: " << int_v.size() << std::endl;

	for (int i = 0; i < ELEMENTS; ++i)
		int_v.push_back(rand() % 1000);
	std::cout << "Int vector size after push_back()s: " << int_v.size() << std::endl;

	std::cout << "Printing elements with const_iterator: " << std::endl;
	ft::vector<int>::const_iterator it = int_v.begin();
	ft::vector<int>::const_iterator ite = int_v.end();
	for (; it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Printing elements with const_reverse_iterator: " << std::endl;
	ft::vector<int>::const_reverse_iterator rit = int_v.rbegin();
	ft::vector<int>::const_reverse_iterator rite = int_v.rend();
	for (; rit != rite; ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;

	for (int i = 0; i < ELEMENTS && !int_v.empty(); ++i)
		int_v.pop_back();
	std::cout << "Int vector size after pop_back()s: " << int_v.size() << std::endl;
	std::cout << "Empty: " << int_v.empty() << std::endl;

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

void test_vector_fill_ctor() {
	std::cout << " -- " << __func__ << " -- " << std::endl;

	ft::vector<int> int_v(ELEMENTS, 42);
	std::cout << "Int vector size: " << int_v.size() << std::endl;

	for (int i = 0; i < ELEMENTS / 2; ++i)
		int_v.push_back(rand() % 1000);
	std::cout << "Int vector size after push_back()s: " << int_v.size() << std::endl;

	std::cout << "Printing elements with const_iterator: " << std::endl;
	ft::vector<int>::const_iterator it = int_v.begin();
	ft::vector<int>::const_iterator ite = int_v.end();
	for (; it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	for (int i = 0; i < ELEMENTS && !int_v.empty(); ++i)
		int_v.pop_back();
	std::cout << "Int vector size after pop_back()s: " << int_v.size() << std::endl;
	std::cout << "Empty: " << int_v.empty() << std::endl;

	int_v.clear();
	std::cout << "Int vector size after clear(): " << int_v.size() << std::endl;
	std::cout << "Empty: " << int_v.empty() << std::endl;

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

void test_vector_range_ctor() {
	std::cout << " -- " << __func__ << " -- " << std::endl;
	ft::vector<int> range_v;
	for (int i = 0; i < ELEMENTS / 2; ++i)
		range_v.push_back(rand() % 1000);
	ft::vector<int>::const_iterator range_it = range_v.begin();
	ft::vector<int>::const_iterator range_ite = range_v.end();

	ft::vector<int> int_v(range_it, range_ite);
	std::cout << "Int vector size: " << int_v.size() << std::endl;

	for (int i = 0; i < ELEMENTS / 2; ++i)
		int_v.push_back(rand() % 1000);
	std::cout << "Int vector size after push_back()s: " << int_v.size() << std::endl;

	std::cout << "Printing elements with const_iterator: " << std::endl;
	ft::vector<int>::const_iterator it = int_v.begin();
	ft::vector<int>::const_iterator ite = int_v.end();
	for (; it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	for (int i = 0; i < ELEMENTS && !int_v.empty(); ++i)
		int_v.pop_back();
	std::cout << "Int vector size after pop_back()s: " << int_v.size() << std::endl;
	std::cout << "Empty: " << int_v.empty() << std::endl;

	int_v.clear();
	std::cout << "Int vector size after clear(): " << int_v.size() << std::endl;
	std::cout << "Empty: " << int_v.empty() << std::endl;

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

void test_vector_copy_ctor() {
	std::cout << " -- " << __func__ << " -- " << std::endl;

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

#endif
