#include "draw.h"
#include "bresenham_line.h"

t_vector2	projection(t_ctx *ctx, t_vector3 *v1, t_mesh *mesh)
{
	(void)mesh;
	t_vector2	v2;

	v2.x = v1->x;
	v2.y = v1->y;

//	v2.x *= v1->z / 100; calculer le ratio NEAR FAR de la camera, et la position du Z dans ce ratio
//	v2.y *= v1->z / 100;

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
		{
			matrice_product(m1, &object->matrice, &m2);
			draw_all(ctx, object->children, &m2);
		}
		elements = elements->next;
	}
}

void	render(t_ctx *ctx)
{
	t_matrice4	m;

	matrice4_init(&m);
	draw_all(ctx, ctx->scene->objects, &m);
}
