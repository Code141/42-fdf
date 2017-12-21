#ifndef PIXEL_H
# define PIXEL_H
# include "ctx.h"
# include "color.h"

void	put_pixel(t_img *canevas, int x, int y, t_color color);
void	draw_point(t_img *canevas, t_vector2 v, int size, t_color color);
void	draw_line(t_img *canevas, t_vector2 v1, t_vector2 v2, t_color color);

#endif
