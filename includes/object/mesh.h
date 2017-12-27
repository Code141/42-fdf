#ifndef MESH_H
# define MESH_H
# include <stdlib.h>
# include "vector.h"
# include "matrice4.h"
# include "geometry.h"
# include "material.h"

typedef struct	s_mesh
{
	t_geometry	*geometry;
	t_material	*material;
	t_vector3	pos;
	t_vector3	rot;
	t_matrice4	matrice;
}				t_mesh;

t_mesh		*new_mesh(t_geometry *geometry, t_material *material);
void		destroy_mesh(t_mesh *mesh);

#endif
