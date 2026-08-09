OBJ_DIR = objects
SRCS_DIR = srcs
SRCS = main.cpp PmergeMe.cpp
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[1;35mmake: DONE!\033[0m"

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJ_DIR)
				@$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;33mclean: DONE!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;33mfclean: DONE!\033[0m"

re: fclean all
	@echo "\033[1;34mre: DONE!\033[0m"

trim:
	@echo "\033[1;36mYou are seeing first 20 characters of Before & After and Times\033[0m"
	@sed -E 's/(Before|After)(: .{20}).*/\1\2 [...]/'

.PHONY: all clean fclean re