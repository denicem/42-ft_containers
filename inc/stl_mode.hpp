#ifndef STL_MODE_HPP
#define STL_MODE_HPP

#ifndef STL
#define STL 1
#endif

#if STL //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif

#endif
