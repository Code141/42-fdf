#ifndef CAMERA_H
# define CAMERA_H
# include "vector.h"

typedef struct	s_camera
{
	t_vector3	pos;
	t_vector3	rot;
	float		angle;
	float		near;
	float		far;
}				t_camera;

t_camera	*new_camera(float angle, float near, float far);
void		destroy_camera(t_camera *cam);

#endif
