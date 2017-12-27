#include "object.h"

t_object	*new_object(t_mesh *mesh)
{
	t_object	*obj;

	obj = (t_object*)malloc(sizeof(t_object));

	obj->parent = NULL;
	obj->children = NULL;
	obj->mesh = mesh;
	vector3_set(&obj->pos, 0, 0, 0);
	vector3_set(&obj->rot, 0, 0, 0);
	matrice4_init(&obj->matrice);
	return (obj);
}

void		object_add_child(t_object *obj1, t_object *obj2)
{
	ft_lst_push_back(&obj1->children, ft_lst_new_link(obj2));
	obj2->parent = obj1;
}

void	destroy_objects(void **objects)
{
	t_object	*object;

	object =  (t_object*)objects;

	if (object->mesh)
		destroy_mesh(object->mesh);
	if (object->children)
		ft_lstdel(&object->children, &destroy_objects);
	free(object);
}
