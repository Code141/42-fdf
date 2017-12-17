#ifndef GEOMETRY_H
# define GEOMETRY_H
# include "vector.h"

typedef struct	s_geometry
{
	t_vect	size;
}				t_geometry;

t_geometry	*new_geometry(int x, int y, int z);
t_geometry	*new_square(int x, int y, int z);

#endif
