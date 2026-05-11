# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 21:04:31 by iskaraag          #+#    #+#              #
#    Updated: 2025/07/28 22:59:15 by iskaraag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR = objects
SRC_DIR = srcs
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = ScavTrap

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[1;35mmake: DONE!\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
				@$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;33mcleane: DONE!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;33mfcleane: DONE!\033[0m"

re: fclean all
.PHONY: all clean fclean re