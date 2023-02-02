#ifndef TEST_FUNCS_HPP
#define TEST_FUNCS_HPP

#include <iostream>
#include <string>

/* COLOURS */

# define RESET	"\e[0m"

/*--- MODES ---*/

# define BOLD		"\e[1m"
# define ITALIC		"\e[3m"
# define UNDERLINED	"\e[4m"

/*-- COLOURED FONT ---*/

# define RED			"\e[31m"
# define GREEN			"\e[32m"
# define YELLOW			"\e[33m"
# define BLUE			"\e[34m"
# define MAGENTA		"\e[35m"
# define CYAN			"\e[36m"
# define LIGHTGRAY		"\e[37m"
# define DARKGRAY		"\e[90m"
# define LIGHTRED		"\e[91m"
# define LIGHTGREEN		"\e[92m"
# define LIGHTYELLOW	"\e[93m"
# define LIGHTBLUE		"\e[94m"
# define LIGHTMAGENTA	"\e[95m"
# define LIGHTCYAN		"\e[96m"

/*--- COLOURED BACKGROUND ---*/

# define RED_BG				"\e[41m"
# define GREEN_BG			"\e[42m"
# define YELLOW_BG			"\e[43m"
# define BLUE_BG			"\e[44m"
# define MAGENTA_BG			"\e[45m"
# define CYAN_BG			"\e[46m"
# define LIGHTGRAY_BG		"\e[47m"
# define DARKGRAY_BG		"\e[100m"
# define LIGHTRED_BG		"\e[101m"
# define LIGHTGREEN_BG		"\e[102m"
# define LIGHTYELLOW_BG		"\e[103m"
# define LIGHTBLUE_BG		"\e[104m"
# define LIGHTMAGENTA_BG	"\e[105m"
# define LIGHTCYAN_BG		"\e[106m"

/*--- DEBUG PRINTER ---*/
# define PRINT_W_COLOR(color, text) \
{ \
	std::cout << color << text << RESET << std::endl; \
}

# define PRINT_LN std::cout << __FILE__ << ": " << __LINE__ << std::endl

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
		PRINT_W_COLOR(RED, "Function pointers are NULL.")
		return ;
	}


	std::cout << std::endl;
	std::cout << "*** STD ver ***" << std::endl;
	clock_t start_std = clock();
	func_std();
	clock_t end_std = clock();

	std::cout << "*** FT ver  ***" << std::endl;
	clock_t start_ft = clock();
	func_ft();
	clock_t end_ft = clock();

	double duration_std = static_cast<double>(end_std - start_std) / CLOCKS_PER_SEC;
	double duration_ft = static_cast<double>(end_ft - start_ft) / CLOCKS_PER_SEC;

	std::cout << std::endl;
	std::cout << "Duration std::vector:\t\t" << std::fixed << duration_std << " seconds." << std::endl;
	std::cout << "Duration ft::vector:\t\t" << std::fixed << duration_ft << " seconds." << std::endl;
	std::cout << std::endl;
	std::cout << "Duration std::vector * 20:\t" << std::fixed << duration_std * 20 << " seconds." << std::endl;
	std::cout << std::endl;

	if (duration_std * 20 > duration_ft) // NOTE: is that correct, if duration_ft can be 20x slower than duration_std
		PRINT_W_COLOR(GREEN, "SUCCESS")
	else
		PRINT_W_COLOR(RED, "FAIL")
}

#endif
