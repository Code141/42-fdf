#ifndef CAMERA_H
# define CAMERA_H
# include "vector.h"

typedef struct	s_camera
{
	t_vect		pos;
}				t_camera;

t_camera		*new_camera();

#endif
