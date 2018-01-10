/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:52:59 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/10 20:59:55 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_hud.h"

void	draw_graph(t_graph *graph, t_img *canevas)
{
	t_vector2	v1;
	t_vector2	v2;
	t_color		color;
	int			i;

	i = 0;
	color.hex = 0x0000;
	while (i < graph->length)
	{
		v1.x = graph->x + graph->length - i;
		v1.y = graph->y + graph->height - graph->data[i];
		v2.x = graph->x + graph->length - i;
		v2.y = graph->y + graph->height;
		color.c.g = graph->data[i] * 255 / 60;
		color.c.r = 255 - graph->data[i] * 255 / 60;
		line(canevas, v1, v2, color);
		i++;
	}
}

void	draw_hud(t_ctx *ctx)
{
	draw_graph(ctx->hud->graphs[0], ctx->screen->canevas);
	draw_graph(ctx->hud->graphs[1], ctx->screen->canevas);
}
