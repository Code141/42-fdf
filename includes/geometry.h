#ifndef GEOMETRY_H
# define GEOMETRY_H
# include "vector.h"

typedef struct	s_geometry
{
	t_vertex	**vertices;
	t_edge		**edges;
	t_face		**faces;
	// INT NB vert / edge / faces
}				t_geometry;

t_geometry	*new_plane(int x, int y);

#endif
