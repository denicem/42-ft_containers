# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 01:48:13 by dmontema          #+#    #+#              #
#    Updated: 2022/11/15 01:48:23 by dmontema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_containers

CC			=	c++

SRC_DIR	=		./src
SRCS	=		$(shell find $(SRC_DIR) -name "*.cpp")

OBJ_DIR	=		./obj
OBJS	=		$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRCS))

DEPS	=		$(OBJS:.o=.d)

CFLAGS		=	-Wall -Wextra -Werror -std=c++98
DEPS_FLAGS 	=	-MMD -MP
INCLUDE		=	-I./inc/

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

# prep:
# 	@mkdir -p $(OBJ_DIR)

clean:
	@printf "$(MAGENTA)Removing object files...\r$(RESET)"
	@rm -rf $(OBJS) $(OBJ_DIR)
	@printf "$(SPACE)$(GREEN)[✓]\n$(RESET)"

fclean: clean
	@printf "$(MAGENTA)Removing binary file...\r$(RESET)"
	@rm -rf $(NAME)
	@printf "$(SPACE)$(GREEN)[✓]\n$(RESET)\n"

re: fclean all

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