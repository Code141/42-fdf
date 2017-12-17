#ifndef OBJECT_H
# define OBJECT_H
# include "vector.h"
# include "geometry.h"
# include "material.h"

typedef struct	s_object
{
	t_geometry	*geometry;
	t_material	*material;
	t_vect		pos;
}				t_object;

t_object	*new_object(t_geometry *geometry, t_material *material);

#endif
