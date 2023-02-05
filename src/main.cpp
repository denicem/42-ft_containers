/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:27:59 by dmontema          #+#    #+#             */
/*   Updated: 2023/02/05 19:29:17 by dmontema         ###   ########.fr       */
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
	std::cout << "Hello ft_containers." << std::endl << std::endl;

	// measureTime(&vector_test_basic_std, &vector_test_basic_ft);
	// vectorTestConstructors();
	// vectorTestPushBack();
	// vectorTestAssign();
	// vectorTestSwap();
	// vectorTestInsert();
	// vectorTestResize();
	vectorTestErase();

	return (0);
}
