#ifndef GRAPH_H
# define GRAPH_H
# include <stdlib.h>
# include "libft.h"
# include "vector.h"
# include "color.h"
# include "screen.h"
# include "stats.h"
//# include "draw.h"

typedef struct	s_graph
{
	int	height;
	int	length;
	int	x;
	int y;
}				t_graph;

t_graph	*new_graph(int length, int height);

#endif
