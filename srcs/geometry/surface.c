#include "surface.h"

static t_vector3	**surface_vertices(int x, int y, int subx, int suby)
{
	t_vector3	**vertices;
	int			i;
	int			j;
	
	vertices = (t_vector3**)malloc(sizeof(t_vector3*) * ((subx + 1) * (suby + 1) + 1));
	i = 0;
	while (i < suby + 1)
	{
		j = 0;
		while (j < subx + 1)
		{
			vertices[(i * (suby + 1)) + j] = new_vector3(x / subx * j - x / 2, y / suby * i - y / 2, 0);
			j++;
		}
		i++;
	}
	vertices[(subx + 1) * (suby + 1)] = NULL;
	return (vertices);
}

static t_edge		**surface_edges(t_vector3 **vertices, int subx, int suby)
{
	t_edge	**edges;
	int		i;
	int		j;

 	edges = (t_edge**)malloc(sizeof(t_edge*) * ((subx * suby * 3) + (subx + suby) + 1));
	i = 0;
	while (i < suby)
	{
		j = 0;
		while (j < subx)
		{
			edges[(i * subx * 3 + (i * 1)) + j * 3 + 0] = new_edge(vertices[(i * (suby + 1)) + j], vertices[(i * (suby + 1)) + j + 1]);
			edges[(i * subx * 3 + (i * 1)) + j * 3 + 1] = new_edge(vertices[(i * (suby + 1)) + j], vertices[((i + 1) * (suby + 1)) + j]);
			edges[(i * subx * 3 + (i * 1)) + j * 3 + 2] = new_edge(vertices[(i * (suby + 1)) + j], vertices[((i + 1) * (suby + 1)) + j + 1]);
			j++;
		}
		edges[(i * subx * 3 + (i * 1)) + j * 3 + 0] = new_edge(vertices[(i * (suby + 1)) + j], vertices[((i + 1) * (suby + 1)) + j ]);
		i++;
	}
	j = 0;
	while (j < subx)
	{
		edges[(i * subx * 3 + (i * 1)) + j ] = new_edge(vertices[(i * (suby + 1)) + j], vertices[(i * (suby + 1)) + j + 1]);
		j++;
	}
	edges[(subx * suby * 3) + (subx + suby)] = NULL;
	return (edges);
}

static t_face		**surface_faces(t_edge **edges, int subx, int suby)
{
	t_face **faces; 

	faces = (t_face**)malloc(sizeof(t_face*) * 3);
	faces[0] = NULL;
	return (faces);
}

t_geometry	*new_surface(int x, int y, int subx, int suby)
{
	t_geometry	*geo;

	geo = (t_geometry*)malloc(sizeof(t_geometry));
	geo->vertices = surface_vertices(x, y, subx, suby);
	geo->edges = surface_edges(geo->vertices, subx, suby);
	geo->faces = surface_faces(geo->edges, subx, suby);
	return (geo);
}
