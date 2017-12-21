#ifndef DRAW_H
# define DRAW_H
# include <math.h>
# include <stdio.h>
# include "mlx.h"
# include "ctx.h"
# include "vector.h"
# include "pixel.h"

# define PI 3.14159265
# define RAD PI / 180
# define TO_RAD(x) ((x) * PI / 180.0)
# define TO_DEG(x) ((x) * 180.0 / PI)

void	draw_mesh(t_ctx *ctx, t_mesh *object);
void	draw_all(t_ctx *ctx);

#endif
