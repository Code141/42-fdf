
NAME =	FdF

LIBS =	-L./lib/mlx -lmlx			\
		-L./lib/libft -lft

INCS =	-I./lib/mlx/				\
		-I./lib/libft/includes/		\
		-I./includes/

SRCS =	./srcs/main.c				\
		./srcs/hooks.c				\
		./srcs/scene.c				\
		./srcs/object.c				\
		./srcs/geometry.c			\
		./srcs/material.c			\
		./srcs/draw.c

FMWS =	-framework OpenGL			\
		-framework AppKit

all: $(NAME)

$(NAME) : $(SRCS)
	gcc $(LIBS) $(INCS) $(FMWS) $(SRCS) -o $(NAME)

debug :
	gcc $(LIBS) $(INCS) $(FMWS) $(SRCS) -o $(NAME) -g -fsanitize=address

