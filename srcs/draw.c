#include "mlx.h"
#include "vector.h"
#include "ctx.h"

void	draw_squar(t_ctx *ctx, t_object *object)
{
	int	x;
	int	y;

	y = 0;
	while (y < object->geometry->size->y)
	{
		x = 0;
		while (x < object->geometry->size->x)
		{
			mlx_pixel_put(
				ctx->mlx,
				ctx->win,
				object->pos->x + x,
				object->pos->y + y,
				object->material->color
			);
			x++;
		}
		y++;	
	}
}

void	draw_all(t_ctx *ctx)
{
	t_list	*objects;
	t_list	*object;

	objects = ctx->scene->objects;
	object = objects;
	while (object)
	{
		draw_squar(ctx, object->content);
		object = object->next;
	}
}


