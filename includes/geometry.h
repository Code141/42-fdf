#ifndef GEOMETRY_H
# define GEOMETRY_H
# include "vector.h"

typedef struct	s_geometry
{
	t_vector3	**vertices;
	t_edge		**edges;
	t_face		**faces;
	// INT NB vert / edge / faces
}				t_geometry;

#endif
