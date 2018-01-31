/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:55:52 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/31 18:29:24 by gelambin         ###   ########.fr       */
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

t_color_rgba		color_set_rgba(char r, char g, char b, char a);
t_color_rgba		color_blend(
						t_color_rgba *ca, t_color_rgba *cb, float balance);

#endif
