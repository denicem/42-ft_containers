#ifndef EVAL_STACK_TEST_HPP
#define EVAL_STACK_TEST_HPP

#include "stl_mode.hpp"
#include "test_general.hpp"
#include "Vect3.hpp"

#ifndef ELEMENTS
#define ELEMENTS 10000
#endif

#include <iostream>

void test_stack() {
	std::cout << " -- BEGIN " << __func__ << " -- " << std::endl;

	ft::stack<int> int_s;
	
	for (ft::stack<int>::size_type i = 0; i < ELEMENTS; ++i)
		int_s.push(i);
	std::cout << "Size: " << int_s.size() << std::endl;
	std::cout << "Empty: " << int_s.empty() << std::endl;
	std::cout << "Top: " << int_s.size() << std::endl;

	for (ft::stack<int>::size_type i = 0; i < ELEMENTS; ++i)
		int_s.pop();
	std::cout << "Size: " << int_s.size() << std::endl;
	std::cout << "Empty: " << int_s.empty() << std::endl;

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

#endif
