#include <stdlib.h>
#include "geometry.h"
#include "vector.h"

/*
t_geometry	*new_geometry(int x, int y, int z)
{
}
*/

t_geometry	*new_square(int x, int y, int z)
{
	t_geometry	*geometry;

	geometry = (t_geometry*)malloc(sizeof(t_geometry));
	geometry->size.x = x;
	geometry->size.y = y;
	geometry->size.z = z;
	return (geometry);
}
