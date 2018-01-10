#include "hud.h"

t_hud	*new_hud()
{
	t_hud	*hud;

	hud = (t_hud*)malloc(sizeof(t_hud));
	return (hud);
}

void	destroy_hud(t_hud* hud)
{
	free(hud->graphs[0]);
	free(hud->graphs[1]);
	free(hud);
}
