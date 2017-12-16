#ifndef SCENE_H
# define SCENE_H
# include "libft.h"
# include "vector.h"
# include "object.h"

typedef struct	s_scene
{
	t_list	*objects;
}				t_scene;

t_scene			*new_scene();
void			scene_add(t_scene *scene, t_object *object);

#endif
