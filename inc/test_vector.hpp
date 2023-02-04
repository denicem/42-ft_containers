#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

#include <vector>
#include "vector.hpp"

#include <iostream>
#include "test_general.hpp"

std::vector<int> createStdVectorInt(unsigned size) {
	std::vector<int> res;

	for (unsigned i = 0; i < size; i++)
		res.push_back(i);

	return (res);
}

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

void vectorTestConstructors() {
	PRINT_W_COLOR(CYAN, "Testing constructors");
	PRINT_W_COLOR(DARKGRAY, "--------------------");

	// TEST default constructor
	std::vector<int> v1;
	ft::vector<int> fv1;
	assert(v1.empty() == fv1.empty());

	// TEST fill constructor
	std::vector<int> v2(5);
	ft::vector<int> fv2(5);
	assert(v2.size() == fv2.size());
	print_container_compare(v2, fv2, true);

	// TEST fill copy constructor
	std::vector<int> v2_cpy(v2);
	ft::vector<int> fv2_cpy(fv2);
	assert(v2_cpy.size() == fv2_cpy.size());
	print_container_compare(v2_cpy, fv2_cpy);

	// TEST fill constructor with second argument
	std::vector<int> v3(10, 5);
	ft::vector<int> fv3(10, 5);
	assert(v3.size() == fv3.size());
	print_container_compare(v3, fv3, true);

	// TEST range constructor
	std::vector<int> example = createStdVectorInt(8);
	ft::vector<int> v5(example.begin(), example.end());
	ft::vector<int> fv5(example.begin(), example.end());
	assert(v5.size() == fv5.size());
	// v5.clear();
	// fv5.clear();
	// assert(v5.empty() == fv5.empty());
	print_container_compare(v5, fv5);

	PRINT_W_COLOR(DARKGRAY, "--------------------") << std::endl;
}

void vectorTestPushBack() {
	PRINT_W_COLOR(CYAN, "Testing push_back() and size()");
	PRINT_W_COLOR(DARKGRAY, "--------------------");

	std::vector<int> v1;
	ft::vector<int> fv1;
	print_container_compare(v1, fv1);
	for (int i = 0; i < 5; i++) {
		v1.push_back(i);
		fv1.push_back(i);
		assert(v1.size() == fv1.size());
	}
	print_container_compare(v1, fv1);

	PRINT_W_COLOR(DARKGRAY, "--------------------") << std::endl;
}

void vectorTestAssign() {
	PRINT_W_COLOR(CYAN, "Testing assign()");
	PRINT_W_COLOR(DARKGRAY, "--------------------");

	std::vector<int> fiftysix(6, 56);
	fiftysix.push_back(5);
	fiftysix.push_back(6);
	fiftysix.push_back(560);
	fiftysix.push_back(5600);
	fiftysix.push_back(-56);

	std::vector<int> nbrs(10, 42);
	ft::vector<int> fnbrs(10, 42);

	print_container_compare(nbrs, fnbrs, true);

	nbrs.assign(10, 21);
	fnbrs.assign(10, 21);
	
	assert(nbrs.size() == fnbrs.size() && nbrs.capacity() == fnbrs.capacity());
	print_container_compare(nbrs, fnbrs, true);

	nbrs.assign(fiftysix.begin(), fiftysix.end());
	fnbrs.assign(fiftysix.begin(), fiftysix.end());

	assert(nbrs.size() == fnbrs.size() && nbrs.capacity() == fnbrs.capacity());
	print_container_compare(nbrs, fnbrs, true);

	nbrs.assign(14, 17);
	fnbrs.assign(14, 17);

	assert(nbrs.size() == fnbrs.size() && nbrs.capacity() == fnbrs.capacity());
	print_container_compare(nbrs, fnbrs, true);

	nbrs.assign(2, 1997);
	fnbrs.assign(2, 1997);

	assert(nbrs.size() == fnbrs.size() && nbrs.capacity() == fnbrs.capacity());
	print_container_compare(nbrs, fnbrs, true);

	PRINT_W_COLOR(DARKGRAY, "--------------------") << std::endl;
}

void vectorTestSwap() {
	PRINT_W_COLOR(CYAN, "Testing swap()");
	PRINT_W_COLOR(DARKGRAY, "--------------------");

	std::vector<int> v1(5, 42);
	std::vector<int> v2(9, 21);
	ft::vector<int> fv1(5, 42);
	ft::vector<int> fv2(9, 21);

	PRINT_W_COLOR(BLUE, "v1");
	std::cout << YELLOW << v1.data() << ": "; print_container(v1, true); std::cout << RESET;
	std::cout << MAGENTA << fv1.data() << ": "; print_container(fv1, true); std::cout << RESET;
	PRINT_W_COLOR(BLUE, "v2");
	std::cout << YELLOW << v2.data() << ": "; print_container(v2, true); std::cout << RESET;
	std::cout << MAGENTA << fv2.data() << ": "; print_container(fv2, true); std::cout << RESET;

	std::swap(v1, v2);
	ft::swap(fv1, fv2);
	std::cout << std::endl << "swapping ..." << std::endl << std::endl;

	PRINT_W_COLOR(LIGHTBLUE, "v1");
	std::cout << LIGHTYELLOW << v1.data() << ": "; print_container(v1, true); std::cout << RESET;
	std::cout << LIGHTMAGENTA << fv1.data() << ": "; print_container(fv1, true); std::cout << RESET;
	PRINT_W_COLOR(LIGHTBLUE, "v2");
	std::cout << LIGHTYELLOW << v2.data() << ": "; print_container(v2, true); std::cout << RESET;
	std::cout << LIGHTMAGENTA << fv2.data() << ": "; print_container(fv2, true); std::cout << RESET;

	PRINT_W_COLOR(DARKGRAY, "--------------------") << std::endl;
}

#endif

/*
Default constructor: TODO:
	Test that the default constructor initializes the vector
	with the correct size and capacity, and that it behaves
	as expected when elements are added and removed.

Copy constructor and assignment operator: TODO:
	Test that the copy constructor and assignment operator behave
	as expected, creating deep copies of the vector and preserving
	the elements and their values.

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

Iterators: TODO:
	Test that the iterators provided by the vector class work as
	expected, and that they can be used to traverse the elements
	of the vector.

Allocator: TODO:
	Test that the std::allocator class is used correctly,
	allocating and deallocating memory as expected, and
	constructing and destroying elements correctly.
*/