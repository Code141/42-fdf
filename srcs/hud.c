#include <time.h>
#include "mlx.h"
#include "ctx.h"

void	hud(t_ctx *ctx)
{
	char	*str;
	ctx->frame++;
	if (ctx->timestamp != (int)time(NULL))
	{
		ctx->timestamp = (int)time(NULL);
		ctx->fps = ctx->frame;
		ctx->frame = 0;
	}
	str = ft_itoa(ctx->fps);
	mlx_string_put(ctx->mlx, ctx->screen->win, 5, 0, 0xff0000, str);
	free(str);
}
