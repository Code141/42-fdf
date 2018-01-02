#ifndef MAP_H
# define MAP_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_fdf_map
{
	char	*name;
	int		width;
	int		height;
	int		min;
	int		max;
	int		delta;
	int		**map;
	int		**color_map;
}				t_fdf_map;

t_fdf_map	*new_map(char *file_name);
void		destroy_map(t_fdf_map *map);

#endif