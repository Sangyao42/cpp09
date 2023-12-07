NAME := RPN
CC := c++
CPPFLAGS := -std=c++98 -Wall -Wextra -Werror
CPPFLAGS += -fsanitize=address
# DIRECTIVRS := -D TEST

SRC_DIR := src
OBJ_DIR := obj
HEADER_DIR := include

SRCS := main.cpp
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all : $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) $(DIRECTIVRS) $(addprefix -I ,$(HEADER_DIR)) -c $^ -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

run :
	$(MAKE) re
	./$(NAME)

.phony: all clean fclean re run