#include "bresenham_line.h"

void	bresenham_line(t_img *canevas, int x1, int y1, int x2, int y2, t_color color)
{
	int	dx;
	int dy;
	int	e;

	if (x2 - x1 > y2 - y1)
	{
		/*-- OCTAN 1 --*/
		e = x2 - x1;
		dx = e * 2;
		dy = (y2 - y1) * 2;
		while (x1 <= x2)
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
		/*-- OCTAN 2 --*/
		e = x2 - x1;
		dx = e * 2;
		dy = (y2 - y1) * 2;
		while (x1 <= x2)
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
	/*-- OCTAN 3 --*/

	/*-- OCTAN 4 --*/





	/*-- OCTAN 5 --*/
	/*-- OCTAN 6 --*/
	/*-- OCTAN 7 --*/
	/*-- OCTAN 8 --*/



	put_pixel(canevas, x2, y2, color);
}

void	line(t_img *canevas, t_vector2 v1, t_vector2 v2, t_color color)
{
	if (v1.x < v2.x)
		bresenham_line(canevas, v1.x, v1.y, v2.x, v2.y, color);
	if (v1.x > v2.x)
		bresenham_line(canevas, v2.x, v2.y, v1.x, v1.y, color);
}
