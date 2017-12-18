#include "pixel.h"

void	put_pixel(t_img *canevas, int x, int y, int color)
{
	if ((y < 0 || y >= canevas->height)
		|| (x < 0 || x >= canevas->width))
	return ;
	((unsigned int*)canevas->data)[(y * canevas->width) + x] = color;	// Alpha
}

void	draw_point(t_img *canevas, t_vector2 v, int size, int color)
{
	int x;
	int y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			put_pixel(canevas, v.x + x - size / 2, v.y + y - size / 2, color);
			y++;
		}
		x++;
	}
}

void	draw_line(t_img *canevas, t_vector2 v1, t_vector2 v2, int color)
{
	int dx;
	int dy;
	int x;
	int y;

	dx = v2.x - v1.x;
	dy = v2.y - v1.y;
	if (dx > dy)
	{	
		x = v1.x;
		while (x < v2.x)
		{
			y = v1.y + dy * (x - v1.x) / dx;
			put_pixel(canevas, x, y, color);
			x++;
		}
	}
	else
	{
		y = v1.y;
		while (y < v2.y)
		{
			x = v1.x + dx * (y - v1.y) / dy;
			put_pixel(canevas, x, y, color);
			y++;
		}
	
	}
}
