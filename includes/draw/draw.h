#ifndef DRAW_H
# define DRAW_H
# include <math.h>
# include <stdio.h>
# include "mlx.h"
# include "ctx.h"
# include "vector.h"
# include "matrice4.h"
# include "pixel.h"

void	draw_mesh(t_ctx *ctx, t_mesh *object);
void	draw_all(t_ctx *ctx, t_list *elements, t_matrice4 *m);
void	update_all(t_ctx *ctx, t_list *object);
void	render(t_ctx *ctx);

#endif
