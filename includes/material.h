#ifndef MATERIAL_H
# define MATERIAL_H
# include "color.h"

typedef struct	s_material
{
	t_color	color;
}				t_material;

t_material	*new_material(int color);
void		destroy_material(t_material *material);

#endif
