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
	free(ctx->screen->canevas);
	free(ctx->screen);
//	destroy_scene(ctx->scene);
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
	ctx->mlx = mlx_init();

	ctx->screen = new_screen(ctx->mlx, 1024, 786);

	ctx->stats = new_stats();

	ctx->hud = new_hud();
	ctx->hud->graphs[0] = new_graph(100, 60, ctx->stats->fps);
	ctx->hud->graphs[1] = new_graph(100, 60, ctx->stats->ms);
	ctx->hud->graphs[1]->color_min.hex = 0x00ffff;
	ctx->hud->graphs[1]->color_max.hex = 0xff0000;
	ctx->hud->graphs[1]->x = 102;

//	ctx->scene = new_scene();
	ctx->camera = new_camera(TO_RAD(120), 10, 100);
	ctx->camera->pos.z = 0;

	ctx->mouse = new_mouse();
	ctx->keyboard = new_keyboard();

	ctx->map = NULL;
	return (ctx);
}

void		load_map(t_ctx *ctx)
{
	t_object		*fdf_map;
	float			diag;
	float			size;
	t_color_rgba	c1;

	c1.hex = 0xffffff;
	fdf_map = new_fdf_map(ctx->map, c1);

	diag = hypot(ctx->map->width, ctx->map->height);
	size = ctx->screen->width / diag / 1.2;

	fdf_map->mesh->matrice.m[0] *= size;
	fdf_map->mesh->matrice.m[5] *= size;
	fdf_map->mesh->matrice.m[10] *= size / 4;

	t_vector4 v;
	v.x = 0;
	v.y = 0;
	v.z = 400;
	v.w = 0;
	matrice_translation(&fdf_map->matrice, &v);

	matrice_rotation_z_from_world(&fdf_map->mesh->matrice, TO_RAD(45));
	matrice_rotation_x_from_world(&fdf_map->mesh->matrice, TO_RAD(-60));

//	scene_add(ctx->scene, fdf_map);
	ctx->map_obj = fdf_map;
}

void		show_usage()
{
	ft_putstr("usage: fdf");
	ft_putendl(" [-R [-H | -L | -P]] [-fi | -n] [-apvX] target_file\n");
}

int		main(int argc, char **argv)
{
	t_ctx	*ctx;

	if (argc == 1)
	{
		show_usage();
		exit (0);
	}

	ctx = ctx_init();
	argc--;
	argv++;
	if (argc)
		ctx->map = parse_fdf_file(*argv);
	if (ctx->map)
		load_map(ctx);
	hooks(ctx);
	mlx_loop(ctx->mlx);
	return (0);
}
