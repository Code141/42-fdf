#ifndef CTX_H
# define CTX_H
# include "scene.h"
# include "object.h"
# include "screen.h"
# include "map.h"
# include "stats.h"
# include "hud.h"
# include "graph.h"

# define PI 3.14159265
# define RAD PI / 180
# define TO_RAD(x) ((x) * PI / 180.0)
# define TO_DEG(x) ((x) * 180.0 / PI)

typedef	struct	s_ctx
{
	void		*mlx;
	t_screen	*screen;
	t_scene		*scene;
	t_fdf_map	*map;
	t_object	*map_obj;
	t_stats		*stats;
	t_hud		*hud;
}				t_ctx;

int				close_fdf(t_ctx *ctx);

#endif
