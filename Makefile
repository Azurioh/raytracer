##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

NAME	=	raytracer

.PHONY: all raytracer clean fclean re

all: raytracer

raytracer:
	make -C src/RayTracer
	mv src/RayTracer/binary ./raytracer

clean:
	make clean -C src/RayTracer

fclean:
	make fclean -C src/RayTracer
	rm -rf $(NAME)

re: fclean all
