/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:05:15 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/10 18:05:16 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

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

t_fdf_map		*new_map(char *file_name);
void			destroy_map(t_fdf_map *map);
void			map_delta(t_fdf_map *map);

#endif
