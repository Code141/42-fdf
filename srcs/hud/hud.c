#include "hud.h"

t_hud	*new_hud()
{
	t_hud	*hud;

	hud = (t_hud*)malloc(sizeof(t_hud));
	return (hud);
}
