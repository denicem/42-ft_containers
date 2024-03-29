# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 01:48:13 by dmontema          #+#    #+#              #
#    Updated: 2023/02/26 21:18:53 by dmontema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_containers
STD_OUT	=	std.out
FT_OUT	=	ft.out

CC			=	c++

SRC_DIR	=		./src
SRCS	=		$(shell find $(SRC_DIR) -name "*.cpp")
TEST_SRC_DIR	=	./tester
TEST_SRCS		=	$(shell find $(TEST_SRC_DIR) -name "*.cpp")

OBJ_DIR	=		./obj
OBJS	=		$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRCS))
TEST_OBJ_DIR	=		./test_obj
TEST_OBJS	=	$(patsubst $(TEST_SRC_DIR)%.cpp, $(TEST_OBJ_DIR)%.o, $(TEST_SRCS))

DEPS	=		$(OBJS:.o=.d)

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 #-g
DEPS_FLAGS 	=	-MMD -MP
INCLUDE		=	-I./inc/

SEED = 213

# **************************************************************************** #
#	RULES																	   #
# **************************************************************************** #

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS)
	@printf "$(BLUE)Linking objects to a binary file$(RESET)\r"
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)
	@printf "$(SPACE)$(GREEN)[✓]\n$(RESET)"
	@printf "\t\t$(GREEN)$(BOLD)COMPLETE!$(RESET)\n\n"
	@printf "\t\t$(MAGENTA)Name of executable: $(BOLD)$(MAGENTA_BG) $(NAME) $(RESET)\n\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@printf "$(BLUE)$(BOLD)\rCompiling: $(CYAN)$(notdir $<)\r"
	@$(CC) $(CFLAGS) $(INCLUDE) $(DEPS_FLAGS) -c $< -o $@
	@printf "$(SPACE)$(GREEN)[✓]\n$(RESET)"

test: $(TEST_SRC_DIR) #$(TEST_OBJS)
	@printf "$(BLUE)Linking objects to two binary files.$(RESET)\r"
# @$(CC) $(CFLAGS) $(INCLUDE) $(TEST_OBJS) -o $(STD_OUT)
	@$(CC) $(CFLAGS) $(INCLUDE) $(TEST_SRCS) -o $(STD_OUT)
# @$(CC) $(CFLAGS) $(INCLUDE) -D STL=0 $(TEST_OBJS) -o $(FT_OUT)
	@$(CC) $(CFLAGS) $(INCLUDE) -D STL=0 $(TEST_SRCS) -o $(FT_OUT)
	@printf "$(SPACE)$(GREEN)[✓]\n$(RESET)"
	@printf "\t\t$(GREEN)$(BOLD)COMPLETE!$(RESET)\n\n"
	@printf "\t\t$(MAGENTA)Name of executables: $(BOLD)$(MAGENTA_BG) $(STD_OUT) and $(FT_OUT) $(RESET)\n\n"
	@make diff

diff: $(STD_OUT) $(FT_OUT)
	@printf "$(BLUE)Executing std executable.$(RESET)\r"
	@printf "$(SPACE)$(GREEN)[✓]\n$(RESET)"
	@./$(STD_OUT) $(SEED) > std_out.txt
	@printf "$(BLUE)Executing ft executable.$(RESET)\r"
	@printf "$(SPACE)$(GREEN)[✓]\n$(RESET)"
	@./$(FT_OUT) $(SEED) > ft_out.txt
	@printf "$(BLUE)Creating diff file...$(RESET)\r"
	@printf "$(SPACE)$(GREEN)[✓]\n$(RESET)"
	@diff std_out.txt ft_out.txt > $(NAME).diff; [ $$? -eq 1 ]
	@printf "\t\t$(GREEN)$(BOLD)COMPLETE!$(RESET)\n\n"
	@printf "\t\t$(MAGENTA)Check out diff file: $(BOLD)$(MAGENTA_BG) $(NAME).diff $(RESET)\n\n"

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@printf "$(BLUE)$(BOLD)\rCompiling: $(CYAN)$(notdir $<)\r"
	@$(CC) $(CFLAGS) $(INCLUDE) $(DEPS_FLAGS) -c $< -o $@
	@printf "$(SPACE)$(GREEN)[✓]\n$(RESET)"

# prep:
# 	@mkdir -p $(OBJ_DIR)

clean:
	@printf "$(MAGENTA)Removing object files...\r$(RESET)"
	@rm -rf $(OBJS) $(OBJ_DIR)
	@rm -rf $(TEST_OBJS) $(TEST_OBJ_DIR)
	@rm -rf std_out.txt ft_out.txt ft_containers.diff
	@printf "$(SPACE)$(GREEN)[✓]\n$(RESET)"

fclean: clean
	@printf "$(MAGENTA)Removing binary file...\r$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(STD_OUT) $(FT_OUT)
	@printf "$(SPACE)$(GREEN)[✓]\n$(RESET)\n"

re: fclean all
re_test: fclean test

# **************************************************************************** #
#	TEXT MODIFIERS / FORMATITING CODES										   #
# **************************************************************************** #

RED =				\e[31m
GREEN =				\e[32m
YELLOW =			\e[33m
BLUE =				\e[34m
MAGENTA =			\e[35m
CYAN =				\e[36m
LIGHTGRAY =			\e[37m
DARKGRAY =			\e[90m
LIGHTRED =			\e[91m
LIGHTGREEN =		\e[92m
LIGHTYELLOW =		\e[93m
LIGHTBLUE =			\e[94m
LIGHTMAGENTA =		\e[95m
LIGHTCYAN =			\e[96m
RED_BG =			\e[41m
GREEN_BG =			\e[42m
YELLOW_BG =			\e[43m
BLUE_BG =			\e[44m
MAGENTA_BG =		\e[45m
CYAN_BG =			\e[46m
LIGHTGRAY_BG =		\e[47m
DARKGRAY_BG =		\e[100m
LIGHTRED_BG =		\e[101m
LIGHTGREEN_BG =		\e[102m
LIGHTYELLOW_BG =	\e[103m
LIGHTBLUE_BG =		\e[104m
LIGHTMAGENTA_BG =	\e[105m
LIGHTCYAN_BG =		\e[106m
BOLD =				\e[1m
ITALIC =			\e[3m
UNDERLINED =		\e[4m
RESET =				\e[0m
SPACE =				\e[50C