#include "mlx.h"
#include "libft.h"
#include "hooks.h"

#include "ctx.h"
#include "vector.h"
#include "draw.h"

int		key_release(int keycode, t_ctx *ctx)
{
	ft_putstr("Key Release : ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	return (1);	
}

int		key_press(int keycode, void *ctx)
{
	ft_putstr("Key Press : ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == 53)
		close_fdf(ctx);
	return (1);	
}


int		motion(int x, int y, t_ctx *ctx)
{
	printf("Mouse X:%d	Y:%d\n", x, y);
	return (1);
}

int		button_pressed(int button, int x, int y, t_ctx *ctx)
{
	printf("Mouse Button Pressed  : %d		X : %d	Y : %d\n", button, x, y);
	return (1);
}

int		button_release(int button, int x, int y, t_ctx *ctx)
{
	printf("Mouse Button Released : %d		X : %d	Y : %d\n", button, x, y);
	return (1);
}


int		expose_hook(void *ctx)
{
	ft_putstr("Expose_Hook\n");
	return (1);	
}

int		loop_hook(t_ctx *ctx)
{
	update_all(ctx, ctx->scene->objects);
	render(ctx);
	return (1);	
}

int		hooks(t_ctx *ctx)
{
	mlx_key_hook (ctx->screen->win, &key_release, ctx);
	mlx_mouse_hook (ctx->screen->win, &button_pressed, ctx);
	mlx_expose_hook (ctx->screen->win, &expose_hook, ctx);
	mlx_loop_hook (ctx->mlx, &loop_hook, ctx);

	mlx_hook(ctx->screen->win, KeyPress, KeyPressMask, &key_press, ctx);
	mlx_hook(ctx->screen->win, MotionNotify, PointerMotionMask, &motion, ctx);
	mlx_hook(ctx->screen->win, ButtonRelease, ButtonReleaseMask, &button_release, ctx);
	return (1);
}

