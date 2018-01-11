/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:55:52 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/11 18:34:10 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include <math.h>

typedef union		u_color_rgba
{
	unsigned int	hex;
	struct			s_c
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	}				c;
}					t_color_rgba;

typedef struct		s_color_hsl
{
	int		h;
	float	s;
	float	l;
}					t_color_hsl;

void			color_set_hsl(float h, float s, float l, t_color_hsl *c1);
void			color_set_rvb(int r, int v, int b, t_color_rgba *c);
t_color_hsl		color_rgb_to_hsl(t_color_rgba c1);
t_color_rgba	color_hsl_to_rgb(t_color_hsl c1);

#endif
