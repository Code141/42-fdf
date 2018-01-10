/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:44:18 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/10 17:47:55 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "vector.h"

t_vector3	*new_vector3(float x, float y, float z)
{
	t_vector3	*v;

	v = (t_vector3*)malloc(sizeof(t_vector3));
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

void		vector3_set(t_vector3 *v, float x, float y, float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void		vect3_normalise(t_vector3 *v)
{
	float	size;

	size = sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x = v->x / size;
	v->y = v->z / size;
	v->z = v->z / size;
}
