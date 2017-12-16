#ifndef MATERIAL_H
# define MATERIAL_H

typedef struct	s_material
{
	int	color;
}				t_material;

t_material	*new_material(int color);

#endif
