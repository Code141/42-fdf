#include "draw.h"

float	scalaire(float x, float y)
{
	int a;
	int b;

	t_vector2 v2;
	float angle;
	v2.x = 0;
	v2.y = 1;

	a =	(x * v2.x) + (y * v2.y);
	b = ((x * x) + (y * y)) * ((v2.x * v2.x) + (v2.y * v2.y));
	angle = acos(a / sqrt(b));
	return (angle);
}

t_vector2	projection(t_ctx *ctx, t_vector3 *v1, t_mesh *mesh)
{
/*	float cpp;
	t_vector2	v2;

	cpp = 1 / tan(ctx->scene->camera->angle / 2);
	printf("%f\n",cpp*ctx->screen->height);
*/

	t_vector2	v2;
	float		hypo;
	t_vector3	angle;
	hypo = hypot(v1->x, v1->y);
	hypo = hypot(hypo, v1->z);
	angle.x = scalaire(v1->y, v1->z);
	angle.y = scalaire(v1->x, v1->z);
	angle.z = scalaire(v1->x, v1->y);
	if (v1->x < 0)
		angle.z = -angle.z;
	v2.x = hypo * (cos(mesh->rot.z + angle.z) * cos(mesh->rot.x + angle.x));
	v2.y = hypo * (sin(mesh->rot.z + angle.z));// * sin(mesh->rot.x + angle.x));
	mesh->rot.x += 0.05 * RAD;
//	mesh->rot.y += 0.05 * RAD;
	mesh->rot.z += 0.05 * RAD;

	v2.x += (ctx->screen->width / 2) + mesh->pos.x - ctx->scene->camera->pos.x;
	v2.y += (ctx->screen->height / 2) + mesh->pos.y - ctx->scene->camera->pos.y;
	
	return (v2);	
}

void	draw_vertices(t_ctx *ctx, t_mesh *mesh)
{
	int			i;
	int			x;
	int			y;
	t_vector2	v;

	i = 0;
	while (mesh->geometry->vertices[i])
	{
		v = projection(ctx, mesh->geometry->vertices[i], mesh);
		draw_point(ctx->screen->canevas, v, 5, mesh->material->color);
		i++;
	}
}

void	draw_edges(t_ctx *ctx, t_mesh *mesh)
{
	int			i;
	t_vector2 v1;
	t_vector2 v2;
	
	i = 0;
	while (mesh->geometry->edges[i])
	{
		v1 = projection(ctx, mesh->geometry->edges[i]->vertices[0], mesh);
		v2 = projection(ctx, mesh->geometry->edges[i]->vertices[1], mesh);
		draw_line(ctx->screen->canevas, v1, v2, mesh->material->color);
		i++;
	}
}

void	draw_mesh(t_ctx *ctx, t_mesh *mesh)
{
	draw_edges(ctx, mesh);
	draw_vertices(ctx, mesh);
}

void	draw_all(t_ctx *ctx)
{
	ft_bzero(ctx->screen->canevas->data, ctx->screen->canevas->width * ctx->screen->canevas->height * 4);
	t_list	*objects;
	t_list	*object;
	
	objects = ctx->scene->objects;
	object = objects;
	while (object)
	{
		draw_mesh(ctx, object->content);
		object = object->next;
	}
	mlx_put_image_to_window (ctx->mlx, ctx->screen->win, ctx->screen->canevas->id, 0, 0);	
}
