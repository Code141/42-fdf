#include "hud.h"

void	graph(t_ctx *ctx, int *fps, int size)
{
	char		*str;
	t_vector2	v1;
	t_vector2	v2;
	t_color		color;	

str = ft_itoa(ctx->stats->fps[0]);
	mlx_string_put(ctx->mlx, ctx->screen->win, 5, 0, 0xff0000, str);
	free(str);

	while (--size)
	{
		v1.x = 100 - size;
		v1.y = 50;
		v2.x = 100 - size;
		v2.y = fps[size];
		color.hex = 0xffffff;
		line(ctx->screen->canevas, v1, v2, color);
	}

}

void	hud(t_ctx *ctx)
{
	graph(ctx, ctx->stats->fps, 100);
}
