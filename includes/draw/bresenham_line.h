#ifndef BRESENHAM_LINE_H
# define BRESENHAM_LINE_H
# include "pixel.h"

void	bresenham_line(t_img *canevas, int x1, int y1, int x2, int y2, t_color color);
void	line(t_img *canevas, t_vector2 v1, t_vector2 v2, t_color color);

#endif
