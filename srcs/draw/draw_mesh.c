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
	int				i;
	t_vector4		v1a;
	t_vector4		v1b;
	t_vector2		v2a;
	t_vector2		v2b;
	t_mesh			*mesh;
	t_matrice4		m3;
	t_color_rgba	color;

	mesh = object->mesh;
	matrice_product(m, &mesh->matrice, &m3);
	i = 0;
	while (mesh->geometry->edges[i])
	{
		color.hex = 0x000000;
		v1a = matrice_apply(&m3, mesh->geometry->edges[i]->vertices[0]);
		v1b = matrice_apply(&m3, mesh->geometry->edges[i]->vertices[1]);
		//CLIPING
		if (v1a.z > ctx->camera->near && v1b.z > ctx->camera->near
			&& v1a.z < ctx->camera->far * 10 && v1b.z < ctx->camera->far * 10)
		{
			v2a = projection(ctx, &v1a, mesh);
			v2b = projection(ctx, &v1b, mesh);
			if (!(v2a.x < 0 && v2b.x < 0) && !(v2a.x > ctx->screen->width && v2b.x > ctx->screen->width)
			&& !(v2a.y < 0 && v2b.y < 0) && !(v2a.y > ctx->screen->height && v2b.y > ctx->screen->height))
			{
				color = color_blend(&mesh->material->color, &color, v1a.z / 1000); 
				line(ctx->screen->canevas, v2a, v2b, color);
			}	
		}
		i++;
	}
}

void	draw_mesh(t_ctx *ctx, t_object *object, t_matrice4 *m)
{
	draw_edges(ctx, object, m);
//	draw_vertices(ctx, object, m);
}


