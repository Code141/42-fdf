/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:56:44 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/10 17:56:50 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef	struct	s_vector2
{
	float	x;
	float	y;
}				t_vector2;

typedef	struct	s_vector3
{
	float	x;
	float	y;
	float	z;
}				t_vector3;

typedef	struct	s_vector4
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vector4;

t_vector3		*new_vector3(float x, float y, float z);
void			vector3_set(t_vector3 *v, float x, float y, float z);
void			vect3_normalise(t_vector3 *v);

#endif
