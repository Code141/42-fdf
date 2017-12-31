#include <stdlib.h>
#include "mlx.h"
#include "libft.h"

#include "ctx.h"
#include "input.h"
#include "hooks.h"
#include "vector.h"
#include "matrice4.h"
#include "draw.h"
#include "object.h"
#include "scene.h"
#include "camera.h"
#include "mesh.h"
#include "fdf_map.h"
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

int		main(int argc, char **argv)
{

/*--- INPUT ------------------------------------------------------------------*/
	argc--;
	argv++;

	t_fdf_map	*map;
	t_object	*fdf_map;

	map = NULL;
	if (argc)
	{
		map = parse_fdf_file(*argv);
	}


/*--- INIT -------------------------------------------------------------------*/

	t_ctx	*ctx;
	int		width;
	int		height;

	ctx = (t_ctx*)malloc(sizeof(t_ctx));
	ctx->mlx = mlx_init();

	ctx->screen = new_screen(ctx->mlx, 1024, 786);
	ctx->screen->canevas = new_canevas(ctx->mlx, 1024, 786);

/*--- SCENE / CAMERA ---------------------------------------------------------*/

	ctx->scene = new_scene();

	//SORTIRE LA CAMERA DE LA SCENE ??
	ctx->scene->camera = new_camera(TO_RAD(120), 10, 2000);
	ctx->scene->camera->pos.z = -500;

/*--- GEOMETRY ---------------------------------------------------------------*/


	if (map)
	{
		printf("NAME : %s\nH : %d	W : %d\n", map->name, map->height, map->width);
		fdf_map = new_fdf_map(map, 0xff0000);
		matrice_rotation_x(&fdf_map->matrice, TO_RAD(45));
		matrice_rotation_z(&fdf_map->mesh->matrice, TO_RAD(45));
		matrice_rotation_y(&fdf_map->mesh->matrice, TO_RAD(90));
		scene_add(ctx->scene, fdf_map);

		fdf_map = new_fdf_map(map, 0x0000ff);
		matrice_rotation_x(&fdf_map->matrice, TO_RAD(45));
		matrice_rotation_z(&fdf_map->mesh->matrice, TO_RAD(45));
		matrice_rotation_x(&fdf_map->mesh->matrice, TO_RAD(90));
		scene_add(ctx->scene, fdf_map);
	
		fdf_map = new_fdf_map(map, 0x00ff00);
		matrice_rotation_x(&fdf_map->matrice, TO_RAD(45));
		matrice_rotation_z(&fdf_map->mesh->matrice, TO_RAD(45));
		scene_add(ctx->scene, fdf_map);
	
	}

/*--- LOOP -------------------------------------------------------------------*/

	hooks(ctx);
	mlx_loop(ctx->mlx);
	return (0);
}
