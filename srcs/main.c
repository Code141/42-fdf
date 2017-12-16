#include "mlx.h"
#include "libft.h"

#include "ctx.h"
#include "hooks.h"
#include "vector.h"
#include "draw.h"
#include "scene.h"
#include "object.h"
#include "geometry.h"
#include "material.h"

int		main()
{
	t_ctx	ctx;

	ctx.mlx = mlx_init();
	ctx.width = 256;
	ctx.height = 256;
	ctx.win = mlx_new_window(ctx.mlx, ctx.width, ctx.height, "FdF");

	hooks(&ctx);

	ctx.scene = new_scene();

	t_geometry	*geometry;
	t_material	*material;
	t_object	*square;

	geometry = new_square(10, 10, 10);
	material = new_material(0xff0000);

	square = new_object(geometry, material);
	square->pos->x = 10;
	square->pos->y = 10;

	scene_add(ctx.scene, square);


	mlx_loop(ctx.mlx);
	return (0);
}
