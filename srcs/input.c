#include "input.h"

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

int			ft_strtab_length(char **strtab)
{
	int i;

	i = 0;
	while (strtab[i])
		i++;
	return (i);
}

t_fdf_map	*parse_fdf_file(char *file_name)
{
	t_fdf_map	*map;
	int			fd;
	
	char		*line;
	char		**splited_line;
	int			size;

	map = (t_fdf_map*)malloc(sizeof(t_fdf_map));
	map->mapname = file_name;

	fd = open(file_name, O_RDONLY);
	while (ft_get_next_line(fd, &line))
	{
		splited_line = ft_strsplit(line, ' ');
		size = ft_strtab_length(splited_line);
		strtab_to_inttab(splited_line, size);
		free(splited_line);
	}
	close(fd);
	// Found wrong line length. Exiting.
	return (map);
}

