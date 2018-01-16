#include "color.h"

void		color_set_rvb(int r, int g, int b, t_color_rgba *c)
{
	c->c.r = r;
	c->c.g = g;
	c->c.b = b;
}

t_color_rgba		color_blend(t_color_rgba *ca, t_color_rgba *cb, float balance)
{
	t_color_rgba c3;

	c3.c.r = (int)((ca->c.r - cb->c.r) * balance + cb->c.r);
	c3.c.g = (int)((ca->c.g - cb->c.g) * balance + cb->c.g);
	c3.c.b = (int)((ca->c.b - cb->c.b) * balance + cb->c.b);
	return (c3);	
}

