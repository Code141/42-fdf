#ifndef MATRICE4_H
# define MATRICE4_H
#include "vector.h"

typedef struct s_matrice4
{
	float	m[16];
}				t_matrice4;

void		matrice4_init(t_matrice4 *m);
t_vector3	matrice_apply(t_vector3 *p, t_matrice4 *m);
t_matrice4	*matrice_product(t_matrice4 *m1, t_matrice4 *m2);
t_matrice4	*matrice_translation(t_matrice4 *m1, t_vector3 *v);
t_matrice4	*matrice_rotation_x(t_matrice4 *m, float angle);
t_matrice4	*matrice_rotation_y(t_matrice4 *m, float angle);
t_matrice4	*matrice_rotation_z(t_matrice4 *m, float angle);

#endif
