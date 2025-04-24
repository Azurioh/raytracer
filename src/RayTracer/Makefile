##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

SRC = $(shell find . -type f -name "*.cpp")
OBJ = $(SRC:.cpp=.o)

ERROR_FLAGS	=	-Werror -Wall -Wextra -Wpedantic
INCLUDES	=	-I .
LDLIBS		+=	-lsfml-window -lsfml-system -lsfml-graphics
CXXFLAGS += $(ERROR_FLAGS) $(INCLUDES) -std=c++20 -g

NAME = binary

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

clean:
	find . -type f -name '*.o' -delete

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all $(NAME) clean fclean re
