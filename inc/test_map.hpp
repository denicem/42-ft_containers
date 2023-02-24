#ifndef TEST_MAP_HPP
#define TEST_MAP_HPP

#include <map>
#include "map.hpp"

#include "test_general.hpp"

#include <iostream>


void test_map_playground() {

	ft::map<int, std::string> m;

	ft::pair<int, std::string> p1(4, "HN");
	ft::pair<int, std::string> p2(2, "NH");
	ft::pair<int, std::string> p3(7, "DNC");
	ft::pair<int, std::string> p4(9, "Romyyy");
	ft::pair<int, std::string> p5(13, "Chrisss");
	ft::pair<int, std::string> p6(15, "Neff");
	ft::pair<int, std::string> p7(5, "Fabibi");
	ft::pair<int, std::string> p8(20, "Flooo");
	ft::pair<int, std::string> p9(-2, "Mooo");
	m.insert(p1);
	m.insert(p5);
	m.insert(p3);
	m.insert(p2);
	m.insert(p4);
	m.insert(p9);
	m.insert(p7);
	m.insert(p6);
	m.insert(p8);
	std::cout << "Map size: " << m.size() << std::endl;
	m.printMap();
	// ft::map<int, std::string>::const_iterator it = m.begin();
	// ft::map<int, std::string>::const_iterator ite = m.end();
	// for (; it != ite; ++it) {
	// 	std::cout << *it << std::endl;
	// }
	// ft::map<int, std::string>::reverse_iterator rit = m.rbegin();
	// ft::map<int, std::string>::reverse_iterator rite = m.rend();
	// for (; rit != rite; ++rit) {
	// 	std::cout << *rit << std::endl;
	// }

	// testing erase
	// m.erase(m.begin());
	// m.erase(m.find(7));
	// m.erase(1);
	// m.erase(-2);
	// ft::map<int, std::string>::iterator e_it = m.begin();
	// ft::map<int, std::string>::iterator e_ite = m.end();
	// ++e_it;
	// ++e_it;
	// ++e_it;
	// --e_ite;
	// --e_ite;
	// m.erase(e_it, e_ite);
	// std::cout << "\n\n----\n\n";
	// std::cout << "Map size: " << m.size() << std::endl;
	// m.printMap();

	// testing clear()
	m.clear();
	std::cout << "\n\n----\n";
	std::cout << "Map size: " << m.size() << std::endl;
	m.printMap();
	std::cout << "----\n\n";



	// ft::map<int, std::string> m_cpy(m);
	// std::cout << "Map copy size: " << m_cpy.size() << std::endl;
	// m_cpy.printMap();

	// ft::map<int, std::string>::const_iterator first = m.begin();
	// ft::map<int, std::string>::const_iterator last = m.end();
	// ++first;
	// ++first;
	// --last;
	// --last;
	// --last;
	// ft::map<int, std::string> m_range(first, last);
	// std::cout << "Map range size: " << m_range.size() << std::endl;
	// m_range.printMap();

	// ft::map<int, std::string> m_assign = m;
	// std::cout << "Map assign size: " << m_assign.size() << std::endl;
	// m_assign.printMap();

	// ft::map<int, std::string>::const_iterator first = m.begin();
	// ft::map<int, std::string>::const_iterator last = m.end();
	// ft::map<int, std::string> m_insert_range;
	// m_insert_range.insert(first, last);
	// std::cout << "Map insert_range size: " << m_insert_range.size() << std::endl;
	// m_insert_range.printMap();
	
}

void test_pair_playground() {
	// ft::pair<std::string, int> pr = ft::make_pair(std::string("Hello"), 42);
	// ft::pair<std::string, int> pr = ft::make_pair("Hello", 42); // NOTE: this works in the std:: version why?
	// ft::pair<std::string, int> pr = ft::make_pair(std::string("Hello"), 42);
	// std::cout << pr.first << ": " << pr.second << std::endl;
}

#endif









// struct cmpByStringLength {
//     bool operator()(const std::string& a, const std::string& b) const {
//         return a.length() < b.length();
//     }
// };

// ft::map<std::string, std::string, cmpByStringLength> m_str;
// ft::pair<const std::string, std::string> str_p1("E", "BBBBB");
// ft::pair<const std::string, std::string> str_p2("DD", "BBBB");
// ft::pair<const std::string, std::string> str_p3("CCC", "BBB");
// ft::pair<const std::string, std::string> str_p4("BBBB", "BB");
// ft::pair<const std::string, std::string> str_p5("AAAAA", "B");
// m_str.insert(str_p1);
// m_str.insert(str_p2);
// m_str.insert(str_p3);
// m_str.insert(str_p4);
// m_str.insert(str_p5);
// ft::map<std::string, std::string, cmpByStringLength>::iterator it = m_str.begin();
// ft::map<std::string, std::string, cmpByStringLength>::iterator ite = m_str.end();

// for (; it != ite; ++it)
// 	std::cout << (*it).first << ": " << (*it).second << std::endl;