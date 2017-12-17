#include <time.h>
#include "mlx.h"
#include "ctx.h"

void	hud(t_ctx *ctx)
{
	ctx->frame++;
	if (ctx->timestamp != (int)time(NULL))
	{
		ctx->timestamp = (int)time(NULL);
		ctx->fps = ctx->frame;
		ctx->frame = 0;
	}
	mlx_string_put(ctx->mlx, ctx->win, 10, 10, 0xff0000, ft_itoa(ctx->fps));
}
