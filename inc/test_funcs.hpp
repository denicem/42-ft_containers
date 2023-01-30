#ifndef TEST_FUNCS_HPP
#define TEST_FUNCS_HPP

#include <string>
#include <iostream>

void pointer_func(const int* p, std::size_t size) // test func for data() method.
{
    std::cout << "data = ";
    for (std::size_t i = 0; i < size; ++i)
        std::cout << p[i] << ' ';
    std::cout << '\n';
}

#endif
