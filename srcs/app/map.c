/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:51:21 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/31 17:51:15 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "ctx.h"

t_fdf_map	*new_map(char *file_name)
{
	t_fdf_map	*map;

	map = (t_fdf_map*)malloc(sizeof(t_fdf_map));
	if (!map)
		crash("Broken malloc");	
	map->name = file_name;
	map->width = 0;
	map->height = 0;
	map->min = 2147483647;
	map->max = -2147483648;
	map->delta = 0;
	map->map = NULL;
	return (map);
}

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

void		destroy_map(t_fdf_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		free(map->map[y]);
		y++;
	}
	free(map->map);
	free(map);
}

void		map_delta(t_fdf_map *map)
{
	int	x;
	int	y;

	map->min = 2147483647;
	map->max = -2147483648;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] > map->max)
				map->max = map->map[y][x];
			if (map->map[y][x] < map->min)
				map->min = map->map[y][x];
			x++;
		}
		y++;
	}
	map->delta = map->max - map->min;
}
