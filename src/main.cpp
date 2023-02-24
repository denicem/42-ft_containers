/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:27:59 by dmontema          #+#    #+#             */
/*   Updated: 2023/02/24 22:44:56 by dmontema         ###   ########.fr       */
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

#include <iostream>

#include "Vect3.hpp"

#include "test_general.hpp"
#include "test_vector.hpp"
#include "test_avltree.hpp"
#include "test_map.hpp"


int main() {
	std::cout << "Hello ft_containers." << std::endl << std::endl;

	// vectorTestConstructors();
	// vectorTestPushBack();
	// vectorTestAssign();
	// vectorTestSwap();
	// vectorTestInsert();
	// vectorTestResize();
	// vectorTestErase();

	// test_vector_playground();
	// test_avltree_playground();
	// test_interactive();
	// test_pair_playground();
	test_map_playground();
	// system("leaks ft_containers");

	return (0);
}
