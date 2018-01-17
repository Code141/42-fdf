/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:37:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/17 19:38:19 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	update_all(t_ctx *ctx, t_list *object)
{
	(void)object;
	int	delta_x;
	int	delta_y;

	if (ctx->mouse->button[4])
	{
		matrice_multiply(&ctx->map_obj->mesh->matrice, 1.1);
		ctx->mouse->button[4] = 0;				
	}
	if (ctx->mouse->button[5])
	{
		matrice_multiply(&ctx->map_obj->mesh->matrice, 0.9);
		ctx->mouse->button[5] = 0;				
	}
	if (ctx->mouse->button[1])
	{
		delta_x = ctx->mouse->last_x - ctx->mouse->x;
		delta_y = ctx->mouse->last_y - ctx->mouse->y;
		matrice_rotation_z(&ctx->map_obj->matrice, TO_RAD(delta_x)/5);
		matrice_rotation_x(&ctx->map_obj->matrice, TO_RAD(delta_y)/5);
		ctx->mouse->last_x = ctx->mouse->x;
		ctx->mouse->last_y = ctx->mouse->y;
	}
//	if (ctx->keyboard->key[53])
//		close_fdf(ctx);
}

int		loop(t_ctx *ctx)
{
	update_all(ctx, ctx->scene->objects);

	ft_bzero(ctx->screen->canevas->data, ctx->screen->canevas->width * ctx->screen->canevas->height * 4);
	render(ctx);
	refresh_stats(ctx->stats);
	draw_hud(ctx);
	mlx_put_image_to_window (ctx->mlx, ctx->screen->win, ctx->screen->canevas->id, 0, 0);	
	return (1);	
}
