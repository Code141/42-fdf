#include "mlx.h"
#include "vector.h"
#include "ctx.h"
#include "pixel.h"


#include <math.h>
#include <stdio.h>
#define PI 3.14159265
#define RAD PI / 180

void	draw_vertices(t_ctx *ctx, t_mesh *mesh)
{
	int			i;
	int			x;
	int			y;
	t_vector2 v;

	i = 0;
	while (mesh->geometry->vertices[i])
	{
		v.x = mesh->geometry->vertices[i]->x;
		v.y = mesh->geometry->vertices[i]->y;

float hypo;
float angle;
hypo = hypot(v.x, v.y);


angle = (90 * (i + 1));

angle = tan(v.x/v.y);


v.x = cos((angle + mesh->rot.z) * RAD ) * hypo;
v.y = sin((angle + mesh->rot.z) * RAD ) * hypo;

if (i == 0)
	printf("%f\n", mesh->rot.z);



		v.x += (ctx->width / 2) + mesh->pos.x - ctx->scene->camera->pos.x;
		v.y += (ctx->height / 2) + mesh->pos.y - ctx->scene->camera->pos.y;
		draw_point(ctx->canevas, v, 5, mesh->material->color + (0xff*i*(255*i+1)) );
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
		v1.x = mesh->geometry->edges[i]->vertices[0]->x;
		v1.y = mesh->geometry->edges[i]->vertices[0]->y;

		v1.x += (ctx->width / 2) + mesh->pos.x - ctx->scene->camera->pos.x;
		v1.y += (ctx->height / 2) + mesh->pos.y - ctx->scene->camera->pos.y;


		v2.x = mesh->geometry->edges[i]->vertices[1]->x;
		v2.y = mesh->geometry->edges[i]->vertices[1]->y;

		v2.x += (ctx->width / 2) + mesh->pos.x - ctx->scene->camera->pos.x;
		v2.y += (ctx->height / 2) + mesh->pos.y - ctx->scene->camera->pos.y;
		draw_line(ctx->canevas, v1, v2, mesh->material->color);
		i++;
	}
}

void	draw_mesh(t_ctx *ctx, t_mesh *mesh)
{
	draw_edges(ctx, mesh);
	draw_vertices(ctx, mesh);
	mesh->pos.x /= 1.01;
	mesh->pos.y /= 1.01;
	mesh->rot.z = mesh->rot.z + 0.50;
	if (mesh->rot.z > 360)
		mesh->rot.z -= 360;
}

void	draw_all(t_ctx *ctx)
{
	ft_bzero(ctx->canevas->data, ctx->canevas->width * ctx->canevas->height * 4);
	t_list	*objects;
	t_list	*object;
	
	objects = ctx->scene->objects;
	object = objects;
	while (object)
	{
		draw_mesh(ctx, object->content);
		object = object->next;
	}
	mlx_put_image_to_window (ctx->mlx, ctx->win, ctx->canevas->id, 0, 0);	
}
