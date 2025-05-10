##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

NAME    =   raytracer

RAYTRACER_SRC   =   $(shell find src/RayTracer -type f -name "*.cpp")
PARSER_SRC 		=	$(shell find src/Parser -type f -name "*.cpp")
RAYTRACER_OBJ   =   $(RAYTRACER_SRC:.cpp=.o)
PARSER_OBJ   =   $(PARSER_SRC:.cpp=.o)

ERROR_FLAGS =   -Werror -Wall -Wextra -Wpedantic
INCLUDES    =   -I src/RayTracer

CXXFLAGS    +=  $(ERROR_FLAGS) $(INCLUDES) -std=c++20

all: $(NAME)

$(NAME): LDFLAGS  += -lsfml-window -lsfml-system -lsfml-graphics -lconfig++
$(NAME): $(RAYTRACER_OBJ) $(PARSER_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

valgrind: CXXFLAGS	+= -g
valgrind: $(NAME)
	valgrind --leak-check=full --track-origins=yes ./$(NAME)

clean:
	find src/RayTracer -type f -name "*.o" -delete
	find src/Parser -type f -name "*.o" -delete

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
