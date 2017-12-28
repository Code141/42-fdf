#include <stdlib.h>
#include "mlx.h"
#include "libft.h"

#include "ctx.h"
#include "hooks.h"
#include "vector.h"
#include "matrice4.h"
#include "draw.h"
#include "object.h"
#include "scene.h"
#include "camera.h"
#include "mesh.h"
#include "geometry.h"
#include "plane.h"
#include "cube.h"
#include "surface.h"
#include "material.h"

int		close_fdf(t_ctx *ctx)
{
	free(ctx->screen->canevas);
	free(ctx->screen);
	destroy_scene(ctx->scene);
	free(ctx);
	ft_putstr("EXIT PROGRAMME");
	while (1)
	{}
	exit (0);
}

t_object	*grid_orientation(int x, int y, int subx, int suby)
{
	t_object	*obj;
	t_object	*grid;
	t_geometry	*geometry;
	t_material	*material;
	
	obj = new_object(NULL);
	geometry = new_surface(x, y, subx, suby);
	material = new_material(0x0000ff);
	grid = new_object(new_mesh(geometry, material));
	object_add_child(obj, grid);

	geometry = new_surface(x, y, subx, suby);
	material = new_material(0x00ff00);
	grid = new_object(new_mesh(geometry, material));
	matrice_rotation_x(&grid->mesh->matrice, TO_RAD(90));
	object_add_child(obj, grid);

	geometry = new_surface(x, y, subx, suby);
	material = new_material(0xff0000);
	grid = new_object(new_mesh(geometry, material));
	matrice_rotation_y(&grid->mesh->matrice, TO_RAD(90));
	object_add_child(obj, grid);
	return(obj);
}

	// PROTECTION DES MALLOCS !

int		main()
{
	t_ctx	*ctx;
	int		width;
	int		height;

	
	ctx = (t_ctx*)malloc(sizeof(t_ctx));
	ctx->mlx = mlx_init();

	ctx->screen = new_screen(ctx->mlx, 1024, 786);
	ctx->screen->canevas = new_canevas(ctx->mlx, 1024, 786);

/*--- SCENE / CAMERA ---------------------------------------------------------*/

	ctx->scene = new_scene();

	ctx->scene->camera = new_camera(TO_RAD(120), 10, 2000);
	ctx->scene->camera->pos.z = -500;

/*--- GEOMETRY ---------------------------------------------------------------*/

	t_geometry	*geometry;
	t_material	*material;
	t_object	*square_obj;

	geometry = new_cube(500, 25, 25);
	material = new_material(0xff0000);
 	square_obj = new_object(new_mesh(geometry, material));
	scene_add(ctx->scene, square_obj);

	geometry = new_cube(25, 500, 25);
	material = new_material(0x00ff00);
 	square_obj = new_object(new_mesh(geometry, material));
	scene_add(ctx->scene, square_obj);

	geometry = new_cube(25, 25, 500);
	material = new_material(0x0000ff);
 	square_obj = new_object(new_mesh(geometry, material));
	scene_add(ctx->scene, square_obj);

	geometry = new_cube(400, 400, 400);
	material = new_material(0xffffff);
 	square_obj = new_object(new_mesh(geometry, material));
	scene_add(ctx->scene, square_obj);

/*GRID*/

//	scene_add(ctx->scene, grid_orientation(700, 700, 10, 10));

/*--- LOOP -------------------------------------------------------------------*/

	hooks(ctx);
	mlx_loop(ctx->mlx);
	return (0);
}
