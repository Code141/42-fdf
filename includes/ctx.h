#ifndef CTX_H
# define CTX_H
# include "scene.h"

typedef	struct	s_img
{
	int		width;
	int		height;
	void	*id;
	char	*data;
}				t_img;

typedef	struct	s_screen
{
	void	*win;
	int		width;
	int		height;
	float	ar; //aspect ratio
	t_img	*canevas;
}				t_screen;

typedef	struct	s_ctx
{
	void		*mlx;
	t_screen	*screen;
	t_scene		*scene;
	int			timestamp;
	int			fps;
	int			frame;
}				t_ctx;

int				close_fdf();

#endif
