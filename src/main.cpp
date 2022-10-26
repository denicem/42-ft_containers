/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:27:59 by dmontema          #+#    #+#             */
/*   Updated: 2022/10/25 22:11:47 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../inc/vect.hpp"
#include "../inc/vector.hpp"

struct vect3
{
	int x, y, z;

	vect3() {}
	vect3(int x, int y, int z): x(x), y(y), z(z) {}

	friend std::ostream& operator<<(std::ostream& stream, vect3& v3);
};

std::ostream& operator<<(std::ostream& stream, vect3& v3)
{
	stream << v3.x << " " << v3.y << " " << v3.z;
	return (stream);
}

int main()
{
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

	ft::vector<int> v1;
	ft::vector<int> v2;
	ft::vector<int> v3;

	for (int i = 0 ; i < 8; ++i)
		v3.push_back(i + 56);
	for (int i = 0 ; i < 4; ++i)
		v2.push_back(i + 42);
	std::cout << "v2: ";
	for (auto v: v2)
		std::cout << v << " ";
	std::cout << std::endl;
	std::cout << "v3: ";
	for (auto v: v3)
		std::cout << v << " ";
	std::cout << std::endl;

	// v3 = v1;
	// std::cout << std::endl << v3.capacity() << " " << v3.size() << std::endl;
	// for (auto v: v3)
	// 	std::cout << &v << " ";
	// std::cout << std::endl;

	std::cout << v2.empty() << " " << v1.empty() << std::endl;

	ft::vector<int>::iterator it = v2.begin();
	ft::vector<int>::iterator it2 = v2.end();
	it2--;
	std::cout << it2 - it << std::endl;

	// v2.assign(2, 302);
	v2.assign(v3.begin(), v3.end());
	for (auto v: v2)
		std::cout << v << " ";
	std::cout << std::endl;

	// std::vector<int> og_vec;
	// ft::vector<int> ft_vec;

	// std::cout << "OG_VEC: " << og_vec.max_size() << std::endl;
	// std::cout << "FT_VEC: " << ft_vec.max_size() << std::endl;
	return (0);
}
