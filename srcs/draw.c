#include "mlx.h"
#include "vector.h"
#include "ctx.h"
#include "pixel.h"

void	draw_squar(t_ctx *ctx, t_object *object)
{
	int	x;
	int	y;

	y = 0;
	while (y < object->geometry->size.y)
	{
		x = 0;
		while (x < object->geometry->size.x)
		{
			put_pixel(
				ctx->canevas,
				(ctx->width / 2) + object->pos.x + x - ctx->scene->camera->pos.x,
				(ctx->height / 2) + object->pos.y + y - ctx->scene->camera->pos.y,
				object->material->color
			);
			x++;
		}
		y++;	
	}
	object->pos.x /= 1.01;
	object->pos.y /= 1.01;

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
		draw_squar(ctx, object->content);
		object = object->next;
	}
	mlx_put_image_to_window (ctx->mlx, ctx->win, ctx->canevas->id, 0, 0);	
}
