/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:27:59 by dmontema          #+#    #+#             */
/*   Updated: 2023/02/21 17:27:30 by dmontema         ###   ########.fr       */
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
#include "test_avltree.hpp"

#include <iostream>

#include "Vect3.hpp"

// #include "test_general.hpp"
// #include "test_vector.hpp"

// struct cmpByStringLength {
//     bool operator()(const std::string& a, const std::string& b) const {
//         return a.length() < b.length();
//     }
// };


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

	// ft::AVLTree<int> avl_int;
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
	// avl_int.printTree();

	// std::cout << "MIN: " << avl_int.min_node(avl_int.getRoot())->data << std::endl;
	// std::cout << "MAX: " << avl_int.max_node(avl_int.getRoot())->data << std::endl;
	// std::cout << "PRE - 37: " << avl_int.predecessor(avl_int.search(37))->data << std::endl;
	// std::cout << "SUC - 37: " << avl_int.successor(avl_int.search(37))->data << std::endl;

	// test_interactive();

	// ft::AVLTree<int>::node n1(20);
	// ft::AVLTree<int>::node n2(15);

	// avl_int.compareNodes(&n1, &n2);


	// std::cout << (*it).first << ": " << (*it).second << std::endl;
	// ++it;
	// std::cout << (*it).first << ": " << (*it).second << std::endl;

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

	m[9] = "HEHEHE";
	// std::cout << m[9] << std::endl;


	m.printMap();
	std::cout << insert_res->first << ": " << insert_res->second << std::endl;

	return (0);
}
