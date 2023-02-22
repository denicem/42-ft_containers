#ifndef TEST_MAP_HPP
#define TEST_MAP_HPP

#include <map>
#include "map.hpp"

#include "test_general.hpp"

#include <iostream>

// struct cmpByStringLength {
//     bool operator()(const std::string& a, const std::string& b) const {
//         return a.length() < b.length();
//     }
// };

void test_map_playground() {
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

	ft::map<int, std::string> m;
	ft::pair<const int, std::string> p1(4, "HN");
	ft::pair<const int, std::string> p2(2, "NH");
	ft::pair<const int, std::string> p3(7, "DNC");
	ft::pair<const int, std::string> p4(9, "Romyyy");
	ft::pair<const int, std::string> p5(13, "Chrisss");
	ft::pair<ft::map<int, std::string>::iterator, bool> insert_val = m.insert(p5);
	std::cout << (insert_val.second ? "INSERTED" : "ALREADY INSERTED") << std::endl;
	insert_val = m.insert(p5);
	std::cout << (insert_val.second ? "INSERTED" : "ALREADY INSERTED") << std::endl;
	m.insert(p1);
	ft::map<int, std::string>::iterator insert_res = m.insert(m.begin(), p2);
	m.insert(p3);
	m.insert(p4);
	// m.printMap();
	// m.comparePairs(p1, p2);
	ft::map<int, std::string>::iterator it = m.begin();
	ft::map<int, std::string>::iterator ite = m.end();
	for (; it != ite; ++it)
		std::cout << (*it).first << ": " << (*it).second << std::endl;

	// m[9] = "HEHEHE";
	try {
		std::cout << "|" << m.at(8) << "|" << std::endl;
	} catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}

	ft::map<int, std::string>::iterator it1 = m.begin();
	ft::map<int, std::string>::const_iterator cit1 = m.begin();

	std::cout << (*it1).first << ": " << (*it1).second << std::endl;
	std::cout << (*cit1).first << ": " << (*cit1).second << std::endl;

	(*it1).second = "JOJI";

	std::cout << (*it1).first << ": " << (*it1).second << std::endl;
	std::cout << (*cit1).first << ": " << (*cit1).second << std::endl;
	std::cout << (*cit1) << std::endl;

	// ft::map<int, std::string>::reverse_iterator rit1 = m.rbegin();
	// ++rit1;
	// ++rit1;
	// std::cout << (*rit1).first << ": " << (*rit1).second << std::endl;
	// std::cout << (*rit1) << std::endl;
	// std::cout << "hehe" << std::endl;

	// std::cout << insert_res->first << ": " << insert_res->second << std::endl;
	m.printMap();
	// std::cout << insert_res->first << ": " << insert_res->second << std::endl;
}

void test_pair_playground() {
	// ft::pair<std::string, int> pr = ft::make_pair(std::string("Hello"), 42);
	// ft::pair<std::string, int> pr = ft::make_pair("Hello", 42); // NOTE: this works in the std:: version why?
	// ft::pair<std::string, int> pr = ft::make_pair(std::string("Hello"), 42);
	// std::cout << pr.first << ": " << pr.second << std::endl;
}

#endif
