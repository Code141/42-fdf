#ifndef VECTOR_H
# define VECTOR_H

typedef	struct	s_vector2
{
	int	x;
	int	y;
}				t_vector2;

typedef	struct	s_vector3
{
	float	x;
	float	y;
	float	z;
}				t_vector3;

typedef	struct	s_vertex
{
	float	x;
	float	y;
	float	z;
}				t_vertex;

typedef	struct	s_edge
{
	t_vertex	*vertices[2];
}				t_edge;

typedef	struct	s_face
{
	t_edge		*edges[3];
}				t_face;

t_vertex	*new_vertex(int x, int y, int z);
t_edge		*new_edge(t_vertex *vertex1, t_vertex *vertex2);
t_face		*new_face(t_edge *edge1, t_edge *edge2, t_edge *edge3);

#endif
