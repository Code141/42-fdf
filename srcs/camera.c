#include <stdlib.h>
#include "camera.h"

t_camera	*new_camera()
{
	t_camera *camera;

	camera = (t_camera*)malloc(sizeof(t_camera));
	camera->pos.x = 0;
	camera->pos.y = 0;
	return (camera);
}
