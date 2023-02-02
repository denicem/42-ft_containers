/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:27:59 by dmontema          #+#    #+#             */
/*   Updated: 2023/02/02 22:14:36 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"

#include <iostream>
#include <cassert>

#include "Vect3.hpp"

#include "test_general.hpp"
#include "test_vector.hpp"

int main() {
	std::cout << "Hello ft_containers." << std::endl;

	// measureTime(&vector_test_basic_std, &vector_test_basic_ft);

	// NOTE: these are test cases for the comparison between std and ft version
	// Test case 1: Constructors
	// TEST default constructor
	std::vector<int> v1;
	ft::vector<int> fv1;
	assert(v1.empty() == fv1.empty());

	// TEST fill constructor
	std::vector<int> v2(5);
	ft::vector<int> fv2(5);
	assert(v2.size() == fv2.size());
	for (size_t i = 0; i < v2.size() && i < fv2.size(); ++i)
		std::cout << v2[0] << " " << fv2[0] << std::endl;

	// TEST fill copy constructor
	std::vector<int> v2_cpy(v2);
	ft::vector<int> fv2_cpy(fv2);
	assert(v2_cpy.size() == fv2_cpy.size());
	for (size_t i = 0; i < v2_cpy.size() && i < fv2_cpy.size(); ++i)
		std::cout << v2_cpy[0] << " " << fv2_cpy[0] << std::endl;

	// TEST fill constructor with second argument
	std::vector<int> v3(10, 5);
	ft::vector<int> fv3(10, 5);
	assert(v3.size() == fv3.size());
	std::cout << "Size: " << v3.size() << " " << fv3.size() << std::endl;
	for (size_t i = 0; i < v3.size() && i < fv3.size(); ++i)
		std::cout << v3[0] << " " << fv3[0] << std::endl;

	// TEST range constructor
	std::vector<int> v5(5, 42);
	ft::vector<int> fv5(v5.begin(), v5.end());
	assert(v5.size() == fv5.size());
	v5.clear();
	fv5.clear();
	assert(v5.empty() == fv5.empty());

	std::cout << "Capacity: " << v5.capacity() << " | " << fv5.capacity() << std::endl;
	fv5.push_back(21);
	for (ft::vector<int>::iterator it = fv5.begin(); it != fv5.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// Test case 2: push_back() and size()
	std::vector<int> v4;
	ft::vector<int> fv4;
	for (int i = 0; i < 5; i++) {
		v4.push_back(i);
		fv4.push_back(i);
		assert(v4.size() == fv4.size());
	}
	for (ft::vector<int>::size_type i = 0; i < fv4.size(); ++i)
		std::cout << fv4[i] << " ";
	std::cout << std::endl;

	// TEST assign
	// std::vector<int> nbrs(11, 42);

	// for (size_t i = 0; i < nbrs.size(); ++i)
	// 	std::cout << nbrs[i] << " ";
	// std::cout << std::endl;
	// std::cout << "Cap: " << nbrs.capacity() << "\nSize: " << nbrs.size() << std::endl;

	// nbrs.assign(10, 21);
	// std::cout << std::endl;
	
	// for (size_t i = 0; i < nbrs.size(); ++i)
	// 	std::cout << nbrs[i] << " ";
	// std::cout << std::endl;
	// std::cout << "Cap: " << nbrs.capacity() << "\nSize: " << nbrs.size() << std::endl;

	return (0);
}


// // std::vector<int> vect;
// // vect.push_back(42);
// // vect.push_back(42);
// // vect.push_back(42);
// // vect.push_back(42);
// // std::cout << vect.capacity() << std::endl;

// // func::Vect<int> vect;
// // std::vector<int> og_vect;
// // for (int i = 0; i < 14; i++)
// // {
// 	// vect.push_back(i + 42);
// // 	og_vect.push_back(i + 42);
// // }
// // std::cout << "CAP: " << vect.capacity() << std::endl;
// // std::cout << "SIZE: " << vect.size() << std::endl;
// // std::cout << vect[2] << std::endl;
// // vect[2] = 56;
// // std::cout << vect[2] << std::endl;
// // for (std::vector<int>::iterator it = og_vect.begin(); it != og_vect.end(); it++)
// // 	std::cout << *it << it.base() << " ";
// // std::cout << std::endl;

// // std::vector<int>::iterator it = og_vect.begin();
// // std::vector<int>::iterator it2 = og_vect.begin();
// // std::vector<int>::iterator it3 = it + 2;
// // std::vector<int>::iterator it4 = it + 7;
// // it += it2;

// // std::cout << (--it).base() << std::endl;
// // std::cout << *it2 << std::endl;
// // std::cout << *it3 << std::endl;
// // std::cout << it4.base() << std::endl;

// // std::cout << "- - - - - - - - - - - - - -\n";

// // std::cout << "CAP: " << vect.capacity() << std::endl;
// // std::cout << "SIZE: " << vect.size() << std::endl;
// // std::cout << vect[2] << std::endl;
// // vect[2] = 56;
// // std::cout << vect[2] << std::endl;

// // std::vector<int> vect(4, 2);
// // std::cout << vect.capacity() << " " << vect.size() << std::endl;
// // for (int i = 0; i < vect.size(); i++)
// // 	std::cout << vect[i] << " ";
// // std::cout << std::endl;

// // ft::vector<int> vect;
// // ft::vector<std::string> vect;
// // ft::vector<int> vect(10, 42);
// // std::cout << "CAP: " << vect.capacity() << " SIZE: " << vect.size() << std::endl;
// // vect.push_back(42);
// // vect.push_back(21);
// // vect.push_back("hehe");
// // vect.push_back("huhu");
// // std::cout << "CAP: " << vect.capacity() << " SIZE: " << vect.size() << std::endl;
// // for (int i = 0; i < vect.size(); i++)
// // 	std::cout << vect[i] << " ";
// // std::cout << std::endl;

// // std::vector<int> og;
// // std::vector<std::string> og_str;
// // std::vector<vect3> vect3_vect;
// ft::vector<int> vect;
// for (int i = 0; i < 14; i++)
// 	vect.push_back(i + 42);
// vect[0] = 21;
// ft::vector<int>::const_iterator itc = vect.begin();
// ft::vector<int>::iterator it = vect.begin();
// ft::vector<int>::iterator it1 = it + 1;
// it += 4;
// std::cout << "it: " << *it << std::endl;
// std::cout << "it1: " << *it1 << std::endl;

// if (itc >= it)
// 	std::cout << "hehe\n";
// else
// 	std::cout << "huhu\n";

// std::cout << it.base() << std::endl;

// std::cout << *it << std::endl;
// ++it;
// ++it;
// ++it;
// --it;
// *it++ = 56;
// std::cout << *it << std::endl;

// // for (auto v: vect)
// // 	std::cout << v << " ";
// // std::cout << std::endl;
// for (ft::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
// 	std::cout << *it << " ";
// std::cout << std::endl;
// vect.front() = 90;
// std::cout << vect.front() << std::endl;
// for (ft::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
// 	std::cout << *it << " ";
// std::cout << std::endl;

// // const int = vect.front();

// // std::cout << og.max_size() << std::endl;
// // std::cout << og_str.max_size() << std::endl;
// // std::cout << vect3_vect.max_size() << std::endl;
// // std::cout << vect3_vect.max_size() * 3 << std::endl;

// ft::vector<vect3> v3;
// for (int i = 0; i < 4; i++)
// 	v3.push_back(vect3(i + 42, i + 42 + 1, i + 42 + 2));
// // for (size_t i = 0; i < v3.size(); i++)
// // 	std::cout << v3[i] << std::endl;
// for (ft::vector<vect3>::iterator it = v3.begin(); it != v3.end(); it++)
// 	std::cout << *it << std::endl;

// ft::vector<vect3>::iterator itv3 = v3.begin();
// itv3 += 2;
// std::cout << *itv3 << std::endl;

// // ft::vector<int> vect_range_test(vect.begin(), vect.end());
// ft::vector<int> vect_range_test(vect);
// for (ft::vector<int>::iterator it = vect_range_test.begin(); it != vect_range_test.end(); ++it)
// 	std::cout << *it << " ";
// std::cout << std::endl;

// ft::vector<int> v1;
// ft::vector<int> v2;
// ft::vector<int> v3;

// for (int i = 0 ; i < 8; ++i)
// 	v3.push_back(i + 56);
// for (int i = 0 ; i < 4; ++i)
// 	v2.push_back(i + 42);
// std::cout << "v2: ";
// for (auto v: v2)
// 	std::cout << v << " ";
// std::cout << std::endl;
// std::cout << "v3: ";
// for (auto v: v3)
// 	std::cout << v << " ";
// std::cout << std::endl;

// v2.push_back(53);
// v3 = v1;
// v2.shrink_to_fit();
// v2.resize(10);
// std::cout << std::endl << v2.capacity() << " " << v2.size() << std::endl;
// for (auto v: v2)
// 	std::cout << v << " ";
// std::cout << std::endl;

// std::cout << v2.empty() << " " << v1.empty() << std::endl;

// ft::vector<int>::iterator it = v3.begin();
// ft::vector<int>::iterator it2 = v3.end();
// it2--;
// it2--;
// ft::vector<int>::difference_type res = it2 - it;
// std::cout << res << std::endl;
// std::cout << v3.size() << " " << v3.capacity() << std::endl;
// v3.insert (v3.begin() + 1, 11, 782);
// v3.insert(it2, v2.begin(), v2.end());
// v3.insert(it2 + 15, 5420);
// v3.insert(it2 + 15, 5420); // NOTE: what happening here?
// for (auto v: v3)
// 	std::cout << &v << " " << v << ", ";
// std::cout << std::endl;
// std::cout << v3.size() << " " << v3.capacity() << std::endl;
// std::cout << it2.base() << " " << *it2 << std::endl;
// v3.erase(v3.end() - 5);
// for (auto v: v3)
// 	std::cout << v << " ";
// std::cout << std::endl;

// v2.assign(2, 302);
// v2.assign(v3.begin(), v3.end());
// for (auto v: v2)
// 	std::cout << v << " ";
// std::cout << std::endl;

// std::vector<int> og_vec;
// ft::vector<int> ft_vec;

// std::cout << "OG_VEC: " << og_vec.max_size() << std::endl;
// std::cout << "FT_VEC: " << ft_vec.max_size() << std::endl;

// std::cout << "- - - - - - - - -\n";
// pointer_func(v3.data(), v3.size());
// std::vector<int> vec;
