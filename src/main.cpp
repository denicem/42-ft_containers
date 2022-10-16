/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:27:59 by dmontema          #+#    #+#             */
/*   Updated: 2022/10/15 21:52:25 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../inc/vect.hpp"
#include "../inc/vector.hpp"

int main()
{
	// std::vector<int> vect;
	// vect.push_back(42);
	// vect.push_back(42);
	// vect.push_back(42);
	// vect.push_back(42);
	// std::cout << vect.capacity() << std::endl;

	// func::Vect<int> vect;
	// std::vector<int> og_vect;
	// for (int i = 0; i < 14; i++)
	// {
	// 	vect.push_back(i + 42);
	// 	og_vect.push_back(i + 42);
	// }
	// std::cout << "CAP: " << vect.capacity() << std::endl;
	// std::cout << "SIZE: " << vect.size() << std::endl;
	// std::cout << vect[2] << std::endl;
	// vect[2] = 56;
	// std::cout << vect[2] << std::endl;

	// std::cout << "- - - - - - - - - - - - - -\n";

	// std::cout << "CAP: " << vect.capacity() << std::endl;
	// std::cout << "SIZE: " << vect.size() << std::endl;
	// std::cout << vect[2] << std::endl;
	// vect[2] = 56;
	// std::cout << vect[2] << std::endl;

	// std::vector<int> vect(4, 2);
	// std::cout << vect.capacity() << " " << vect.size() << std::endl;
	// for (int i = 0; i < vect.size(); i++)
	// 	std::cout << vect[i] << " ";
	// std::cout << std::endl;

	// ft::vector<int> vect;
	// ft::vector<std::string> vect;
	ft::vector<int> vect(10, 42);
	std::cout << "CAP: " << vect.capacity() << " SIZE: " << vect.size() << std::endl;
	// vect.push_back(42);
	// vect.push_back(21);
	// vect.push_back("hehe");
	// vect.push_back("huhu");
	std::cout << "CAP: " << vect.capacity() << " SIZE: " << vect.size() << std::endl;
	for (int i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;

	return (0);
}
