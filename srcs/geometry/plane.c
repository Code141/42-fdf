#include "plane.h"

t_geometry	*new_plane(int x, int y)
{
	t_geometry	*geo;

	geo = (t_geometry*)malloc(sizeof(t_geometry));
	geo->vertices = (t_vector3**)malloc(sizeof(t_vector3*) * 5);
	geo->vertices[0] = new_vector3(-x / 2, -y / 2, 0);
	geo->vertices[1] = new_vector3(-x / 2, y / 2, 0);
	geo->vertices[2] = new_vector3(x / 2, -y / 2, 0);
	geo->vertices[3] = new_vector3(x / 2, y / 2, 0);
	geo->vertices[4] = NULL;
	geo->edges = (t_edge**)malloc(sizeof(t_edge*) * 6);
	geo->edges[0] = new_edge(geo->vertices[0], geo->vertices[1]);
	geo->edges[1] = new_edge(geo->vertices[0], geo->vertices[2]);
	geo->edges[2] = new_edge(geo->vertices[1], geo->vertices[3]);
	geo->edges[3] = new_edge(geo->vertices[2], geo->vertices[3]);
	geo->edges[4] = new_edge(geo->vertices[1], geo->vertices[2]);
	geo->edges[5] = NULL;
	geo->faces = (t_face**)malloc(sizeof(t_face*) * 3);
	geo->faces[0] = new_face(geo->edges[0], geo->edges[1], geo->edges[4]);
	geo->faces[1] = new_face(geo->edges[2], geo->edges[3], geo->edges[4]);
	geo->faces[2] = NULL;
	return (geo);
}
