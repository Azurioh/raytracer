##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

SRC = $(shell find src -type f -name "*.cpp")
OBJ = $(SRC:.cpp=.o)

CXXFLAGS += -std=c++20 -g -Wall -Wextra -Wpedantic -I include -I src

NAME = raytracer

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

clean:
	find src -type f -name '*.o' -delete

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all client server clean fclean re
