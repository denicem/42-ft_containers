#ifndef TEST_FUNCS_HPP
#define TEST_FUNCS_HPP

#include <iostream>
#include <string>
#include <exception>

#include "format_codes.hpp"

/* ----------------------------- debug printers ----------------------------- */
# define PRINT_W_COLOR(color, text) std::cout << color << text << RESET << std::endl
# define PRINT_POS std::cout << __FILE__ << ": " << __LINE__ << std::endl

/* ---------------------------- redefining assert --------------------------- */
#undef assert
#define assert(e, succ_msg) (e ? (succ_msg ? __assert_success(#e, __FILE__, __LINE__) : void() ) : __assert_fail(#e, __FILE__, __LINE__))
#define __assert_fail(e, file, line) (std::cout << "Testing " << UNDERLINED << e << RESET << RED << " failed " << RESET << BOLD << "@ " << file << ":" << line << RESET << std::endl, void())
#define __assert_success(e, file, line) (std::cout << "Testing " << UNDERLINED << e << RESET << GREEN << " passed " << RESET << BOLD << "@ " << file << ":" << line << RESET << std::endl, void())

// #define TIME(func) 

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void pointer_func(const int* p, std::size_t size) // test func for data() method.
{
    std::cout << "data = ";
    for (std::size_t i = 0; i < size; ++i)
        std::cout << p[i] << ' ';
    std::cout << '\n';
}

void measureTime(void (*func_std)(), void (*func_ft)()) {
	if (func_std == NULL || func_ft == NULL) {
		PRINT_W_COLOR(RED, "Function pointers are NULL.");
		return ;
	}

	std::cout << std::endl;
	// std::cout << "*** STD ver ***" << std::endl;
	clock_t start_std = clock();
	func_std();
	clock_t end_std = clock();

	// std::cout << "*** FT ver  ***" << std::endl;
	clock_t start_ft = clock();
	func_ft();
	clock_t end_ft = clock();

	double duration_std = static_cast<double>(end_std - start_std) / CLOCKS_PER_SEC;
	double duration_ft = static_cast<double>(end_ft - start_ft) / CLOCKS_PER_SEC;

	std::cout << std::endl;
	std::cout << "Duration std:: :\t\t" << std::fixed << duration_std << " seconds." << std::endl;
	std::cout << "Duration ft::  :\t\t" << std::fixed << duration_ft << " seconds." << std::endl;
	std::cout << std::endl;
	std::cout << "Duration std:: * 20:\t\t" << std::fixed << duration_std * 20 << " seconds." << std::endl;
	std::cout << std::endl;

	// if (duration_std * 20 > duration_ft) // NOTE: is that correct, if duration_ft can be 20x slower than duration_std
	// 	PRINT_W_COLOR(GREEN, "SUCCESS");
	// else
	// 	PRINT_W_COLOR(RED, "FAIL");
	assert(duration_std * 20 > duration_ft, true);
}

template <typename Container>
void print_container(const Container& c, bool print_info = false) {
	typename Container::const_iterator it;
	for (it = c.begin(); it != c.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	if (print_info) {
		std::cout << "Size: " << c.size() << std::endl;
		std::cout << "Capacity: " << c.capacity() << std::endl;
	} 
}

template <typename Container>
void print_container_info(const Container& c) {
	std::cout << "Size: " << c.size() << std::endl;
	std::cout << "Capacity: " << c.capacity() << std::endl;
}

template <typename Container1, typename Container2>
void print_container_compare(const Container1& std_c, const Container2& ft_c, bool print_info = false) {
	PRINT_W_COLOR(LIGHTGREEN, "----- CONTAINER COMPARE -----") << std::endl;
	
	PRINT_W_COLOR (LIGHTYELLOW, "STD");
	PRINT_W_COLOR (LIGHTMAGENTA, "FT") << std::endl;

	std::cout << LIGHTYELLOW;
	if (!std_c.empty()) {
		typename Container1::const_iterator std_it;
		for (std_it = std_c.begin(); std_it != std_c.end(); ++std_it)
			std::cout << *std_it << " ";
	}
	else std::cout << "EMPTY.";
	std::cout << RESET;
	std::cout << std::endl;

	std::cout << LIGHTMAGENTA;
	if (!ft_c.empty()) {
		typename Container2::const_iterator ft_it;
		for (ft_it = ft_c.begin(); ft_it != ft_c.end(); ++ft_it)
			std::cout << *ft_it << " ";
	}
	else std::cout << "EMPTY.";
	std::cout << RESET;
	std::cout << std::endl << std::endl;;

	if (print_info) {
		std::cout << LIGHTYELLOW << "Size:\t" << std_c.size() << RESET << std::endl;
		std::cout << LIGHTMAGENTA << "Size:\t" << ft_c.size() << RESET << std::endl;
		std::cout << LIGHTYELLOW << "Capacity:\t" << std_c.capacity() << RESET << std::endl;
		std::cout << LIGHTMAGENTA << "Capacity:\t" << ft_c.capacity() << RESET << std::endl;
		std::cout << std::endl;
	}
	
	PRINT_W_COLOR(GREEN, "----- CONTAINER COMPARE -----");
}

#endif
