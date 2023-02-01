#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

#include <vector>
#include "vector.hpp"

#include <iostream>
#include "test_general.hpp"

void vector_test_basic_std() {
	std::vector<int> nbrs;

	nbrs.push_back(42);

	std::cout << nbrs[0] << std::endl;
}

void vector_test_basic_ft() {
	ft::vector<int> nbrs;

	nbrs.push_back(42);

	std::cout << nbrs[0] << std::endl;
}

#endif

/*
Default constructor: TODO:
	Test that the default constructor initializes the vector
	with the correct size and capacity, and that it behaves
	as expected when elements are added and removed.

Size and capacity: TODO:
	Test that the size and capacity member functions return
	the correct values, and that the capacity increases
	dynamically as elements are added to the vector.

Element access: TODO:
	Test that elements can be accessed using the operator[]
	and the at member functions, and that out-of-range
	accesses throw exceptions.

Insertion and deletion: TODO:
	Test that elements can be inserted and deleted at the end
	of the vector, as well as at specific positions, and that
	the size and capacity of the vector are updated as expected.

Copy constructor and assignment operator: TODO:
	Test that the copy constructor and assignment operator behave
	as expected, creating deep copies of the vector and preserving
	the elements and their values.

Iterators: TODO:
	Test that the iterators provided by the vector class work as
	expected, and that they can be used to traverse the elements
	of the vector.

Allocator: TODO:
	Test that the std::allocator class is used correctly,
	allocating and deallocating memory as expected, and
	constructing and destroying elements correctly.
*/