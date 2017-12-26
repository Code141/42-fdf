#include "draw.h"

float	scalaire(float x, float y)
{
	int			a;
	int			b;
	t_vector2	v2;
	float		angle;

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

	v2.x = v1->x;
	v2.y = v1->y;

	v2.x += (ctx->screen->width / 2) + mesh->pos.x - ctx->scene->camera->pos.x;
	v2.y += (ctx->screen->height / 2) + mesh->pos.y - ctx->scene->camera->pos.y;
	
	return (v2);	
}

void	draw_vertices(t_ctx *ctx, t_object *object, t_matrice4 *m)
{
	int			i;
	t_mesh		*mesh;
	t_vector3	v1;
	t_vector2	v2;
	t_matrice4	m3;

	mesh = object->mesh;
	matrice_product(&mesh->matrice, m, &m3);
	i = 0;
	while (mesh->geometry->vertices[i])
	{
		
		v1 = matrice_apply(&m3, mesh->geometry->vertices[i]);
		v2 = projection(ctx, &v1, mesh);
		draw_point(ctx->screen->canevas, v2, 5, mesh->material->color);
		i++;
	}

}

void	draw_edges(t_ctx *ctx, t_object *object, t_matrice4 *m)
{

	int			i;
	t_vector3	v1a;
	t_vector3	v1b;
	t_vector2	v2a;
	t_vector2	v2b;
	t_mesh		*mesh;
	t_matrice4	m3;

	mesh = object->mesh;
	matrice_product(&mesh->matrice, m, &m3);
	i = 0;
	while (mesh->geometry->edges[i])
	{
		v1a = matrice_apply(&m3, mesh->geometry->edges[i]->vertices[0]);
		v1b = matrice_apply(&m3, mesh->geometry->edges[i]->vertices[1]);
		v2a = projection(ctx, &v1a, mesh);
		v2b = projection(ctx, &v1b, mesh);
		draw_line(ctx->screen->canevas, v2a, v2b, mesh->material->color);
		i++;
	}
}

void	draw_object(t_ctx *ctx, t_object *object, t_matrice4 *m)
{

	draw_edges(ctx, object, m);
	draw_vertices(ctx, object, m);
}

void	draw_all(t_ctx *ctx, t_list *elements, t_matrice4 *m1)
{
	t_mesh		*mesh;
	t_object	*object;
	t_matrice4	m2;

	while (elements)
	{
		object =  (t_object*)elements->content;
		matrice_product(m1, &object->matrice, &m2);
		mesh = object->mesh;
		if (mesh)
			draw_object(ctx, object, &m2);
		if (object->children)
		{
			matrice_product(m1, &object->matrice, &m2);
			draw_all(ctx, object->children, &m2);
		}
		elements = elements->next;
	}
}

void	update_all(t_ctx *ctx, t_list *object)
{
	//----------
	//----------
	//----------
}

void	render(t_ctx *ctx)
{
	t_matrice4	m;

	matrice4_init(&m);
	ft_bzero(ctx->screen->canevas->data, ctx->screen->canevas->width * ctx->screen->canevas->height * 4);
	draw_all(ctx, ctx->scene->objects, &m);
	mlx_put_image_to_window (ctx->mlx, ctx->screen->win, ctx->screen->canevas->id, 0, 0);	
	hud(ctx);
}
