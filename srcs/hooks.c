#include "mlx.h"
#include "libft.h"

#include "ctx.h"
#include "vector.h"
#include "draw.h"

int		key_hook(int keycode, void *ctx)
{
	ft_putstr("Key : ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	return (1);	
}

int		mouse_hook(int button, int x, int y, void *ctx)
{
	ft_putstr("Mouse : ");
	ft_putnbr(button);
	ft_putstr("\n  X : ");
	ft_putnbr(x);
	ft_putstr("\n  Y : ");
	ft_putnbr(y);
	ft_putstr("\n");
	return (1);
}

int		expose_hook(void *ctx)
{
	ft_putstr("Expose_Hook\n");
	return (1);	
}

int		loop_hook(void *ctx)
{
	draw_all(ctx);
//	ft_putstr("Loop_Hook\n");
	return (1);	
}

int		hooks(t_ctx *ctx)
{
	mlx_key_hook (ctx->win, &key_hook, ctx);
	mlx_mouse_hook (ctx->win, &mouse_hook, ctx);
	mlx_expose_hook (ctx->win, &expose_hook, ctx);
	mlx_loop_hook (ctx->mlx, &loop_hook, ctx);
	return (1);
}
