# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 15:45:56 by iskaraag          #+#    #+#              #
#    Updated: 2025/07/16 17:32:01 by iskaraag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR = objects
SRC_DIR = srcs
SRCS = main.cpp error_handlers.cpp
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = replace

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[1;35mmake: DONE!\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
				$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;33mclean: DONE!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;33mfclean: DONE!\033[0m"

allclean: clean fclean
	@rm -f $(NAME)
	@echo "\033[1;33mallclean: DONE!\033[0m"
	@rm -f *.replace
	@rm -f test_file
	
test1:
	./replace
	
test2:
	@echo "Hello world. What a beatiful world" > test_file
	./replace test_file world world

test3:
	@echo "Hello world. What a beatiful world" > test_file
	./replace test_file world 42warsaw

re: fclean all
.PHONY: all clean fclean re
