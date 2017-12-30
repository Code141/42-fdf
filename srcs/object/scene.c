#include <stdlib.h>
#include "scene.h"
#include "mesh.h"

t_scene		*new_scene()
{
	t_scene *scene;

	scene = (t_scene*)malloc(sizeof(t_scene));
	scene->objects = NULL;
	scene->camera = NULL;
	return (scene);
}

void		scene_add(t_scene *scene, t_object *object)
{
	ft_lst_push_back(&scene->objects, ft_lst_new_link(object));
}

void	destroy_scene(t_scene *scene)
{
	ft_lstdel(&scene->objects, &destroy_objects);
	// LEAKS DANS LES LISTES
	destroy_camera(scene->camera);
	free(scene);
}