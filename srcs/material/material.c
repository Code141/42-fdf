#include <stdlib.h>
#include "material.h"

t_material	*new_material(int color)
{
	t_material	*material;

	material = (t_material*)malloc(sizeof(t_material));
	material->color.hex = color;
	return (material);
}

void	destroy_material(t_material *material)
{
	free(material);
}
