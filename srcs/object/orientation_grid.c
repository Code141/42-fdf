#include "orientation_grid.h"
/*
t_object	*grid_orientation(int x, int y, int subx, int suby)
{
	t_object	*obj;
	t_object	*grid;
	t_geometry	*geometry;
	t_material	*material;
	
	obj = new_object(NULL);
	geometry = new_surface(x, y, subx, suby);
	material = new_material(0x0000ff);
//	grid = new_object(new_mesh(geometry, material));
	object_add_child(obj, grid);

	geometry = new_surface(x, y, subx, suby);
	material = new_material(0x00ff00);
	grid = new_object(new_mesh(geometry, material));
//	matrice_rotation_x(&grid->mesh->matrice, TO_RAD(90));
	object_add_child(obj, grid);

	geometry = new_surface(x, y, subx, suby);
	material = new_material(0xff0000);
	grid = new_object(new_mesh(geometry, material));
//	matrice_rotation_y(&grid->mesh->matrice, TO_RAD(90));
	object_add_child(obj, grid);
	return(obj);
}
*/
