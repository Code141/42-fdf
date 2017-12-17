#include "pixel.h"

void	put_pixel(t_img *canevas, int x, int y, int color)
{
	if ((y < 0 || y >= canevas->height)
		|| (x < 0 || x >= canevas->width))
	return ;
	canevas->data[(4 * y * canevas->width) + x*4 + 0] = 0xff;	// Blue
	canevas->data[(4 * y * canevas->width) + x*4 + 1] = 0xff;	// Green
	canevas->data[(4 * y * canevas->width) + x*4 + 2] = 0xff;	// Red
	canevas->data[(4 * y * canevas->width) + x*4 + 3] = 0x00;	// Alpha
}
