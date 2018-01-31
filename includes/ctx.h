/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:54:13 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/31 18:30:01 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H
# include "scene.h"
# include "screen.h"
# include "object.h"
# include "map.h"
# include "stats.h"
# include "hud.h"
# include "graph.h"
# include "camera.h"
# include "keyboard.h"
# include "mouse.h"

# define PI 3.14159265
# define RAD PI / 180
# define TO_RAD(x) ((x) * PI / 180.0)
# define TO_DEG(x) ((x) * 180.0 / PI)

typedef	struct	s_ctx
{
	void		*mlx;
	t_screen	*screen;
	t_stats		*stats;
	t_hud		*hud;
	t_mouse		*mouse;
	t_keyboard	*keyboard;
	t_scene		*scene;
	t_camera	*camera;
	t_fdf_map	*map;
	t_object	*map_obj;
}				t_ctx;

int				close_fdf(t_ctx *ctx);
void			crash(char *str);

#endif
