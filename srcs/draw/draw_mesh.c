#include "draw_mesh.h"

void	draw_vertices(t_ctx *ctx, t_object *object, t_matrice4 *m)
{
	int			i;
	t_mesh		*mesh;
	t_vector4	v1;
	t_vector2	v2;
	t_matrice4	m3;

	mesh = object->mesh;
	matrice_product(m, &mesh->matrice, &m3);
	i = 0;
	while (mesh->geometry->vertices[i])
	{
		v1 = matrice_apply(&m3, mesh->geometry->vertices[i]);
		v2 = projection(ctx, &v1, mesh);
			draw_point(ctx->screen->canevas, v2, 1, mesh->material->color);
		i++;
	}
}

void	draw_edges(t_ctx *ctx, t_object *object, t_matrice4 *m)
{
	int			i;
	t_vector4	v1a;
	t_vector4	v1b;
	t_vector2	v2a;
	t_vector2	v2b;
	t_mesh		*mesh;
	t_matrice4	m3;

	mesh = object->mesh;
	matrice_product(m, &mesh->matrice, &m3);
	i = 0;
	while (mesh->geometry->edges[i])
	{
		v1a = matrice_apply(&m3, mesh->geometry->edges[i]->vertices[0]);
		v1b = matrice_apply(&m3, mesh->geometry->edges[i]->vertices[1]);
		//CLIPING
		if (v1a.z > 0 && v1b.z > 0)
		{
			v2a = projection(ctx, &v1a, mesh);
			v2b = projection(ctx, &v1b, mesh);
			line(ctx->screen->canevas, v2a, v2b, mesh->material->color);
		}
		i++;
	}
}

void	draw_mesh(t_ctx *ctx, t_object *object, t_matrice4 *m)
{
	draw_edges(ctx, object, m);
//	draw_vertices(ctx, object, m);
}


