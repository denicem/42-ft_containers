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

void vectorTestConstructors() {
	// NOTE: these are test cases for the comparison between std and ft version
	// Test case 1: Constructors
	// TEST default constructor
	std::vector<int> v1;
	ft::vector<int> fv1;
	assert(v1.empty() == fv1.empty());

	// TEST fill constructor
	std::vector<int> v2(5);
	ft::vector<int> fv2(5);
	assert(v2.size() == fv2.size());
	for (size_t i = 0; i < v2.size() && i < fv2.size(); ++i)
		std::cout << v2[0] << " " << fv2[0] << std::endl;

	// TEST fill copy constructor
	std::vector<int> v2_cpy(v2);
	ft::vector<int> fv2_cpy(fv2);
	assert(v2_cpy.size() == fv2_cpy.size());
	for (size_t i = 0; i < v2_cpy.size() && i < fv2_cpy.size(); ++i)
		std::cout << v2_cpy[0] << " " << fv2_cpy[0] << std::endl;

	// TEST fill constructor with second argument
	std::vector<int> v3(10, 5);
	ft::vector<int> fv3(10, 5);
	assert(v3.size() == fv3.size());
	std::cout << "Size: " << v3.size() << " " << fv3.size() << std::endl;
	for (size_t i = 0; i < v3.size() && i < fv3.size(); ++i)
		std::cout << v3[0] << " " << fv3[0] << std::endl;

	// TEST range constructor
	std::vector<int> v5(5, 42);
	ft::vector<int> fv5(v5.begin(), v5.end());
	assert(v5.size() == fv5.size());
	v5.clear();
	fv5.clear();
	assert(v5.empty() == fv5.empty());

	std::cout << "Capacity: " << v5.capacity() << " | " << fv5.capacity() << std::endl;
	fv5.push_back(21);
	for (ft::vector<int>::iterator it = fv5.begin(); it != fv5.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void vectorTestPushBack() {
	// Test case 2: push_back() and size()
	std::vector<int> v4;
	ft::vector<int> fv4;
	for (int i = 0; i < 5; i++) {
		v4.push_back(i);
		fv4.push_back(i);
		assert(v4.size() == fv4.size());
	}
	for (ft::vector<int>::size_type i = 0; i < fv4.size(); ++i)
		std::cout << fv4[i] << " ";
	std::cout << std::endl;
}

void vectorTestAssign() {
	// TEST assign
	std::vector<int> fiftysix(6, 56);
	fiftysix.push_back(5);
	fiftysix.push_back(6);
	fiftysix.push_back(560);
	fiftysix.push_back(5600);
	fiftysix.push_back(-56);
	std::vector<int> nbrs(11, 42);
	ft::vector<int> fnbrs(11, 42);

	for (size_t i = 0; i < nbrs.size(); ++i)
		std::cout << nbrs[i] << " ";
	std::cout << std::endl;
	std::cout << "Cap: " << nbrs.capacity() << "\nSize: " << nbrs.size() << std::endl;
	for (size_t i = 0; i < fnbrs.size(); ++i)
		std::cout << fnbrs[i] << " ";
	std::cout << std::endl;
	std::cout << "fCap: " << fnbrs.capacity() << "\nfSize: " << fnbrs.size() << std::endl;
	assert(nbrs.size() == fnbrs.size() && nbrs.capacity() == fnbrs.capacity());

	nbrs.assign(10, 21);
	fnbrs.assign(10, 21);
	std::cout << std::endl;
	
	for (size_t i = 0; i < nbrs.size(); ++i)
		std::cout << nbrs[i] << " ";
	std::cout << std::endl;
	std::cout << "Cap: " << nbrs.capacity() << "\nSize: " << nbrs.size() << std::endl;
	for (size_t i = 0; i < fnbrs.size(); ++i)
		std::cout << fnbrs[i] << " ";
	std::cout << std::endl;
	std::cout << "fCap: " << fnbrs.capacity() << "\nfSize: " << fnbrs.size() << std::endl;
	assert(nbrs.size() == fnbrs.size() && nbrs.capacity() == fnbrs.capacity());

	nbrs.assign(fiftysix.begin(), fiftysix.end());
	fnbrs.assign(fiftysix.begin(), fiftysix.end());
	std::cout << std::endl;

	for (size_t i = 0; i < nbrs.size(); ++i)
		std::cout << nbrs[i] << " ";
	std::cout << std::endl;
	std::cout << "Cap: " << nbrs.capacity() << "\nSize: " << nbrs.size() << std::endl;
	for (size_t i = 0; i < fnbrs.size(); ++i)
		std::cout << fnbrs[i] << " ";
	std::cout << std::endl;
	std::cout << "fCap: " << fnbrs.capacity() << "\nfSize: " << fnbrs.size() << std::endl;
	assert(nbrs.size() == fnbrs.size() && nbrs.capacity() == fnbrs.capacity());

	nbrs.assign(14, 17);
	fnbrs.assign(14, 17);
	std::cout << std::endl;
	
	for (size_t i = 0; i < nbrs.size(); ++i)
		std::cout << nbrs[i] << " ";
	std::cout << std::endl;
	std::cout << "Cap: " << nbrs.capacity() << "\nSize: " << nbrs.size() << std::endl;
	for (size_t i = 0; i < fnbrs.size(); ++i)
		std::cout << fnbrs[i] << " ";
	std::cout << std::endl;
	std::cout << "fCap: " << fnbrs.capacity() << "\nfSize: " << fnbrs.size() << std::endl;
	assert(nbrs.size() == fnbrs.size() && nbrs.capacity() == fnbrs.capacity());

	nbrs.assign(2, 1997);
	fnbrs.assign(2, 1997);
	std::cout << std::endl;
	
	for (size_t i = 0; i < nbrs.size(); ++i)
		std::cout << nbrs[i] << " ";
	std::cout << std::endl;
	std::cout << "Cap: " << nbrs.capacity() << "\nSize: " << nbrs.size() << std::endl;
	for (size_t i = 0; i < fnbrs.size(); ++i)
		std::cout << fnbrs[i] << " ";
	std::cout << std::endl;
	std::cout << "fCap: " << fnbrs.capacity() << "\nfSize: " << fnbrs.size() << std::endl;
	assert(nbrs.size() == fnbrs.size() && nbrs.capacity() == fnbrs.capacity());
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