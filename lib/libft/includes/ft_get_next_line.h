/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:23:38 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/03 19:07:13 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include "libft.h"
# ifndef BUFF_SIZE
#  define BUFF_SIZE 64
# endif

typedef struct	s_file
{
	int				fd;
	int				status;
	t_list			*save;
}				t_file;

int				ft_get_next_line(const int fd, char **line);

#endif
