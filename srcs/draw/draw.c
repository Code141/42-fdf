#include "draw.h"
#include "bresenham_line.h"

t_vector2	projection(t_ctx *ctx, t_vector4 *v1, t_mesh *mesh)
{
	(void)mesh;
	t_vector2	v2;
	float		normal_z;
	
	normal_z = v1->z / (ctx->camera->far - ctx->camera->near);
	v2.x = ctx->camera->near * v1->x / normal_z;
	v2.y = ctx->camera->near * v1->y / normal_z; 
	v2.x += (ctx->screen->width / 2);
	v2.y += (ctx->screen->height / 2);
	return (v2);	
}

t_vector2	iso_projection(t_ctx *ctx, t_vector4 *v1, t_mesh *mesh)
{
	(void)mesh;
	t_vector2	v2;

	v2.x = v1->x;
	v2.y = v1->y;
	v2.x += (ctx->screen->width / 2);
	v2.y += (ctx->screen->height / 2);
	return (v2);	
}

void	draw_all(t_ctx *ctx, t_list *elements, t_matrice4 *m1)
{
	t_mesh		*mesh;
	t_object	*object;
	t_matrice4	m2;

	while (elements)
	{
		object = (t_object*)elements->content;
		matrice_product(&object->matrice, m1, &m2);
		mesh = object->mesh;
		if (mesh)
			draw_mesh(ctx, object, &m2);
		if (object->children)
			draw_all(ctx, object->children, &m2);
		elements = elements->next;
	}
}

void	render(t_ctx *ctx)
{
	t_matrice4	m;

	matrice4_init(&m);
	draw_all(ctx, ctx->scene->objects, &m);
}
