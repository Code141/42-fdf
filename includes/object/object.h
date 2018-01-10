/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:57:12 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/10 18:05:58 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include <stdlib.h>
# include "libft.h"
# include "mesh.h"

typedef struct s_object	t_object;

struct					s_object
{
	t_object		*parent;
	t_list			*children;
	t_mesh			*mesh;
	t_vector3		pos;
	t_vector3		rot;
	t_matrice4		matrice;
};

t_object				*new_object(t_mesh *object);
void					object_add_child(t_object *obj1, t_object *obj2);
void					destroy_objects(void **objects);

#endif
