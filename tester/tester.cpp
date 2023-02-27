/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:27:59 by dmontema          #+#    #+#             */
/*   Updated: 2023/02/27 19:15:38 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_general.hpp"

#include <iostream>

#include "stl_mode.hpp"
#include "eval_vector_test.hpp"
#include "eval_stack_test.hpp"
#include "eval_map_test.hpp"

int main(int argc, char* argv[]) {
	if (argc > 1)
		srand(atoi(argv[1]));
	if (STL)
		std::cout << "STD version" << std::endl << std::endl;
	else if (!STL)
		std::cout << "FT version" << std::endl << std::endl;

	test_vector_default_ctor();
	test_vector_fill_ctor();
	test_vector_range_ctor();
	test_vector_copy_ctor();
	test_vector_assignment_operator();
	test_vector_iterators();
	test_vector_capacity();
	test_vector_element_access();
	test_vector_modifiers();

	test_stack();

	test_map_ctor();
	test_map_insert();
	test_map_erase();
	test_map_element_access_lookup();

	return (0);
}
