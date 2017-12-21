#ifndef VECTOR_H
# define VECTOR_H

typedef	struct	s_vector2
{
	float	x;
	float	y;
}				t_vector2;

typedef	struct	s_vector3
{
	float	x;
	float	y;
	float	z;
}				t_vector3;

typedef	struct	s_vector4
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vector4;

typedef	struct	s_edge
{
	t_vector3	*vertices[2];
}				t_edge;

typedef	struct	s_face
{
	t_edge		*edges[3];
}				t_face;

t_vector3	*new_vector3(float x, float y, float z);
t_edge		*new_edge(t_vector3 *v1, t_vector3 *v2);
t_face		*new_face(t_edge *edge1, t_edge *edge2, t_edge *edge3);

#endif
