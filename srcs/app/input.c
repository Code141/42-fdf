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
	int			*new_line;
	int			**n_map;
	int			size;

	splited_line = ft_strsplit(line, ' ');
	if (!splited_line)
		return (0);
	size = ft_str_tab_length(splited_line);
	if (!map->width)
		map->width = size;
	else if (map->width != size)
	{
		ft_putstr("Found wrong line length. Exiting.\n");
		while (size--)
			free(splited_line[size]);
		free(splited_line);
		return (0);
	}
	new_line = strtab_to_inttab(splited_line, map->width);
	free(splited_line);
	if (new_line)
	{
		n_map = ft_array_int_push(map->map, map->height, new_line);		
		if (map->map)
			free(map->map);
		map->map = n_map;
		map->height++;
	}		
	return (1);
}

t_fdf_map	*parse_fdf_file(char *file_name)
{
	t_fdf_map	*map;
	int			fd;
	char		*line;

	ft_putstr("Loading file: ");
	ft_putendl(file_name);
	line = NULL;
	map = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror(file_name);
		return (NULL);
	}
	map = new_map(file_name);
	while (ft_get_next_line(fd, &line))
	{
		if (new_line(line, map) && line)
		{	
			free(line);
			line = NULL;
		}
		else
		{
			free(line);
			line = NULL;
			destroy_map(map);
			perror(file_name);
			return (NULL);
		}
	}
	map_delta(map);
	if (line)
		free(line);
	close(fd);
	return (map);
}
