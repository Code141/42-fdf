#include <stdlib.h>
#include "camera.h"

t_camera	*new_camera()
{
	t_camera *camera;

	camera = (t_camera*)malloc(sizeof(t_camera));
	camera->pos.x = 0;
	camera->pos.y = 0;
	camera->pos.z = 0;
	camera->rot.x = 0;
	camera->rot.y = 0;
	camera->rot.z = 0;
	camera->angle = 0;
	camera->near = 0;
	camera->far = 0;
	return (camera);
}
