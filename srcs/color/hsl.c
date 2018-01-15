#include "color.h"

void		color_set_rvb(int r, int g, int b, t_color_rgba *c)
{
	c->c.r = r;
	c->c.g = g;
	c->c.b = b;
}

void			color_set_hsl(float h, float s, float l, t_color_hsl *c1)
{
	c1->h = h;
	c1->s = s;
	c1->l = l;
}

t_color_hsl		color_rgb_to_hsl(t_color_rgba c1)
{
	t_color_hsl	c2;
	float		r;
	float		g;
	float		b;
	float		min;
	float		max;
	float		delta;

	r = (float)c1.c.r / 255;
	g = (float)c1.c.g / 255;
	b = (float)c1.c.b / 255;
	min = fmin(r, fmin(g, b));
	max = fmax(r, fmax(g, b));
	delta = max - min;
	if (!delta)
		c2.h = 0;
	else if (max == r)
		c2.h = 60 * fmod(((g - b) / delta),  6);
	else if (max == g)
		c2.h = 60 * (((b - r) / delta) + 2);
	else if (max == b)
		c2.h = 60 * (((r - g) / delta) + 4);
	c2.l = (max + min) / 2;
	c2.s = 0;
	if (delta)
		c2.s = delta / (1 - fabs(2 * c2.l - 1));
	return (c2);
}

t_color_rgba	color_hsl_to_rgb(t_color_hsl c1)
{
	t_color_rgba	c2;
	float			c;
	float			h;
	float			x;
	
	c = ((1 - fabs(2 * c1.l - 1)) * c1.s);
	h = c1.h / 60;
	x = c * (1 - fabs((float)((int)h % 2) - 1));

	if (0 == h)
		c2.hex = 0;
	else if (h <= 1)
		c2.hex = (c * 256 * 256) + (x * 256) + (0);
	else if (h <= 2)
		c2.hex = (x * 256 * 256) + (c * 256) + (0);
	else if (h <= 3)
		c2.hex = (0) + (c * 256) + (x);
	else if (h <= 4)
		c2.hex = (0) + (x * 256) + (c);
	else if (h <= 5)
		c2.hex = (x * 256 * 256) + (0) + (c);
	else if (h < 6)
		c2.hex = (c * 256 * 256) + (0) + (x);
	c2.hex *= c1.l - (1 / 2 * c);

	return (c2);
}
