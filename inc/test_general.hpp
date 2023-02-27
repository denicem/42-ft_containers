#ifndef TEST_FUNCS_HPP
#define TEST_FUNCS_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>

#include "format_codes.hpp"

#include "stl_mode.hpp"

#define ELEMENTS 10000

/* ----------------------------- debug printers ----------------------------- */
# define PRINT_W_COLOR(color, text) std::cout << color << text << RESET << std::endl
# define PRINT_POS std::cout << __FILE__ << ": " << __LINE__ << std::endl

/* ---------------------------- redefining assert --------------------------- */
#undef assert
#define assert(e, succ_msg) (e ? (succ_msg ? __assert_success(#e, __FILE__, __LINE__) : void() ) : __assert_fail(#e, __FILE__, __LINE__))
#define __assert_fail(e, file, line) (std::cout << "Testing " << UNDERLINED << e << RESET << RED << " failed " << RESET << BOLD << "@ " << file << ":" << line << RESET << std::endl, void())
#define __assert_success(e, file, line) (std::cout << "Testing " << UNDERLINED << e << RESET << GREEN << " passed " << RESET << BOLD << "@ " << file << ":" << line << RESET << std::endl, void())

#define PRINT_TIMING(func) \
{ \
	clock_t t; \
	t = clock(); \
	func; \
	t = clock() - t; \
	double tt = ((double)(t) / CLOCKS_PER_SEC); \
	std::cout << #func << ": " << tt << "s" << std::endl; \
}

void playground() {
	ft::vector<char> v;
	v.push_back('H');
	v.push_back('e');
	v.push_back('l');
	v.push_back('l');
	v.push_back('o');

	for (ft::vector<char>::size_type i = 0; i < v.size(); ++i)
		std::cout << v[i];
	std::cout << std::endl;

}

#endif
