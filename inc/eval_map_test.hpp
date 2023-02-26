#ifndef EVAL_MAP_TEST_HPP
#define EVAL_MAP_TEST_HPP

#include "stl_mode.hpp"
#include "test_general.hpp"
#include "Vect3.hpp"

#ifndef ELEMENTS
#define ELEMENTS 10000
#endif

#include <iostream>

void test_map() {
	ft::map<int, char> intchar;

	for (int i = 0; i < ELEMENTS; ++i)
		intchar[i] = 97 + (i % 26);
	std::cout << "Map intchar size: " << intchar.size() << std::endl;
	
	ft::map<int, char>::iterator ic_it = intchar.begin();
	ft::map<int, char>::iterator ic_ite = intchar.begin();
	std::advance(ic_ite, 1);
	intchar.erase(ic_it, ic_ite);
	std::cout << "^Map intchar size: " << intchar.size() << std::endl;

	ic_it = intchar.begin();
	ic_ite = intchar.begin();
	std::advance(ic_it, 24);
	std::advance(ic_ite, 30);
	intchar.erase(ic_it, ic_ite);
	std::cout << "^Map intchar size: " << intchar.size() << std::endl;
}

#endif
