/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:56:40 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/10 17:56:41 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H
# include "ctx.h"
# include "color.h"

void	put_pixel(t_img *canevas, int x, int y, t_color color);
void	draw_point(t_img *canevas, t_vector2 v, int size, t_color color);

#endif
