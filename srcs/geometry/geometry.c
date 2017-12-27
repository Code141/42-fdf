#include "geometry.h"

void	destroy_geometry(t_geometry *geo)
{
	int i;

	i = 0;
	while (geo->vertices[i])
		free(geo->vertices[i++]);
	free(geo->vertices);
	geo->vertices = NULL;
	i = 0;
	while (geo->edges[i])
		free(geo->edges[i++]);
	free(geo->edges);
	geo->edges = NULL;
	i = 0;
	while (geo->faces[i])
		free(geo->faces[i++]);
	free(geo->faces);
	geo->faces = NULL;
}
