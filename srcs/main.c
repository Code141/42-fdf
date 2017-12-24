#include <stdlib.h>
#include "mlx.h"
#include "libft.h"

#include "ctx.h"
#include "hooks.h"
#include "vector.h"
#include "matrice4.h"
#include "draw.h"
#include "scene.h"
#include "camera.h"
#include "mesh.h"
#include "geometry.h"
#include "material.h"

int		close_fdf()
{
	ft_putstr("EXIT PROGRAMME");
	while (1)
	{}
	exit (0);
}

int		main()
{
	t_ctx	*ctx;
	int		width;
	int		height;

	width = 1024;
	height = 786;

	ctx = (t_ctx*)malloc(sizeof(t_ctx));
	ctx->mlx = mlx_init();

	ctx->screen = (t_screen*)malloc(sizeof(t_screen));
	ctx->screen->width = width;
	ctx->screen->height = height;
	ctx->screen->ar = width / height;

	ctx->screen->win = mlx_new_window(ctx->mlx, ctx->screen->width, ctx->screen->height, "FdF");

	hooks(ctx);

	ctx->scene = new_scene();


/*---CAMERA-------------------------------------------------------------------*/

	ctx->scene->camera = new_camera();
	ctx->scene->camera->pos.x = 0;
	ctx->scene->camera->pos.y = 0;
	ctx->scene->camera->pos.z = -500;
	ctx->scene->camera->angle = 2 * 3.14159265 / 3; // 120 DEG
	ctx->scene->camera->near = 10;
	ctx->scene->camera->far = 2000;

/*---GEOMETRY-----------------------------------------------------------------*/

	t_geometry	*geometry;
	t_material	*material;
	t_mesh		*square;
/*
	geometry = new_cube(500, 25, 25);
	material = new_material(0xff0000);
	square = new_mesh(geometry, material);
	scene_add(ctx->scene, square);

	geometry = new_cube(25, 500, 25);
	material = new_material(0x00ff00);
	square = new_mesh(geometry, material);
	scene_add(ctx->scene, square);

	geometry = new_cube(25, 25, 500);
	material = new_material(0x0000ff);
	square = new_mesh(geometry, material);
	scene_add(ctx->scene, square);
*/
	geometry = new_cube(50, 50, 50);
	material = new_material(0xffffff);
	square = new_mesh(geometry, material);
	scene_add(ctx->scene, square);



	geometry = new_surface(200, 200, 2, 2);
	material = new_material(0x0000ff);
	square = new_mesh(geometry, material);
	square->matrice = matrice_rotation_z(square->matrice, TO_RAD(90));
	scene_add(ctx->scene, square);

	geometry = new_surface(200, 200, 3, 3);
	material = new_material(0xff0000);
	square = new_mesh(geometry, material);
	square->matrice = matrice_rotation_y(square->matrice, TO_RAD(90));
	scene_add(ctx->scene, square);

	geometry = new_surface(200, 200, 5, 5);
	material = new_material(0x00ff00);
	square = new_mesh(geometry, material);
	square->matrice = matrice_rotation_x(square->matrice, TO_RAD(90));
	scene_add(ctx->scene, square);

	

/*---IMG----------------------------------------------------------------------*/

	int		bits_per_pixel;
	int		size_line;
	int		endian;

	ctx->screen->canevas = (t_img*)malloc(sizeof(t_img));
	ctx->screen->canevas->width = ctx->screen->width;
	ctx->screen->canevas->height = ctx->screen->height;
	ctx->screen->canevas->id = mlx_new_image(ctx->mlx, ctx->screen->canevas->width, ctx->screen->canevas->height);
	size_line = ctx->screen->canevas->width;
	ctx->screen->canevas->data = mlx_get_data_addr(ctx->screen->canevas->id, &bits_per_pixel, &size_line, &endian);

	mlx_loop(ctx->mlx);
	return (0);
}
