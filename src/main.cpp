/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:27:59 by dmontema          #+#    #+#             */
/*   Updated: 2023/02/11 00:18:03 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include "utility.hpp"

#include <iostream>

#include "Vect3.hpp"

// #include "test_general.hpp"
// #include "test_vector.hpp"

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
	ft::pair<std::string, int> pr = ft::make_pair(std::string("Hello"), 42);


	std::cout << pr.first << ": " << pr.second << std::endl;

	return (0);
}
