#ifndef SCREEN_H
# define SCREEN_H

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

t_img	*new_canevas(void *mlx, int width, int height);
t_screen	*new_screen(void *mlx, int width, int height);

#endif
