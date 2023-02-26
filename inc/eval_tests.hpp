#define ELEMENTS 100

#include "Vect3.hpp"
#include "test_general.hpp"

#include <iostream>

#include "stl_mode.hpp"

void test_case() {
	ft::vector<int> int_v;
	for (int i = 0; i < ELEMENTS; ++i) {
		int_v.push_back(rand() % 1000);
	}
	std::cout << "Int vector size: " << int_v.size() << std::endl;
	ft::vector<int>::iterator it = int_v.begin();
	ft::vector<int>::iterator ite = int_v.end();
	for (; it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	int_v.clear();
	std::cout << "Int vector size after clear: " << int_v.size() << std::endl;

}

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