#include "draw.h"

float	scalaire(float x, float y)
{
	int			a;
	int			b;
	t_vector2	v2;
	float		angle;

	v2.x = 0;
	v2.y = 1;
	a =	(x * v2.x) + (y * v2.y);
	b = ((x * x) + (y * y)) * ((v2.x * v2.x) + (v2.y * v2.y));
	angle = acos(a / sqrt(b));
	return (angle);
}

t_vector2	projection(t_ctx *ctx, t_vector3 *v1, t_mesh *mesh)
{

/*	float cpp;
	t_vector2	v2;

	cpp = 1 / tan(ctx->scene->camera->angle / 2);
	printf("%f\n",cpp*ctx->screen->height);
*/

	t_vector2	v2;
	float		hypo;
	t_vector3	angle;

	v2.x = v1->x;
	v2.y = v1->y;

	v2.x += (ctx->screen->width / 2) + mesh->pos.x - ctx->scene->camera->pos.x;
	v2.y += (ctx->screen->height / 2) + mesh->pos.y - ctx->scene->camera->pos.y;
	
	return (v2);	
}

void	draw_vertices(t_ctx *ctx, t_mesh *mesh)
{
	int			i;
	t_vector3	v1;
	t_vector2	v2;

	i = 0;
	while (mesh->geometry->vertices[i])
	{
		v1 = matrice_apply(mesh->geometry->vertices[i], mesh->matrice);
		v2 = projection(ctx, &v1, mesh);
		draw_point(ctx->screen->canevas, v2, 5, mesh->material->color);
		i++;
	}
}

void	draw_edges(t_ctx *ctx, t_mesh *mesh)
{
	int			i;
	t_vector3	v1a;
	t_vector3	v1b;
	t_vector2	v2a;
	t_vector2	v2b;
	
	i = 0;
	while (mesh->geometry->edges[i])
	{
		v1a = matrice_apply(mesh->geometry->edges[i]->vertices[0], mesh->matrice);
		v1b = matrice_apply(mesh->geometry->edges[i]->vertices[1], mesh->matrice);
		v2a = projection(ctx, &v1a, mesh);
		v2b = projection(ctx, &v1b, mesh);
		draw_line(ctx->screen->canevas, v2a, v2b, mesh->material->color);
		i++;
	}
}

void	draw_mesh(t_ctx *ctx, t_mesh *mesh)
{
	t_matrice4 *m;
	t_vector3 v;

	v.x = 1;
	v.y = 0;
	v.z = 0;


	mesh->matrice = matrice_rotation_x(mesh->matrice, TO_RAD(0.5));
	mesh->matrice = matrice_rotation_y(mesh->matrice, TO_RAD(0.1));
	mesh->matrice = matrice_rotation_z(mesh->matrice, TO_RAD(0.1));

//	mesh->matrice = matrice_translation(mesh->matrice, &v);
/*	m = mesh->matrice;

	printf("%f	%f	%f	%f\n%f	%f	%f	%f\n%f	%f	%f	%f\n%f	%f	%f	%f\n\n\n",
		m->m[0], m->m[1], m->m[2], m->m[3], m->m[4], m->m[5], m->m[6], m->m[7],
		m->m[8], m->m[9], m->m[10], m->m[11], m->m[12], m->m[13], m->m[14], m->m[15]);

*/


	draw_edges(ctx, mesh);
	draw_vertices(ctx, mesh);
}

void	draw_all(t_ctx *ctx)
{
	int i;
	
	ft_bzero(ctx->screen->canevas->data, ctx->screen->canevas->width * ctx->screen->canevas->height * 4);
	t_list	*objects;
	t_list	*object;
	
//	printf("--- DRAW ALL -------------------------\n\n");
	objects = ctx->scene->objects;
	object = objects;

	i = 0;
	while (object)
	{
//		printf("- Mesh [%d] -\n", i);
		draw_mesh(ctx, object->content);
		object = object->next;
		i++;
	}
	mlx_put_image_to_window (ctx->mlx, ctx->screen->win, ctx->screen->canevas->id, 0, 0);	
}
