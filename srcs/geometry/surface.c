#include "surface.h"

t_geometry	*new_surface(int x, int y, int subx, int suby)
{
	t_geometry	*geo;
	int			i;
	int			j;

	geo = (t_geometry*)malloc(sizeof(t_geometry));
	geo->vertices = (t_vector3**)malloc(sizeof(t_vector3*) * ((subx + 1) * (suby + 1) + 1));
	i = 0;
	while (i < suby + 1)
	{
		j = 0;
		while (j < subx + 1)
		{
			geo->vertices[(i * (suby + 1)) + j] = new_vector3(x / subx * j, y / suby * i, 0);
			j++;
		}
		i++;
	}
	geo->vertices[(subx + 1) * (suby + 1)] = NULL;

	geo->edges = (t_edge**)malloc(sizeof(t_edge*) * ((subx * suby * 3) + (subx + suby) + 1));
	i = 0;
	while (i < suby)
	{
		j = 0;
		while (j < subx)
		{
			geo->edges[(i * subx * 3 + (i * 1)) + j * 3 + 0] = new_edge(geo->vertices[(i * (suby + 1)) + j], geo->vertices[(i * (suby + 1)) + j + 1]);
			geo->edges[(i * subx * 3 + (i * 1)) + j * 3 + 1] = new_edge(geo->vertices[(i * (suby + 1)) + j], geo->vertices[((i + 1) * (suby + 1)) + j]);
			geo->edges[(i * subx * 3 + (i * 1)) + j * 3 + 2] = new_edge(geo->vertices[(i * (suby + 1)) + j], geo->vertices[((i + 1) * (suby + 1)) + j + 1]);
			j++;
		}
		geo->edges[(i * subx * 3 + (i * 1)) + j * 3 + 0] = new_edge(geo->vertices[(i * (suby + 1)) + j], geo->vertices[((i + 1) * (suby + 1)) + j ]);
		i++;
	}
	j = 0;
	while (j < subx)
	{
		geo->edges[(i * subx * 3 + (i * 1)) + j ] = new_edge(geo->vertices[(i * (suby + 1)) + j], geo->vertices[(i * (suby + 1)) + j + 1]);
		j++;
	}
	

	geo->edges[(subx * suby * 3) + (subx + suby)] = NULL;
	return (geo);
}
