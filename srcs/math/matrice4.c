#include <stdlib.h>
#include <math.h>
#include "matrice4.h"
#include "vector.h"

void	matrice4_init(t_matrice4 *m)
{
	m->m[0] = 1;
	m->m[1] = 0;
	m->m[2] = 0;
	m->m[3] = 0;
	m->m[4] = 0;
	m->m[5] = 1;
	m->m[6] = 0;
	m->m[7] = 0;
	m->m[8] = 0;
	m->m[9] = 0;
	m->m[10] = 1;
	m->m[11] = 0;
	m->m[12] = 0;
	m->m[13] = 0;
	m->m[14] = 0;
	m->m[15] = 1;
}

t_vector3	matrice_apply(t_vector3 *p, t_matrice4 *m)
{
	t_vector3	p2;

	p2.x = (p->x * m->m[0]) + (p->y * m->m[1]) + (p->z * m->m[2]) + m->m[3];
	p2.y = (p->x * m->m[4]) + (p->y * m->m[5]) + (p->z * m->m[6]) + m->m[7];
	p2.z = (p->x * m->m[8]) + (p->y * m->m[9]) + (p->z * m->m[10]) + m->m[11];
//	p2.w = (p->x * m->m[12]) + (p->y * m->m[13]) + (p->z * m->m[14]) + m->m[15];
	return (p2);
}

void	matrice_multiply(t_matrice4 *m1, t_matrice4 *m2)
{
	int			i;
	t_matrice4	*m3;

	i = 0;
	while (i < 16)
	{
		m1->m[i] *= m2->m[i];
		i++;
	}
}

void	matrice_add(t_matrice4 *m1, t_matrice4 *m2)
{
	int			i;

	i = 0;
	while (i < 16)
	{
		m1->m[i] +=  m2->m[i];
		i++;
	}
}

void	matrice_translation(t_matrice4 *m1, t_vector3 *v)
{
	t_matrice4 m2;

	m2.m[0] = 0;
	m2.m[1] = 0;
	m2.m[2] = 0;
	m2.m[3] = v->x;
	m2.m[4] = 0;
	m2.m[5] = 0;
	m2.m[6] = 0;
	m2.m[7] = v->y;
	m2.m[8] = 0;
	m2.m[9] = 0;
	m2.m[10] = 0;
	m2.m[11] = v->z;
	m2.m[12] = 0;
	m2.m[13] = 0;
	m2.m[14] = 0;
	m2.m[15] = 0;
	matrice_add(m1, &m2);
}

void	matrice_rotation_z(t_matrice4 *m1, float angle)
{
	t_matrice4 m2;

	m1->m[0] = cos(angle);
	m1->m[1] = -sin(angle);
	m1->m[4] = sin(angle);
	m1->m[5] = cos(angle);
}

