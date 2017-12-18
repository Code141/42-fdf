#include <stdlib.h>
#include "vector.h"

t_vertex	*new_vertex(int x, int y, int z)
{
	t_vertex	*vertex;

	vertex = (t_vertex*)malloc(sizeof(t_vertex));
	vertex->x = x;
	vertex->y = y;
	vertex->z = z;
	return (vertex);
}

t_edge		*new_edge(t_vertex *vertex1, t_vertex *vertex2)
{
	t_edge	*edge;

	edge = (t_edge*)malloc(sizeof(t_edge));
	edge->vertices[0] = vertex1;
	edge->vertices[1] = vertex2;
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


