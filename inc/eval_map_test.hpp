#ifndef EVAL_MAP_TEST_HPP
#define EVAL_MAP_TEST_HPP

#include "stl_mode.hpp"
#include "test_general.hpp"
#include "Vect3.hpp"

#ifdef ELEMENTS
#undef ELEMENTS
#define ELEMENTS 100
#endif

#include <iostream>


void test_map_ctor() {
	std::cout << " -- BEGIN " << __func__ << " -- " << std::endl;

	// 	testing default constructor
	std::cout << "Testing default cosntructor:" << std::endl;
	ft::map<int, char> intchar;

	for (int i = 0; i < ELEMENTS; ++i)
		intchar[i] = 97 + (rand() % 26);

	std::cout << "Size: " << intchar.size() << std::endl;
	std::cout << "Empty: " << intchar.empty() << std::endl;
	std::cout << "Max size: " << intchar.max_size() << std::endl;

	ft::map<int, char>::iterator ic_it = intchar.begin();
	ft::map<int, char>::iterator ic_ite = intchar.end();
	std::cout << "Printing map elements:" << std::endl;
	for (; ic_it != ic_ite; ++ic_it)
		std::cout << "| K = " << ic_it->first << ", V = " << ic_it->second << " | ";
	std::cout << std::endl;
	std::cout << std::endl;

	// 	testing copy constructor
	std::cout << "Testing copy cosntructor:" << std::endl;
	ft::map<int, char> m_cpy(intchar);
	std::cout << "Map copy size: " << m_cpy.size() << std::endl;
	std::cout << std::endl;

	// testing range constructor
	std::cout << "Testing range cosntructor:" << std::endl;
	ft::map<int, char>::const_iterator first = intchar.begin();
	ft::map<int, char>::const_iterator last = intchar.begin();
	std::advance(first, ELEMENTS / 4);
	std::advance(last, (ELEMENTS / 2) + (ELEMENTS / 4));

	ft::map<int, char> m_range(first, last);
	std::cout << "Map range size: " << m_range.size() << std::endl;

	// testing range constructor
	std::cout << "Testing assignment operator:" << std::endl;
	ft::map<int, char> m_assign = intchar;
	std::cout << "Map assign size: " << m_assign.size() << std::endl;
	std::cout << std::endl;

	intchar.clear();
	m_cpy.clear();
	m_range.clear();
	m_assign.clear();
	std::cout << "Maps after clear(): " << std::endl;
	std::cout << "default map empty: " << intchar.empty() << std::endl;
	std::cout << "copy map empty: " << m_cpy.empty() << std::endl;
	std::cout << "range map empty: " << m_range.empty() << std::endl;
	std::cout << "assign map empty: " << m_assign.empty() << std::endl;

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

void test_map_insert() {
	std::cout << " -- BEGIN " << __func__ << " -- " << std::endl;

	ft::map<int, char> intchar;
	std::cout << "Size: " << intchar.size() << std::endl;

	for (int i = 0; i < ELEMENTS; ++i)
		intchar.insert(ft::make_pair(i,  97 + (rand() % 26)));
	
	std::cout << "Size after single element insert()s: " << intchar.size() << std::endl;

	ft::map<int, char> intchar2;
	std::cout << "Size map2: " << intchar2.size() << std::endl;
	intchar2.insert(intchar.begin(), intchar.end());
	std::cout << "Size map2 after range insert(): " << intchar.size() << std::endl;

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

void test_map_erase() {
	std::cout << " -- BEGIN " << __func__ << " -- " << std::endl;

	ft::map<int, char> intchar;

	for (int i = 0; i < ELEMENTS; ++i)
		intchar[i] = 97 + (i % 26);
	std::cout << "Map intchar size: " << intchar.size() << std::endl;
	
	intchar.erase(1);
	std::cout << "Map intchar size after erasing one element (with key): " << intchar.size() << std::endl;
	intchar.erase(intchar.begin());
	std::cout << "Map intchar size after erasing one element: " << intchar.size() << std::endl;

	ft::map<int, char>::iterator ic_it = intchar.begin();
	ft::map<int, char>::iterator ic_ite = intchar.begin();
	ic_it = intchar.begin();
	ic_ite = intchar.begin();
	std::advance(ic_it, 24);
	std::advance(ic_ite, 30);
	intchar.erase(ic_it, ic_ite);
	std::cout << "Map intchar size after erasing multiple elements: " << intchar.size() << std::endl;

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

void test_map_element_access_lookup() {
	std::cout << " -- BEGIN " << __func__ << " -- " << std::endl;

	ft::map<int, char> intchar;

	for (int i = 0; i < ELEMENTS; ++i)
		intchar[i] = 97 + (rand() % 26);

	std::cout << "operator[]() = " << intchar[0] << std::endl;
	std::cout << "at() = " << intchar.at(0) << std::endl;
	std::cout << "find() = ";
	if (intchar.find(1) == intchar.end())
		std::cout << "NOT FOUND" << std::endl;
	else 
		std::cout << "FOUND" << std::endl;
	std::cout << "wrong find() = ";
	if (intchar.find(ELEMENTS + 5) == intchar.end())
		std::cout << "NOT FOUND" << std::endl;
	else 
		std::cout << "FOUND" << std::endl;
	
	std::cout << "count() = " << intchar.count(0) << std::endl;
	std::cout << "wrong count() = " << intchar.count(ELEMENTS + 5) << std::endl;
	
	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

#endif
