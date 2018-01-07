#ifndef HUD_H
# define HUD_H
# include "stats.h"
# include "graph.h"

typedef struct	s_hud
{
	t_graph	graphs[2];
}				t_hud;

t_hud	*new_hud();

#endif
