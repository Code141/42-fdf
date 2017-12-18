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
//	geometry->size.x = x;
//	geometry->size.y = y;
//	geometry->size.z = z;
	return (geometry);
}


t_geometry	*new_plane(int x, int y)
{
	t_geometry	*geometry;

	geometry = (t_geometry*)malloc(sizeof(t_geometry));
	
	geometry->vertices = (t_vertex**)malloc(sizeof(t_vertex*) * 5);
	geometry->vertices[0] = new_vertex(0, 0, 0);
	geometry->vertices[1] = new_vertex(0, y, 0);
	geometry->vertices[2] = new_vertex(x, 0, 0);
	geometry->vertices[3] = new_vertex(x, y, 0);
	geometry->vertices[4] = NULL;

	geometry->edges = (t_edge**)malloc(sizeof(t_edge*) * 6);
	geometry->edges[0] = new_edge(geometry->vertices[0], geometry->vertices[1]);
	geometry->edges[1] = new_edge(geometry->vertices[0], geometry->vertices[2]);
	geometry->edges[2] = new_edge(geometry->vertices[1], geometry->vertices[3]);
	geometry->edges[3] = new_edge(geometry->vertices[2], geometry->vertices[3]);
	geometry->edges[4] = new_edge(geometry->vertices[1], geometry->vertices[2]);
	geometry->edges[5] = NULL;

	geometry->faces = (t_face**)malloc(sizeof(t_face*) * 3);
	geometry->faces[0] = new_face(
		geometry->edges[0],
		geometry->edges[1],
		geometry->edges[4]
	);

	geometry->faces[1] = new_face(
		geometry->edges[2],
		geometry->edges[3],
		geometry->edges[4]
	);
	geometry->faces[2] = NULL;
	return (geometry);
}

