##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

NAME    =   raytracer

RAYTRACER_SRC   =   $(shell find src/RayTracer -type f -name "*.cpp")
RAYTRACER_OBJ   =   $(RAYTRACER_SRC:.cpp=.o)

ERROR_FLAGS =   -Werror -Wall -Wextra -Wpedantic
INCLUDES    =   -I src/RayTracer

CXXFLAGS    +=  $(ERROR_FLAGS) $(INCLUDES) -std=c++20

all: $(NAME)

$(NAME): LDFLAGS  += -lsfml-window -lsfml-system -lsfml-graphics
$(NAME): $(RAYTRACER_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

valgrind: CXXFLAGS	+= -g
valgrind: $(NAME)
	valgrind --leak-check=full --track-origins=yes ./$(NAME)

clean:
	find src/RayTracer -type f -name "*.o" -delete

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
