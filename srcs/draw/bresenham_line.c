#include "bresenham_line.h"

void	bresenham_line1(t_img *canevas, int x1, int y1, int x2, int y2, t_color color)
{
	int	dx;
	int dy;
	int	e;

	dx = (x2 - x1);
	dy = (y2 - y1);
	if (dx > dy)
	{
		/*--- OCTAN 1/5 ---*/
		e = x2 - x1;
		while (x1 < x2)
		{
			put_pixel(canevas, x1, y1, color);
			e -= dy;
			if (e <= 0)
			{
				y1++;
				e += dx;
			}
			x1++;
		}
	}
	else
	{
		/*--- OCTAN 2/6 ---*/
		e = y2 - y1;
		while (y1 < y2)
		{
			put_pixel(canevas, x1, y1, color);
			e -= dx;
			if (e <= 0)
			{
				x1++;
				e += dy;
			}
			y1++;
		}
	}
}

void	bresenham_line2(t_img *canevas, int x1, int y1, int x2, int y2, t_color color)
{
	int	dx;
	int dy;
	int	e;

	dx = (x2 - x1);
	dy = (y1 - y2);
	if (dx > dy)
	{
		/*--- OCTAN 4/8 ---*/
		e = x2 - x1;
		while (x1 < x2)
		{
			put_pixel(canevas, x1, y1, color);
			e -= dy;
			if (e <= 0)
			{
				y1--;
				e += dx;
			}
			x1++;
		}
	}
	else
	{
		/*--- OCTAN 3/7 ---*/
		e = y2 - y1;
		while (y1 > y2)
		{
			put_pixel(canevas, x1, y1, color);
			e -= dx;
			if (e <= 0)
			{
				x1++;
				e += dy;
			}
			y1--;
		}
	}
}

void	line(t_img *canevas, t_vector2 v1, t_vector2 v2, t_color color)
{
	if (v1.x <= v2.x)
		if (v1.y < v2.y)
			bresenham_line1(canevas, v1.x, v1.y, v2.x, v2.y, color);
		else
			bresenham_line2(canevas, v1.x, v1.y, v2.x, v2.y, color);
	else
		if (v1.y > v2.y)
			bresenham_line1(canevas, v2.x, v2.y, v1.x, v1.y, color);
		else
			bresenham_line2(canevas, v2.x, v2.y, v1.x, v1.y, color);
}
