/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:10:04 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/01 16:18:35 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "ctx.h"

int			**ft_array_int_push(int **array, int size, int *new_elem)
{
	int	**new_array;
	int	i;

	new_array = (int**)malloc(sizeof(*new_array) * (size + 1));
	if (!new_array)
		crash("Broken malloc");
	i = 0;
	while (i < size)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = new_elem;
	return (new_array);
}

int			*strtab_to_inttab(char **strtab, int size)
{
	int i;
	int	*tab;

	tab = (int*)malloc(sizeof(*tab) * (size));
	if (!tab)
		crash("Broken malloc");
	i = 0;
	while (i < size)
	{
		tab[i] = ft_atoi(strtab[i]);
		free(strtab[i]);
		i++;
	}
	return (tab);
}

int			ft_str_tab_length(char **strtab)
{
	int i;

	i = 0;
	while (strtab[i])
		i++;
	return (i);
}

int			new_line(char *line, t_fdf_map *map)
{
	char		**splited_line;
	int			**n_map;
	int			size;

	if (!(splited_line = ft_strsplit(line, ' ')))
		perror(map->name);
	if (!splited_line)
		exit(1);
	size = ft_str_tab_length(splited_line);
	map->width = (!map->width) ? size : map->width;
	if (map->width != size)
	{
		ft_putstr("Found wrong line length.\n");
		while (size--)
			free(splited_line[size]);
		free(splited_line);
		return (0);
	}
	n_map = ft_array_int_push(map->map, map->height,
			strtab_to_inttab(splited_line, map->width));
	free(splited_line);
	if (map->map)
		free(map->map);
	map->map = n_map;
	return (1);
}

t_fdf_map	*parse_fdf_file(char *file_name)
{
	t_fdf_map	*map;
	int			fd;
	char		*line;

	map = NULL;
	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		perror(file_name);
	if (fd < 0 || !(map = new_map(file_name)))
		return (NULL);
	while (ft_get_next_line(fd, &line))
	{
		if (!new_line(line, map) && line)
			return (0);
		map->height++;
		if (line)
			free(line);
		line = NULL;
	}
	free(line);
	close(fd);
	map_delta(map);
	return (map);
}
