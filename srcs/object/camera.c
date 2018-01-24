/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:37:05 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/24 19:36:30 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "camera.h"

t_camera	*new_camera(float angle, float near, float far)
{
	t_camera *camera;

	camera = (t_camera*)malloc(sizeof(t_camera));
	set_point(0, 0, 0, &camera->pos);
	set_angle(0, 0, 0, &camera->rot);
	camera->angle = angle;
	camera->near = near;
	camera->far = far;
	return (camera);
}

void		destroy_camera(t_camera *cam)
{
	free(cam);
}
