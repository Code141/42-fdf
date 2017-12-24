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

	p2.x = p->x * m->m[0] + p->y * m->m[1] + p->z * m->m[2] + m->m[3];
	p2.y = p->x * m->m[4] + p->y * m->m[5] + p->z * m->m[6] + m->m[7];
	p2.z = p->x * m->m[8] + p->y * m->m[9] + p->z * m->m[10] + m->m[11];
//	p2.w = p->x * m->m[12] + p->y * m->m[13] + p->z * m->m[14] + m->m[15];
	return (p2);
}

t_matrice4	*matrice_product(t_matrice4 *m1, t_matrice4 *m2)
{
	int			i;
	t_matrice4	*m3;

	m3 = (t_matrice4*)malloc(sizeof(t_matrice4));
	i = 0;
	while (i < 16)
	{
		m3->m[i] = (m1->m[(i / 4) * 4 + 0] * m2->m[i % 4 + 0])
				+ (m1->m[(i / 4) * 4 + 1] * m2->m[i % 4 + 4])
				+ (m1->m[(i / 4) * 4 + 2] * m2->m[i % 4 + 8])
				+ (m1->m[(i / 4) * 4 + 3] * m2->m[i % 4 + 12]);
		i++;
	}
	return (m3);
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

t_matrice4	*matrice_translation(t_matrice4 *m1, t_vector3 *v)
{
	t_matrice4	m2;
	t_matrice4	*m3;
	
	matrice4_init(&m2);
	m2.m[3] = v->x;
	m2.m[7] = v->y;
	m2.m[11] = v->z;
	m3 = (t_matrice4*)malloc(sizeof(t_matrice4));
	m3 = matrice_product(m1, &m2);
	return (m3);
}

t_matrice4	*matrice_rotation_x(t_matrice4 *m1, float angle)
{
	t_matrice4 m2;
	t_matrice4 *m3;

	matrice4_init(&m2);
	m2.m[5] = cos(angle);
	m2.m[6] = -sin(angle);
	m2.m[9] = sin(angle);
	m2.m[10] = cos(angle);
	m3 = (t_matrice4*)malloc(sizeof(t_matrice4));
	m3 = matrice_product(m1, &m2);
	return (m3);
}

t_matrice4	*matrice_rotation_y(t_matrice4 *m1, float angle)
{
	t_matrice4 m2;
	t_matrice4 *m3;

	matrice4_init(&m2);
	m2.m[0] = cos(angle);
	m2.m[2] = -sin(angle);
	m2.m[8] = sin(angle);
	m2.m[10] = cos(angle);
	m3 = (t_matrice4*)malloc(sizeof(t_matrice4));
	m3 = matrice_product(m1, &m2);
	return (m3);
}

t_matrice4	*matrice_rotation_z(t_matrice4 *m1, float angle)
{
	t_matrice4 m2;
	t_matrice4 *m3;

	matrice4_init(&m2);
	m2.m[0] = cos(angle);
	m2.m[1] = -sin(angle);
	m2.m[4] = sin(angle);
	m2.m[5] = cos(angle);
	m3 = (t_matrice4*)malloc(sizeof(t_matrice4));
	m3 = matrice_product(m1, &m2);
	return (m3);
}

