/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:27:59 by dmontema          #+#    #+#             */
/*   Updated: 2022/10/11 22:18:42 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../inc/vect.hpp"

int main()
{
	// std::vector<int> vect;
	// vect.push_back(42);
	// vect.push_back(42);
	// vect.push_back(42);
	// vect.push_back(42);
	// std::cout << vect.capacity() << std::endl;

	func::Vect<int> vect;
	for (int i = 0; i < 14; i++)
		vect.push_back(i + 42);
	std::cout << "CAP: " << vect.capacity() << std::endl;
	std::cout << "SIZE: " << vect.size() << std::endl;
	std::cout << vect[2] << std::endl;
	vect[2] = 56;
	std::cout << vect[2] << std::endl;

	return (0);
}
