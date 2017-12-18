#include <stdlib.h>
#include "mlx.h"
#include "libft.h"

#include "ctx.h"
#include "hooks.h"
#include "vector.h"
#include "draw.h"
#include "scene.h"
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
	height = 1024;

	ctx = (t_ctx*)malloc(sizeof(t_ctx) + (sizeof(int) * (width * height)));
	ctx->mlx = mlx_init();
	ctx->width = width;
	ctx->height = height;
	ctx->win = mlx_new_window(ctx->mlx, ctx->width, ctx->height, "FdF");
	hooks(ctx);

	ctx->scene = new_scene();


/*---CAMERA-----------------------------------------------------------------*/

	ctx->scene->camera->pos.x = 0;
	ctx->scene->camera->pos.y = 0;
	
/*---GEOMETRY---------------------------------------------------------------*/

	t_geometry	*geometry;
	t_material	*material;
	t_mesh		*square;

	geometry = new_plane(10, 10);
	material = new_material(0xff0000);

	square = new_mesh(geometry, material);
	square->pos.x = 0;
	square->pos.y = 0;
	scene_add(ctx->scene, square);

/*---IMG--------------------------------------------------------------------*/

	int		bits_per_pixel;
	int		size_line;
	int		endian;

	ctx->canevas = (t_img*)malloc(sizeof(t_img));
	ctx->canevas->width = ctx->width;
	ctx->canevas->height = ctx->height;
	ctx->canevas->id = mlx_new_image(ctx->mlx, ctx->canevas->width, ctx->canevas->height);
	size_line = ctx->canevas->width;
	ctx->canevas->data = mlx_get_data_addr(ctx->canevas->id, &bits_per_pixel, &size_line, &endian);



	mlx_loop(ctx->mlx);
	return (0);
}
