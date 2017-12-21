#include <stdlib.h>
#include "vector.h"

t_vector3	*new_vector3(float x, float y, float z)
{
	t_vector3	*v;

	v = (t_vector3*)malloc(sizeof(t_vector3));
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_edge		*new_edge(t_vector3 *v1, t_vector3 *v2)
{
	t_edge	*edge;

	edge = (t_edge*)malloc(sizeof(t_edge));
	edge->vertices[0] = v1;
	edge->vertices[1] = v2;
	return (edge);
}

t_face		*new_face(t_edge *edge1, t_edge *edge2, t_edge *edge3)
{
	t_face	*face;

	face = (t_face*)malloc(sizeof(t_face));
	face->edges[0] = edge1;
	face->edges[1] = edge2;
	face->edges[2] = edge3;
	return (face);
}


