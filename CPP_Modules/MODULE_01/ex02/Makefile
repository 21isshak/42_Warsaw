# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 16:15:32 by iskaraag          #+#    #+#              #
#    Updated: 2025/07/10 16:26:44 by iskaraag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR = object
SRC_DIR = src
SRC = main.cpp
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = HI_THIS_IS_BRAIN

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
