/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:56:01 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/22 19:38:48 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H
# include "color.h"

typedef struct	s_material
{
	t_color_rgba	color;
	t_color_rgba	color_b;
}				t_material;

t_material		*new_material(t_color_rgba color);
void			destroy_material(t_material *material);

#endif
