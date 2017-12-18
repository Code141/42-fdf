#include <stdlib.h>
#include "mesh.h"
#include "vector.h"

t_mesh	*new_mesh(t_geometry *geometry, t_material *material)
{
	t_mesh *mesh;

	mesh = (t_mesh*)malloc(sizeof(t_mesh));
	mesh->geometry = geometry;
	mesh->material = material;
	mesh->pos.x = 0;
	mesh->pos.y = 0;
	mesh->pos.z = 0;
	return (mesh);
}
