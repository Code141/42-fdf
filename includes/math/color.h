#ifndef COLOR_H
# define COLOR_H

typedef union	u_color
{
	unsigned int	hex;
	struct			s_c
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	}					c;
}				t_color;

#endif
