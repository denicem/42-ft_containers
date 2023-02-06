#ifndef FT_ASSERT_HPP
#define FT_ASSERT_HPP

#include <exception>
#include <iostream>

namespace ft {

struct AssertException: public std::exception {\
	AssertException() {}
	const char* what() const throw() {
		return ("");
	}
};


// TODO: Assertion failed: (v1.size() != fv1.size()), function main, file src/main.cpp, line 38. -> assertion failed msg! Red color
#undef assert
#undef __assert
#define assert(e, succ_msg) (e ? (succ_msg ? __assert_succ_msg(#e, __FILE__, __LINE__) : void() ) : __assert(#e, __FILE__, __LINE__))
#define __assert(e, file, line) (std::cout << file << ":" << line << ": failed assertion with case: " << e << " in func " << __func__ << std::endl, throw ft::AssertException())
#define __assert_succ_msg(e, file, line) (std::cout << file << ":" << line << ": succesful assertion with case: " << e << std::endl, void())

} // END NAMESPACE FT

#endif

