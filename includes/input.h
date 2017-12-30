#ifndef INPUT_H
# define INPUT_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_fdf_map
{
	char	*mapname;
	int		width;
	int		height;
	int		delta;
	int		**map;
	int		**color_map;
}				t_fdf_map;

t_fdf_map	*parse_fdf_file(char *file_name);

#endif
