#ifndef CTX_H
# define CTX_H
# include "scene.h"

typedef	struct	s_ctx
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_scene	*scene;
}				t_ctx;

#endif
