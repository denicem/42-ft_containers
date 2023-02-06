/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:27:59 by dmontema          #+#    #+#             */
/*   Updated: 2023/02/06 21:44:55 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"

#include <iostream>

#include "Vect3.hpp"

#include "test_general.hpp"
#include "test_vector.hpp"

int main() {
	std::cout << "Hello ft_containers." << std::endl << std::endl;

	vectorTestConstructors();
	vectorTestPushBack();
	vectorTestAssign();
	vectorTestSwap();
	// vectorTestInsert();
	// vectorTestResize();
	// vectorTestErase();

	std::vector<int> v1(5, 42);
	ft::vector<int> fv1(5, 42);
	assert(v1.size() == fv1.size(), true);
	assert(v1.size() != fv1.size(), true);
	assert(v1.size() >= fv1.size(), true);
	assert(v1.size() > fv1.size(), true);
	assert(v1.size() <= fv1.size(), true);
	assert(v1.size() < fv1.size(), true);
	measureTime(&vector_test_basic_std, &vector_test_basic_ft);

	return (0);
}
