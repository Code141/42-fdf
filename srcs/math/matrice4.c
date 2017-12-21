#include "matrice4.h"

t_matrice4	*matrice4_init()
{
	t_matrice4	*m;

	m = (t_matrice4*)malloc(sizeof(t_matrice4));
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;

	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = 0;

	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = 0;

	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
	return (m);	
}

void		matrice_translation(t_vector3 p, t_vector3 v, t_matrice4 *m)
{
	m[0][0] = p.x | p.y | p.z;//v1
	m[0][1] = p.x | p.y | p.z;
	m[0][2] = p.x | p.y | p.z;
	m[0][3] = p.x | p.y | p.z;

	m[1][0] = p.x | p.y | p.z;//v2
	m[1][1] = p.x | p.y | p.z;
	m[1][2] = p.x | p.y | p.z;
	m[1][3] = p.x | p.y | p.z;

	m[2][0] = p.x | p.y | p.z;//v2
	m[2][1] = p.x | p.y | p.z;
	m[2][2] = p.x | p.y | p.z;
	m[2][3] = p.x | p.y | p.z;

	m[3][0] = p.x | p.y | p.z;
	m[3][1] = p.x | p.y | p.z;
	m[3][2] = p.x | p.y | p.z;
	m[3][3] = p.x | p.y | p.z;

}
