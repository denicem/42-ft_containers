/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:27:59 by dmontema          #+#    #+#             */
/*   Updated: 2023/02/26 22:13:59 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vect3.hpp"
#include "test_general.hpp"

#include <iostream>

#include "stl_mode.hpp"

#include "eval_vector_test.hpp"
#include "eval_map_test.hpp"

int main(int argc, char* argv[]) {
	if (argc > 1)
		srand(atoi(argv[1]));
	if (STL)
		std::cout << "STD version" << std::endl << std::endl;
	else if (!STL)
		std::cout << "FT version" << std::endl << std::endl;

	PRINT_TIMING(test_vector_default_ctor());
	PRINT_TIMING(test_vector_fill_ctor());
	PRINT_TIMING(test_vector_range_ctor());
	// PRINT_TIMING(test_map());

	return (0);
}





// #include <iostream>
// #include <string>
// #include <deque>

// #ifndef STL
// #define STL 1
// #endif

// #if STL //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include "../inc/map.hpp"
// 	#include "../inc/stack.hpp"
// 	#include "../inc/vector.hpp"
// #endif

// // #include <stdlib.h>

// // #define MAX_RAM 4294967296
// // #define BUFFER_SIZE 4096
// // struct Buffer
// // {
// // 	int idx;
// // 	char buff[BUFFER_SIZE];
// // };


// // #define CNT (MAX_RAM / (int)sizeof(Buffer))

// // template<typename T>
// // class MutantStack : public ft::stack<T>
// // {
// // public:
// // 	MutantStack() {}
// // 	MutantStack(const MutantStack<T>& src) { *this = src; }
// // 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// // 	{
// // 		this->c = rhs.c;
// // 		return *this;
// // 	}
// // 	~MutantStack() {}

// // 	typedef typename ft::stack<T>::container_type::iterator iterator;

// // 	iterator begin() { return this->c.begin(); }
// // 	iterator end() { return this->c.end(); }
// // };

// // int main(int argc, char** argv) {
// // 	if (argc != 2)
// // 	{
// // 		std::cerr << "Usage: ./test seed" << std::endl;
// // 		std::cerr << "Provide a seed please" << std::endl;
// // 		std::cerr << "Count value:" << CNT << std::endl;
// // 		return 1;
// // 	}
// // 	const int seed = atoi(argv[1]);
// // 	srand(seed);

// // 	ft::vector<std::string> vector_str;
// // 	ft::vector<int> vector_int;
// // 	ft::stack<int> stack_int;
// // 	ft::vector<Buffer> vector_buffer;
// // 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// // 	ft::map<int, int> map_int;

// // 	for (int i = 0; i < CNT; i++)
// // 	{
// // 		vector_buffer.push_back(Buffer());
// // 	}

// // 	for (int i = 0; i < CNT; i++)
// // 	{
// // 		const int idx = rand() % CNT;
// // 		vector_buffer[idx].idx = 5;
// // 	}
// // 	ft::vector<Buffer>().swap(vector_buffer);

// // 	try
// // 	{
// // 		for (int i = 0; i < CNT; i++)
// // 		{
// // 			const int idx = rand() % CNT;
// // 			vector_buffer.at(idx);
// // 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// // 		}
// // 	}
// // 	catch(const std::exception& e)
// // 	{
// // 		//NORMAL ! :P
// // 	}
	
// // 	for (int i = 0; i < CNT; ++i)
// // 	{
// // 		map_int.insert(ft::make_pair(rand(), rand()));
// // 	}

// // 	int sum = 0;
// // 	for (int i = 0; i < 10000; i++)
// // 	{
// // 		int access = rand();
// // 		sum += map_int[access];
// // 	}
// // 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// // 	{
// // 		ft::map<int, int> copy = map_int;
// // 	}
// // 	MutantStack<char> iterable_stack;
// // 	for (char letter = 'a'; letter <= 'z'; letter++)
// // 		iterable_stack.push(letter);
// // 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// // 	{
// // 		std::cout << *it;
// // 	}
// // 	std::cout << std::endl;
// // 	return (0);
// // }