#include <stdlib.h>
#include "camera.h"

t_camera	*new_camera()
{
	t_camera *camera;

	camera = (t_camera*)malloc(sizeof(t_camera));
	vector3_set(&camera->pos, 0, 0, 0);
	vector3_set(&camera->rot, 0, 0, 0);
	camera->angle = 0;
	camera->near = 0;
	camera->far = 0;
	return (camera);
}
