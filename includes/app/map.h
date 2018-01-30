/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:05:15 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/17 14:40:51 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "geometry.h"
# include "object.h"
# include "surface2.h"

typedef struct	s_fdf_map
{
	char	*name;
	int		width;
	int		height;
	int		min;
	int		max;
	int		delta;
	int		**map;
	int		**color_map;
}				t_fdf_map;

t_object		*new_fdf_map(t_fdf_map *map, t_color_rgba color);
t_fdf_map		*new_map(char *file_name);
void			destroy_map(t_fdf_map *map);
void			map_delta(t_fdf_map *map);

#endif
