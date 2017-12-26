#ifndef CTX_H
# define CTX_H
# include "scene.h"
# include "object.h"

# define PI 3.14159265
# define RAD PI / 180
# define TO_RAD(x) ((x) * PI / 180.0)
# define TO_DEG(x) ((x) * 180.0 / PI)

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

int				close_fdf(t_ctx *ctx);

#endif
