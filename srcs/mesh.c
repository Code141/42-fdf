#include "mesh.h"

t_mesh	*new_mesh(t_geometry *geometry, t_material *material)
{
	t_mesh *mesh;

	mesh = (t_mesh*)malloc(sizeof(t_mesh));
	mesh->geometry = geometry;
	mesh->material = material;
	vector3_set(&mesh->pos, 0, 0, 0);
	vector3_set(&mesh->rot, 0, 0, 0);

	mesh->matrice = (t_matrice4*)malloc(sizeof(t_matrice4));
	matrice4_init(mesh->matrice);
	return (mesh);
}
