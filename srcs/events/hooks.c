#include "mlx.h"
#include "libft.h"
#include "hooks.h"

#include "ctx.h"
#include "vector.h"
#include "draw.h"
#include "stats.h"
#include "hud.h"

/*--- KEYBOARD ---------------------------------------------------------------*/

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

/*--- MOUSE ------------------------------------------------------------------*/

int		mouse_move(int x, int y, t_ctx *ctx)
{
	ctx->mouse.x = x;
	ctx->mouse.y = y;
	return (1);
}

int		button_pressed(int button, int x, int y, t_ctx *ctx)
{
	if (y >= 0)
	{
		if (button == 1)
			ctx->mouse.button_right = 1;
		if (button == 2)
			ctx->mouse.button_left = 1;
		ctx->mouse.x = x;
		ctx->mouse.y = y;
		ctx->mouse.last_x = x;
		ctx->mouse.last_y = y;
		if (button == 4)
			matrice_multiply(&ctx->map_obj->mesh->matrice, 1.1);
		if (button == 5)
			matrice_multiply(&ctx->map_obj->mesh->matrice, 0.9);
	}
	return (1);
}

int		button_release(int button, int x, int y, t_ctx *ctx)
{
	if (button == 1)
		ctx->mouse.button_right = 0;
	if (button == 2)
		ctx->mouse.button_left = 0;
	return (1);
}

/*--- MLX --------------------------------------------------------------------*/

int		expose_hook(void *ctx)
{
	ft_putstr("Expose_Hook\n");
	return (1);	
}

int		loop_hook(t_ctx *ctx)
{
	main_loop();
	return (1);	
}

int		hooks(t_ctx *ctx)
{
	mlx_hook(ctx->screen->win, KeyPress, KeyPressMask, &key_press, ctx);
	mlx_hook(ctx->screen->win, KeyRelease, KeyReleaseMask, &key_release, ctx);



	mlx_hook(ctx->screen->win, ButtonRelease, ButtonReleaseMask, &button_release, ctx);
	mlx_hook(ctx->screen->win, ButtonPress, ButtonPressMask, &button_pressed, ctx);
	mlx_hook(ctx->screen->win, MotionNotify, PointerMotionMask, &mouse_move, ctx);







//	mlx_mouse_hook (ctx->screen->win, &button_pressed, ctx);
	mlx_expose_hook (ctx->screen->win, &expose_hook, ctx);
	mlx_loop_hook (ctx->mlx, &loop_hook, ctx);


	return (1);
}
