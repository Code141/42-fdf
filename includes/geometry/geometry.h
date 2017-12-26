#ifndef GEOMETRY_H
# define GEOMETRY_H
# include <stdlib.h>
# include "vector.h"

typedef struct	s_geometry
{
	t_vector3	**vertices;
	t_edge		**edges;
	t_face		**faces;
	// INT NB vert / edge / faces
}				t_geometry;

t_geometry	*new_plane(int x, int y);
t_geometry	*new_cube(int x, int y, int z);
t_geometry	*new_surface(int x, int y, int subx, int suby);

#endif
