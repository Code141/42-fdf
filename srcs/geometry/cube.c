#include "cube.h"

t_geometry	*new_cube(int x, int y, int z)
{
	t_geometry	*geo;

	geo = (t_geometry*)malloc(sizeof(t_geometry));

	geo->vertices = (t_vector3**)malloc(sizeof(t_vector3*) * 9);

	geo->vertices[0] = new_vector3(-x / 2, -y / 2, z / 2);
	geo->vertices[1] = new_vector3(-x / 2, y / 2, z / 2);
	geo->vertices[2] = new_vector3(x / 2, -y / 2, z / 2);
	geo->vertices[3] = new_vector3(x / 2, y / 2, z / 2);
	geo->vertices[4] = new_vector3(-x / 2, -y / 2, -z / 2);
	geo->vertices[5] = new_vector3(-x / 2, y / 2, -z / 2);
	geo->vertices[6] = new_vector3(x / 2, -y / 2, -z / 2);
	geo->vertices[7] = new_vector3(x / 2, y / 2, -z / 2);
	geo->vertices[8] = NULL;

	geo->edges = (t_edge**)malloc(sizeof(t_edge*) * 13);
	geo->edges[0] = new_edge(geo->vertices[0], geo->vertices[1]);
	geo->edges[1] = new_edge(geo->vertices[0], geo->vertices[2]);
	geo->edges[2] = new_edge(geo->vertices[1], geo->vertices[3]);
	geo->edges[3] = new_edge(geo->vertices[2], geo->vertices[3]);
	geo->edges[4] = new_edge(geo->vertices[4], geo->vertices[5]);
	geo->edges[5] = new_edge(geo->vertices[4], geo->vertices[6]);
	geo->edges[6] = new_edge(geo->vertices[5], geo->vertices[7]);
	geo->edges[7] = new_edge(geo->vertices[6], geo->vertices[7]);
	geo->edges[8] = new_edge(geo->vertices[0], geo->vertices[4]);
	geo->edges[9] = new_edge(geo->vertices[1], geo->vertices[5]);
	geo->edges[10] = new_edge(geo->vertices[3], geo->vertices[7]);
	geo->edges[11] = new_edge(geo->vertices[2], geo->vertices[6]);
	geo->edges[12] = NULL;
	
/*	geo->faces = (t_face**)malloc(sizeof(t_face*) * 3);
	geo->faces[0] = new_face(geo->edges[0], geo->edges[1], geo->edges[4]);
	geo->faces[1] = new_face(geo->edges[2], geo->edges[3], geo->edges[4]);
	geo->faces[2] = NULL;
*/	return (geo);
}


