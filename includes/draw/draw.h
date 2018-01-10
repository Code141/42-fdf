/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:54:50 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/10 17:54:53 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include <math.h>
# include <stdio.h>
# include "mlx.h"
# include "ctx.h"
# include "vector.h"
# include "matrice4.h"
# include "pixel.h"
# include "hud.h"
# include "draw_mesh.h"
# include "bresenham_line.h"

t_vector2	projection(t_ctx *ctx, t_vector3 *v1, t_mesh *mesh);
void		draw_all(t_ctx *ctx, t_list *elements, t_matrice4 *m);
void		update_all(t_ctx *ctx, t_list *object);
void		render(t_ctx *ctx);
void		draw_hud(t_ctx *ctx);

#endif
