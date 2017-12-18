#ifndef MESH_H
# define MESH_H
# include "vector.h"
# include "geometry.h"
# include "material.h"

typedef struct	s_mesh
{
	t_geometry	*geometry;
	t_material	*material;
	t_vector	pos;
}				t_mesh;

t_mesh			*new_mesh(t_geometry *geometry, t_material *material);

#endif
