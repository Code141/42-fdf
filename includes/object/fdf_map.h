/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:05:22 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/11 17:09:38 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MAP_H
# define FDF_MAP_H
# include <stdlib.h>
# include "geometry.h"
# include "object.h"
# include "input.h"
# include "surface2.h"

t_object	*new_fdf_map(t_fdf_map *map, t_color_rgba color);

#endif
