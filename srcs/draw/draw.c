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
			draw_mesh(ctx, object, &m2);
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
	int	delta_x;
	int	delta_y;

	if (ctx->mouse.button_right)
	{
		delta_x = ctx->mouse.last_x - ctx->mouse.x;
		delta_y = ctx->mouse.last_y - ctx->mouse.y;
		matrice_rotation_z(&ctx->map_obj->matrice, TO_RAD(delta_x)/5);
		matrice_rotation_x(&ctx->map_obj->matrice, TO_RAD(delta_y)/5);
		ctx->mouse.last_x = ctx->mouse.x;
		ctx->mouse.last_y = ctx->mouse.y;
	}
}

void	render(t_ctx *ctx)
{
	t_matrice4	m;

	matrice4_init(&m);
	draw_all(ctx, ctx->scene->objects, &m);
}

