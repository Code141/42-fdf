#include "input.h"

int			**ft_array_int_push(int **array, int size, int *new_elem)
{
	int	**new_array;
	int	i;

	new_array = (int**)malloc(sizeof(*new_array) * (size + 1));
	if (!new_array)
		return (NULL);
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
	i = 0;
	while (i < size)
	{
		tab[i] = ft_atoi(strtab[i]);
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

t_fdf_map	*parse_fdf_file(char *file_name)
{
	t_fdf_map	*map;
	int			fd;
	char		*line;
	char		**splited_line;
	int			size;
	int			*new_line;
	int			**n_map;

	map =  new_map(file_name);

	fd = open(file_name, O_RDONLY);
	while (ft_get_next_line(fd, &line))
	{
		splited_line = ft_strsplit(line, ' ');
		free(line);

		if (!map->width)
			map->width = ft_str_tab_length(splited_line);
		else if (map->width != ft_str_tab_length(splited_line))
		{
			ft_putstr("Found wrong line length. Exiting.\n");
			free(splited_line);
			return (0);
		}

		new_line = strtab_to_inttab(splited_line, map->width);

		if (new_line)
		{
			n_map = ft_array_int_push(map->map, map->height, new_line);		
			if (map->map)
				free(map->map);
			map->map = n_map;
		}		
		free(splited_line);
		map->height++;
	}
	close(fd);
	return (map);
}

