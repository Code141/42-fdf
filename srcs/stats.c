#include "stats.h"

t_stats	*new_stats()
{
	t_stats	*stats;

	stats = (t_stats*)malloc(sizeof(t_stats));
	stats->timestamp = (int)time(NULL);
	stats->fps[0] = 0;
	stats->frame = 0;
	return (stats);
}

void	refresh_stats(t_stats *stats)
{
	stats->frame++;
	if (stats->timestamp != (int)time(NULL))
	{
		stats->timestamp = (int)time(NULL);
		stats->fps[0] = stats->frame;
		stats->frame = 0;
	}
}

void	array_shift_right(int *array, int size)
{
	while (size > 0)
	{
		array[size] = array[size - 1];
		size--;
	}
}


