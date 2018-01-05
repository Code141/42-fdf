#ifndef STATS_H
# define STATS_H
# include <time.h>
# include <stdlib.h>

typedef	struct	s_stats
{
	int			timestamp;
	int			fps[100];
	int			ms[100];
	int			frame;
}				t_stats;

t_stats	*new_stats();
void	refresh_stats(t_stats *stats);

#endif
