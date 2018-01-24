/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:40:40 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/24 17:47:47 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"

void		fdf_map_elevation(t_fdf_map *map, t_mesh *mesh)
{
	int i;
	int j;
	int x;
	int y;

	x = map->width;
	y = map->height;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			mesh->geometry->vertices[(i * x) + j]->z = -map->map[i][j];
			j++;
		}
		i++;
	}
}

t_object	*new_fdf_map(t_fdf_map *map, t_color_rgba color)
{
	t_geometry	*geometry;
	t_material	*material;
	t_object	*obj;
	int			x;
	int			y;

	x = map->width - 1;
	y = map->height - 1;
	geometry = new_surface2(x, y, x, y);
	material = new_material(color);
	obj = new_object(new_mesh(geometry, material));
	fdf_map_elevation(map, obj->mesh);
	return (obj);
}
