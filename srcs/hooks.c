#include "mlx.h"
#include "libft.h"

#include "ctx.h"
#include "vector.h"
#include "draw.h"
#include "hud.h"

int		key_hook(int keycode, void *ctx)
{
	ft_putstr("Key : ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == 53)
		close_fdf();
	return (1);	
}

int		mouse_hook(int button, int x, int y, t_ctx *ctx)
{
	ft_putstr("Mouse : ");
	ft_putnbr(button);
	ft_putstr("\n  X : ");
	ft_putnbr(x);
	ft_putstr("\n  Y : ");
	ft_putnbr(y);
	ft_putstr("\n");

	t_scene	*scene;
	scene = ctx->scene;

	t_geometry	*geometry;
	t_material	*material;
	t_mesh		*square;

	geometry = new_plane(100, 100);
	material = new_material(0xffffff);

	square = new_mesh(geometry, material);
	square->pos.x = x - ctx->width / 2;
	square->pos.y = y - ctx->height / 2;
	scene_add(ctx->scene, square);



	return (1);
}

int		expose_hook(void *ctx)
{
	ft_putstr("Expose_Hook\n");
	return (1);	
}

int		loop_hook(t_ctx *ctx)
{
	mlx_clear_window(ctx->mlx, ctx->win);
	draw_all(ctx);
	hud(ctx);
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
