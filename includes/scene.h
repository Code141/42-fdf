#ifndef SCENE_H
# define SCENE_H
# include "libft.h"
# include "vector.h"
# include "mesh.h"
# include "camera.h"

typedef struct	s_scene
{
	t_list		*objects;
	t_camera	*camera;
}				t_scene;

t_scene			*new_scene();
void			scene_add(t_scene *scene, t_mesh *object);

#endif
