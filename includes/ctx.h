#ifndef CTX_H
# define CTX_H
# include "scene.h"

typedef union	u_color
{
	unsigned int hex;
}				t_color;

typedef	struct	s_img
{
	int		width;
	int		height;
	void	*id;
	char	*data;
}				t_img;

typedef	struct	s_ctx
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_scene	*scene;
	int		timestamp;
	int		fps;
	int		frame;
	t_img	*canevas;
}				t_ctx;

int				close_fdf();

#endif
