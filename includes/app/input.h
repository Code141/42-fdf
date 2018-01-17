/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:54:27 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/10 17:54:29 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "map.h"

t_fdf_map	*parse_fdf_file(char *file_name);

#endif
