#include "graph.h"

t_graph	*new_graph(int length, int height)
{
	t_graph	*graph;

	graph = (t_graph*)malloc(sizeof(t_graph) + (sizeof(int) * length));
	graph->length = length;
	graph->height = height;

	return (graph);
}

