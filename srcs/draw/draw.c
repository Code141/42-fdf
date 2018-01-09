#include "draw.h"
#include "bresenham_line.h"

t_vector2	projection(t_ctx *ctx, t_vector3 *v1, t_mesh *mesh)
{
	t_vector2	v2;
	float		hypo;
	t_vector3	angle;

	v2.x = v1->x;
	v2.y = v1->y;

	v2.x += (ctx->screen->width / 2);
	v2.y += (ctx->screen->height / 2);
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
	t_vector3	v1a;
	t_vector3	v1b;
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
		v2a = projection(ctx, &v1a, mesh);
		v2b = projection(ctx, &v1b, mesh);
		line(ctx->screen->canevas, v2a, v2b, mesh->material->color);
		i++;
	}
}

void	draw_object(t_ctx *ctx, t_object *object, t_matrice4 *m)
{
	draw_edges(ctx, object, m);
//	draw_vertices(ctx, object, m);
}

void	draw_all(t_ctx *ctx, t_list *elements, t_matrice4 *m1)
{
	t_mesh		*mesh;
	t_object	*object;
	t_matrice4	m2;

	while (elements)
	{
		object =  (t_object*)elements->content;
		matrice_product(&object->matrice, m1, &m2);
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
	matrice_rotation_z(&ctx->map_obj->matrice, TO_RAD(0.5));
}

void	render(t_ctx *ctx)
{
	t_matrice4	m;

	matrice4_init(&m);
	draw_all(ctx, ctx->scene->objects, &m);
}

void	draw_graph(t_graph *graph, t_img *canevas, int	*data)
{
	t_vector2	v1;
	t_vector2	v2;
	t_color		color;	
	int			i;
	int			c;

	i = 0;
	color.hex = 0x0000;
	while (i < graph->length)
	{
		v1.x = graph->length - i;
		v1.y = graph->height - data[i];
		v2.x = graph->length - i;
		v2.y = graph->height;
		color.c.g = data[i] * 255 / 60;
		color.c.r = 255 - data[i] * 255 / 60;
		line(canevas, v1, v2, color);
		i++;
	}
}

void	draw_hud(t_ctx *ctx)
{
	draw_graph(&ctx->hud->graphs[0], ctx->screen->canevas, ctx->stats->fps);
}
