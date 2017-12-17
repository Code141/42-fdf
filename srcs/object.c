#include <stdlib.h>
#include "object.h"
#include "vector.h"

t_object	*new_object(t_geometry *geometry, t_material *material)
{
	t_object *object;

	object = (t_object*)malloc(sizeof(t_object));
	object->geometry = geometry;
	object->material = material;
	object->pos.x = 0;
	object->pos.y = 0;
	object->pos.z = 0;
	return (object);
}
