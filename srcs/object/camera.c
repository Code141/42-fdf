/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:37:05 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/10 17:37:21 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "camera.h"

t_camera	*new_camera(float angle, float near, float far)
{
	t_camera *camera;

	camera = (t_camera*)malloc(sizeof(t_camera));
	vector3_set(&camera->pos, 0, 0, 0);
	vector3_set(&camera->rot, 0, 0, 0);
	camera->angle = angle;
	camera->near = near;
	camera->far = far;
	return (camera);
}

void		destroy_camera(t_camera *cam)
{
	free(cam);
}
