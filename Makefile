
NAME	=	FdF

CC		=	gcc
CFLAGS	=	#-Wall -Wextra -Werror
CFLAGS	+=	$(INCS)

LIBS	=	-L./lib/mlx -lmlx			\
			-L./lib/libft -lft

INCS	=	-I./lib/mlx/				\
			-I./lib/libft/includes/		\
			-I./includes/

SRCS	=	./srcs/main.c				\
			./srcs/hooks.c				\
			./srcs/pixel.c				\
			./srcs/vector.c				\
			./srcs/scene.c				\
			./srcs/camera.c				\
			./srcs/mesh.c				\
			./srcs/geometry.c			\
			./srcs/material.c			\
			./srcs/hud.c				\
			./srcs/draw.c

OBJS	=	$(SRCS:.c=.o)

FMWS	=	-framework OpenGL			\
			-framework AppKit

all		: $(NAME)

$(NAME) : $(OBJS)
	gcc $(LIBS) $(FMWS) $(OBJS) -o $(NAME)

clean	:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)
	cd ./lib/libft $(MAKE) fclean
	cd ./lib/mlx $(MAKE) clean
re:
	$(MAKE) $(MFLAGS) fclean
	$(MAKE) $(MFLAGS) all

.PHONY: all clean fclean re

########################################################################
fsanitize :
	gcc $(LIBS) $(INCS) $(FMWS) $(SRCS) -o $(NAME) -g -fsanitize=address
g :
	gcc $(LIBS) $(INCS) $(FMWS) $(SRCS) -o $(NAME) -g
