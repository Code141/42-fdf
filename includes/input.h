#ifndef INPUT_H
# define INPUT_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "map.h"

t_fdf_map	*parse_fdf_file(char *file_name);

#endif
