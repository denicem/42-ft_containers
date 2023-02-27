#ifndef EVAL_VECTOR_TEST_HPP
#define EVAL_VECTOR_TEST_HPP

#include "stl_mode.hpp"
#include "test_general.hpp"
#include "Vect3.hpp"

#ifndef ELEMENTS
#define ELEMENTS 10000
#endif

#include <iostream>

template < typename T >
static void printVector(ft::vector<T>& v) {
	for (typename ft::vector<T>::size_type i = 0; i < v.size(); ++i)
			std::cout << v[i] << " ";
		std::cout << std::endl;
}

static ft::vector<int> createVectorInt(unsigned size) {
	ft::vector<int> res;

	for (unsigned i = 0; i < size; i++)
		res.push_back(i);

	return (res);
}

void test_vector_default_ctor() {
	std::cout << " -- BEGIN " << __func__ << " -- " << std::endl;

	ft::vector<int> int_v;
	std::cout << "Int vector size: " << int_v.size() << std::endl;

	for (int i = 0; i < ELEMENTS; ++i)
		int_v.push_back(rand() % 1000);
	std::cout << "Int vector size after push_back()s: " << int_v.size() << std::endl;

	std::cout << "Printing elements with const_iterator: " << std::endl;
	ft::vector<int>::const_iterator it = int_v.begin();
	ft::vector<int>::const_iterator ite = int_v.end();
	for (; it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Printing elements with const_reverse_iterator: " << std::endl;
	ft::vector<int>::const_reverse_iterator rit = int_v.rbegin();
	ft::vector<int>::const_reverse_iterator rite = int_v.rend();
	for (; rit != rite; ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;

	for (int i = 0; i < ELEMENTS / 2 && !int_v.empty(); ++i)
		int_v.pop_back();
	std::cout << "Int vector size after pop_back()s: " << int_v.size() << std::endl;
	std::cout << "Empty: " << int_v.empty() << std::endl;

	int_v.clear();
	std::cout << "Int vector size after clear(): " << int_v.size() << std::endl;
	std::cout << "Empty: " << int_v.empty() << std::endl;

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

void test_vector_fill_ctor() {
	std::cout << " -- BEGIN " << __func__ << " -- " << std::endl;

	ft::vector<int> int_v(ELEMENTS, 42);
	std::cout << "Int vector size: " << int_v.size() << std::endl;

	// std::cout << "Printing elements with const_iterator: " << std::endl;
	// ft::vector<int>::const_iterator it = int_v.begin();
	// ft::vector<int>::const_iterator ite = int_v.end();
	// for (; it != ite; ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

	int_v.clear();
	std::cout << "Int vector size after clear(): " << int_v.size() << std::endl;
	std::cout << "Empty: " << int_v.empty() << std::endl;

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

void test_vector_range_ctor() {
	std::cout << " -- BEGIN " << __func__ << " -- " << std::endl;
	ft::vector<int> range_v;
	for (int i = 0; i < ELEMENTS / 2; ++i)
		range_v.push_back(rand() % 1000);
	ft::vector<int>::const_iterator range_it = range_v.begin();
	ft::vector<int>::const_iterator range_ite = range_v.end();

	ft::vector<int> int_v(range_it, range_ite);
	std::cout << "Int vector size: " << int_v.size() << std::endl;

	int_v.clear();
	std::cout << "Int vector size after clear(): " << int_v.size() << std::endl;
	std::cout << "Empty: " << int_v.empty() << std::endl;

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

void test_vector_copy_ctor() {
	std::cout << " -- BEGIN " << __func__ << " -- " << std::endl;

	ft::vector<int> copy_v;
	for (int i = 0; i < ELEMENTS / 2; ++i)
		copy_v.push_back(rand() % 1000);

	ft::vector<int> int_v(copy_v);
	std::cout << "Int vector size: " << int_v.size() << std::endl;

	if (int_v == copy_v)
		std::cout << "Vectors are equal!" << std::endl;
	else
		std::cout << "Vectors are NOT equal!" << std::endl;

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

void test_vector_assignment_operator() {
	std::cout << " -- BEGIN " << __func__ << " -- " << std::endl;

	ft::vector<int> copy_v;
	for (int i = 0; i < ELEMENTS / 2; ++i)
		copy_v.push_back(rand() % 1000);

	ft::vector<int> int_v = copy_v;
	std::cout << "Int vector size: " << int_v.size() << std::endl;

	if (int_v == copy_v)
		std::cout << "Vectors are equal!" << std::endl;
	else
		std::cout << "Vectors are NOT equal!" << std::endl;

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

void test_vector_iterators() {
	std::cout << " -- BEGIN " << __func__ << " -- " << std::endl;

	ft::vector<int> int_v = createVectorInt(10);
	printVector(int_v);

	ft::vector<int>::iterator it = int_v.begin();
	ft::vector<int>::iterator ite = int_v.end();
	*it = 42;
	std::cout << "Iterators: begin() = " << *it << ", end() = " << *ite << std::endl;

	ft::vector<int>::const_iterator cit = int_v.begin();
	ft::vector<int>::const_iterator cite = int_v.end();
	// *cit = 21;
	std::cout << "Iterators: const begin() = " << *cit << ", const end() = " << *cite << std::endl;

	ft::vector<int>::reverse_iterator rit = int_v.rbegin();
	ft::vector<int>::reverse_iterator rite = int_v.rend();
	*rit = 42;
	std::cout << "Iterators: rbegin() = " << *rit << ", rend() = " << *rite << std::endl;

	ft::vector<int>::const_reverse_iterator crit = int_v.rbegin();
	ft::vector<int>::const_reverse_iterator crite = int_v.rend();
	// *crit = 21;
	std::cout << "Iterators: const rbegin() = " << *crit << ", const rend() = " << *crite << std::endl;
	
	for (ft::vector<int>::size_type i = 0; i < int_v.size(); ++i)
		std::cout << int_v[i] << " ";
	std::cout << std::endl;

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

void test_vector_capacity() {
	std::cout << " -- BEGIN " << __func__ << " -- " << std::endl;

	ft::vector<int> int_v = createVectorInt(10);
	printVector(int_v);

	std::cout << "size() = " << int_v.size() << std::endl;
	std::cout << "empty() = " << int_v.empty() << std::endl;
	std::cout << "capacity() = " << int_v.capacity() << std::endl;
	std::cout << "max_size() = " << int_v.max_size() << std::endl;

	int_v.resize(int_v.size() + 5);
	std::cout << "size() after resize() = " << int_v.size() << std::endl;
	std::cout << "capacity() after resize() = " << int_v.capacity() << std::endl;

	int_v.reserve(int_v.size() + 5);
	std::cout << "size() after reserve() = " << int_v.size() << std::endl;
	std::cout << "capacity() after reserve() = " << int_v.capacity() << std::endl;
	
	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

void test_vector_element_access() {
	std::cout << " -- BEGIN " << __func__ << " -- " << std::endl;

	ft::vector<int> int_v = createVectorInt(10);
	printVector(int_v);
	std::cout << "size() = " << int_v.size() << std::endl;
	std::cout << "capacity() = " << int_v.capacity() << std::endl << std::endl;

	std::cout << "operator[]() = " << int_v[0] << std::endl;
	std::cout << "at() = " << int_v.at(0) << std::endl;
	try {
		std::cout << "at() out of range? " << int_v.at(15) << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "front() = " << int_v.front() << std::endl;
	std::cout << "back() = " << int_v.back() << std::endl;
	std::cout << "data() = " << int_v.data() << std::endl;
	
	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

void test_vector_modifiers() {
	std::cout << " -- BEGIN " << __func__ << " -- " << std::endl;

	ft::vector<int> tmp = createVectorInt(20);

	ft::vector<int> int_v = createVectorInt(10);
	printVector(int_v);
	std::cout << "size() = " << int_v.size() << std::endl;
	std::cout << "capacity() = " << int_v.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "* ASSIGN *" << std::endl;

	int_v.assign(5, 42);
	std::cout << "vector after fill assign():" << std::endl;
	printVector(int_v);
	int_v.assign(tmp.begin(), tmp.end());
	std::cout << "vector after range assign():" << std::endl;
	printVector(int_v);
	std::cout << std::endl;
	
	std::cout << "* INSERT *" << std::endl;
	int_v.insert(int_v.begin(), 42); // insert begin
	int_v.insert(int_v.end(), 21); // insert end
	int_v.insert(int_v.begin() + (int_v.size() / 2), 420); //insert middle
	std::cout << "vector after single insert():" << std::endl;
	printVector(int_v);
	int_v.insert(int_v.begin(), 2, 5050); // insert begin
	int_v.insert(int_v.end(), 2, 5050); // insert end
	int_v.insert(int_v.begin() + (int_v.size() / 2), 2, 5050); //insert middle
	std::cout << "vector after fill insert():" << std::endl;
	printVector(int_v);
	int_v.insert(int_v.begin(), tmp.begin(), tmp.begin() + 7); // insert begin
	int_v.insert(int_v.end(), tmp.begin(), tmp.begin() + 7); // insert end
	int_v.insert(int_v.begin() + (int_v.size() / 2), tmp.begin(), tmp.begin() + 7); //insert middle
	std::cout << "vector after range insert():" << std::endl;
	printVector(int_v);
	std::cout << std::endl;

	std::cout << "* ERASE *" << std::endl;
	int_v.erase(int_v.begin());
	int_v.erase(int_v.end() - 1);
	std::cout << "vector after single erase()s at the beginning and end:" << std::endl;
	printVector(int_v);
	int_v.erase(int_v.begin() + (int_v.size() / 2), int_v.end() - 1);
	std::cout << "vector after range erase():" << std::endl;
	printVector(int_v);
	std::cout << std::endl;

	std::cout << "* SWAP *" << std::endl;
	{
		ft::vector<int> a = createVectorInt(7);
		ft::vector<int> b(3, 42);

		std::cout << "a = ";
		printVector(a);
		std::cout << "b = ";
		printVector(b);

		std::cout << "swapping..." << std::endl;
		swap(a, b);

		std::cout << "a = ";
		printVector(a);
		std::cout << "b = ";
		printVector(b);
	}

	std::cout << " --  END " << __func__ << " -- " << std::endl;
}

#endif
