SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "\033[1;35mmake: DONE!\033[0m"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)
	@echo "\033[1;33mcleane: DONE!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;33mfcleane: DONE!\033[0m"

re: fclean all
.PHONY: all clean fclean re