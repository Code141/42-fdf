#include "map.h"

t_fdf_map	*new_map(char *file_name)
{
	t_fdf_map	*map;

	map = (t_fdf_map*)malloc(sizeof(t_fdf_map));
	map->name = file_name;
	map->width = 0;
	map->height = 0;
	map->min = 2147483647;
	map->max = -2147483648;
	map->delta = 0;
	map->map = NULL;
	return (map);
}

void		destroy_map(t_fdf_map *map)
{
	int	x;
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
