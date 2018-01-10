#include "graph.h"

t_graph	*new_graph(int length, int height, int *data)
{
	t_graph	*graph;

	graph = (t_graph*)malloc(sizeof(t_graph));
	graph->length = length;
	graph->height = height;
	graph->data = data;
	graph->x = 0;
	graph->y = 0;
	return (graph);
}
