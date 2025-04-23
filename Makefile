##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

all: raytracer

raytracer:
	make -C src/RayTracer
	mv src/RayTracer/raytracer .

clean:
	make clean -C src/RayTracer

fclean:
	make fclean -C src/RayTracer

re: fclean all
