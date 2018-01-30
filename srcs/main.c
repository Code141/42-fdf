#include <stdlib.h>
#include "mlx.h"
#include "libft.h"

#include "ctx.h"
#include "input.h"
#include "events.h"
#include "vector.h"
#include "matrice4.h"
#include "draw.h"
#include "object.h"
#include "scene.h"
#include "camera.h"
#include "mesh.h"
#include "map.h"
#include "geometry.h"
#include "plane.h"
#include "cube.h"
#include "surface.h"
#include "surface2.h"
#include "material.h"
#include "mouse.h"
#include "keyboard.h"

// PROTECTION DES MALLOCS !

int		close_fdf(t_ctx *ctx)
{
	if (ctx->screen)
	{
		if (ctx->screen->canevas)
			free(ctx->screen->canevas);
		mlx_destroy_window( ctx->mlx, ctx->screen->win);
		free(ctx->screen);
	}
	if (ctx->map)
		destroy_map(ctx->map);
	
	destroy_hud(ctx->hud);
	destroy_camera(ctx->camera);
	destroy_mouse(ctx->mouse);
	destroy_keyboard(ctx->keyboard);

	free(ctx->stats);
	free(ctx);
	ft_putstr("EXIT PROGRAMME");
	while (1)
	{}
	exit (0);
}

t_ctx	*ctx_init()
{
	t_ctx	*ctx;

	ctx = (t_ctx*)malloc(sizeof(t_ctx));
	if (!ctx)
		close_fdf(ctx);
	ft_bzero(ctx, sizeof(t_ctx));

	ctx->mlx = mlx_init();
	if (!ctx->mlx)
		close_fdf(ctx);	

	ctx->screen = new_screen(ctx->mlx, 1024, 786);

	ctx->stats = new_stats();

	ctx->hud = new_hud();
	ctx->hud->graphs[0] = new_graph(100, 60, ctx->stats->fps);
	ctx->hud->graphs[1] = new_graph(100, 60, ctx->stats->ms);
	ctx->hud->graphs[1]->color_min.hex = 0x00ffff;
	ctx->hud->graphs[1]->color_max.hex = 0xff0000;
	ctx->hud->graphs[1]->x = 102;

	ctx->camera = new_camera(TO_RAD(120), 10, 100);
	ctx->camera->pos.z = 0;

	ctx->mouse = new_mouse();
	ctx->keyboard = new_keyboard();

	ctx->map = NULL;
	ctx->map_obj = NULL;
	hooks(ctx);
	return (ctx);
}

t_object		*load_map(t_fdf_map *map, int screen_width)
{
	t_object		*fdf_map;
	t_color_rgba	c1;
	t_vector4		v;
	float			size;

	c1.hex = 0xffffff;
	fdf_map = new_fdf_map(map, c1);

	size = screen_width / hypot(map->width, map->height) / 1.2;
	fdf_map->mesh->matrice.m[0] *= size;
	fdf_map->mesh->matrice.m[5] *= size;
	fdf_map->mesh->matrice.m[10] *= size/5;
	v.x = 0;
	v.y = 0;
	v.z = 600;
	v.w = 0;
	matrice_translation(&fdf_map->matrice, &v);
	matrice_rotation_z_from_world(&fdf_map->mesh->matrice, TO_RAD(45));
	matrice_rotation_x_from_world(&fdf_map->mesh->matrice, TO_RAD(-45));
	return (fdf_map);
}

void		show_usage()
{
	ft_putstr("usage: fdf");
	ft_putstr(" target_file\n");
	exit (0);
}

int		main(int argc, char **argv)
{
	t_ctx		*ctx;
	t_fdf_map	*map;

	argc--;
	argv++;
	if (argc != 1)
		show_usage();
	ctx = ctx_init();
	map = parse_fdf_file(*argv);
	if (map)
		ctx->map_obj = load_map(map, ctx->screen->width);
	else
		close_fdf(ctx);
	if (ctx->map_obj)
		mlx_loop(ctx->mlx);
	else
		close_fdf(ctx);
	return (0);
}
