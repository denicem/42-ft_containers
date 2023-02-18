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

ft::vector<int> createFtVectorInt(unsigned size) {
	ft::vector<int> res;

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

void vector_test_basic() {
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
	assert(v1.empty() == fv1.empty(), true);

	// TEST fill constructor
	std::vector<int> v2(5);
	ft::vector<int> fv2(5);
	assert(v2.size() == fv2.size(), true);
	print_container_compare(v2, fv2, true);

	// TEST fill copy constructor
	std::vector<int> v2_cpy(v2);
	ft::vector<int> fv2_cpy(fv2);
	assert(v2_cpy.size() == fv2_cpy.size(), true);
	print_container_compare(v2_cpy, fv2_cpy);

	// TEST fill constructor with second argument
	std::vector<int> v3(10, 5);
	ft::vector<int> fv3(10, 5);
	assert(v3.size() == fv3.size(), true);
	print_container_compare(v3, fv3, true);

	// TEST range constructor
	std::vector<int> example = createStdVectorInt(8);
	ft::vector<int> v5(example.begin(), example.end());
	ft::vector<int> fv5(example.begin(), example.end());
	assert(v5.size() == fv5.size(), true);
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
		assert(v1.size() == fv1.size(), true);
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
	
	assert(nbrs.size() == fnbrs.size() && nbrs.capacity() == fnbrs.capacity(), true);
	print_container_compare(nbrs, fnbrs, true);

	nbrs.assign(fiftysix.begin(), fiftysix.end());
	fnbrs.assign(fiftysix.begin(), fiftysix.end());

	assert(nbrs.size() == fnbrs.size() && nbrs.capacity() == fnbrs.capacity(), true);
	print_container_compare(nbrs, fnbrs, true);

	nbrs.assign(14, 17);
	fnbrs.assign(14, 17);

	assert(nbrs.size() == fnbrs.size() && nbrs.capacity() == fnbrs.capacity(), true);
	print_container_compare(nbrs, fnbrs, true);

	nbrs.assign(2, 1997);
	fnbrs.assign(2, 1997);

	assert(nbrs.size() == fnbrs.size() && nbrs.capacity() == fnbrs.capacity(), true);
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

// void vectorTestInsert() {
// 	std::vector<int> v1(5, 42);
// 	ft::vector<int> fv1(5, 42);

// 	PRINT_W_COLOR(BOLD, "vector at the beginning");
// 	print_container_compare(v1, fv1, true);

// 	//TODO: save return value from insert single element
// 	// insert, single element, begin
// 	PRINT_W_COLOR(BOLD, "\ninserting single element at the beginning");
// 	v1.insert(v1.begin(), 21);
// 	fv1.insert(fv1.begin(), 21);
// 	print_container_compare(v1, fv1, true);

// 	// insert, single element, in the middle
// 	PRINT_W_COLOR(BOLD, "\ninserting single element in the middle");
// 	v1.insert(v1.begin() + 3, 21);
// 	fv1.insert(fv1.begin() + 3, 21);
// 	print_container_compare(v1, fv1, true);

// 	// insert, single element, end
// 	PRINT_W_COLOR(BOLD, "\ninserting single element at the end");
// 	v1.insert(v1.end(), 21);
// 	fv1.insert(fv1.end(), 21);
// 	print_container_compare(v1, fv1, true);

// 	//resetting vector to initial state TODO: shrink_to_fit() is in C++11 -> put test cases in a scope 
// 	v1.assign(5, 42);
// 	v1.shrink_to_fit();
// 	fv1.assign(5, 42);
// 	fv1.shrink_to_fit();
// 	print_container_compare(v1, fv1, true);

// 	// insert, fill, begin
// 	PRINT_W_COLOR(BOLD, "\ninserting multiple elements at the beginning");
// 	v1.insert(v1.begin(), 6, 21);
// 	fv1.insert(fv1.begin(), 6, 21);
// 	print_container_compare(v1, fv1, true);

// 	// insert, fill, in the middle
// 	PRINT_W_COLOR(BOLD, "\ninserting multiple elements in the middle");
// 	v1.insert(v1.begin() + 3, 6, 21);
// 	fv1.insert(fv1.begin() + 3, 6, 21);
// 	print_container_compare(v1, fv1, true);

// 	// insert, fill, end
// 	PRINT_W_COLOR(BOLD, "\ninserting multiple elements at the end");
// 	v1.insert(v1.end(), 6, 21);
// 	fv1.insert(fv1.end(), 6, 21);
// 	print_container_compare(v1, fv1, true);

// 	//resetting vector to initial state
// 	v1.assign(5, 42);
// 	v1.shrink_to_fit();
// 	fv1.assign(5, 42);
// 	fv1.shrink_to_fit();
// 	print_container_compare(v1, fv1, true);

// 	std::vector<int> example = createStdVectorInt(7);

// 	// insert, range, begin
// 	PRINT_W_COLOR(BOLD, "\ninserting another vector w iterators at the beginning");
// 	v1.insert(v1.begin(), example.begin(), example.end());
// 	fv1.insert(fv1.begin(), example.begin(), example.end());
// 	print_container_compare(v1, fv1, true);

// 	// insert, range, in the middle
// 	PRINT_W_COLOR(BOLD, "\ninserting another vector w iterators in the middle");
// 	v1.insert(v1.begin() + 3, example.begin(), example.end());
// 	fv1.insert(fv1.begin() + 3, example.begin(), example.end());
// 	print_container_compare(v1, fv1, true);

// 	// insert, range, end
// 	PRINT_W_COLOR(BOLD, "\ninserting another vector w iterators at the end");
// 	v1.insert(v1.end(), example.begin(), example.end());
// 	fv1.insert(fv1.end(), example.begin(), example.end());
// 	print_container_compare(v1, fv1, true);
// }

void vectorTestErase() {
	std::vector<int> v1 = createStdVectorInt(15);
	std::vector<int> tmp(5, 42);
	ft::vector<int> fv1 = createFtVectorInt(15);
	

	PRINT_W_COLOR(BOLD, "vector at the beginning");
	print_container_compare(v1, fv1);

	{
		PRINT_W_COLOR(BOLD, "\nerasing single element at the beginning");
		std::vector<int>::iterator it = v1.erase(v1.begin());
		ft::vector<int>::iterator fit= fv1.erase(fv1.begin());
		print_container_compare(v1, fv1);
		std::cout << "Return val - std: " << *it << std::endl;
		std::cout << "Return val -  ft: " << *fit << std::endl;
	}
	{
		PRINT_W_COLOR(BOLD, "\nerasing single element in the middle");
		std::vector<int>::iterator it = v1.erase(v1.begin() + 4);
		ft::vector<int>::iterator fit= fv1.erase(fv1.begin() + 4);
		print_container_compare(v1, fv1);
		std::cout << "Return val - std: " << *it << std::endl;
		std::cout << "Return val -  ft: " << *fit << std::endl;
	}
	{
		PRINT_W_COLOR(BOLD, "\nerasing single element at the end");
		std::vector<int>::iterator it = v1.erase(v1.end() - 1);
		ft::vector<int>::iterator fit= fv1.erase(fv1.end() - 1);
		print_container_compare(v1, fv1);
		std::cout << "Return val - std: " << *it << std::endl;
		std::cout << "Return val -  ft: " << *fit << std::endl;
	}
	{
		PRINT_W_COLOR(BOLD, "\nerasing multiple elements at the beginning");
		std::vector<int>::iterator it = v1.erase(v1.begin(), v1.begin() + 3);
		ft::vector<int>::iterator fit= fv1.erase(fv1.begin(), fv1.begin() + 3);
		print_container_compare(v1, fv1);
		std::cout << "Return val - std: " << *it << std::endl;
		std::cout << "Return val -  ft: " << *fit << std::endl;
	}
	{
		PRINT_W_COLOR(BOLD, "\nerasing multiple elements in the middle");
		std::vector<int>::iterator it = v1.erase(v1.begin() + 3, v1.begin() + 6);
		ft::vector<int>::iterator fit= fv1.erase(fv1.begin() + 3, fv1.begin() + 6);
		print_container_compare(v1, fv1);
		std::cout << "Return val - std: " << *it << std::endl;
		std::cout << "Return val -  ft: " << *fit << std::endl;
	}
	{
		PRINT_W_COLOR(BOLD, "\nerasing multiple elements at the end");
		std::vector<int>::iterator it = v1.erase(v1.end() - 3, v1.end());
		ft::vector<int>::iterator fit= fv1.erase(fv1.end() - 3, fv1.end());
		print_container_compare(v1, fv1);
		std::cout << "Return val - std: " << *it << std::endl;
		std::cout << "Return val -  ft: " << *fit << std::endl;
	}
}

void vectorTestResize() {
	std::vector<int> v1(7, 42);
	ft::vector<int> fv1(7, 42);

	PRINT_W_COLOR(BOLD, "vector at the beginning");
	print_container_compare(v1, fv1, true);

	v1.resize(4);
	fv1.resize(4);
	PRINT_W_COLOR(BOLD, "\nvector after resizing smaller than size");
	print_container_compare(v1, fv1, true);

	v1.resize(6, 34);
	fv1.resize(6, 34);
	PRINT_W_COLOR(BOLD, "\nvector after resizing bigger than size");
	print_container_compare(v1, fv1, true);

	v1.resize(v1.capacity() + 4, 89);
	fv1.resize(fv1.capacity() + 4, 89);
	PRINT_W_COLOR(BOLD, "\nvector after resizing bigger than capacity");
	print_container_compare(v1, fv1, true);
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
