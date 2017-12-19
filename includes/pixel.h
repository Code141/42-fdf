#ifndef PIXEL_H
# define PIXEL_H
# include "ctx.h"

typedef union	u_pix
{
	unsigned int	i;
	struct			s_c
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	}					c;
}				t_pix;

void	put_pixel(t_img *canevas, int x, int y, int color);
void	draw_point(t_img *canevas, t_vector2 v, int size, int color);
void	draw_line(t_img *canevas, t_vector2 v1, t_vector2 v2, int color);

#endif
