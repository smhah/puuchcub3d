#include "cub3d.h"

player p;

void	walk_right_or_left(void)
{
	if(p.walk_left == 1 )
	{
		if (checknextstepx(2))
			p.x += cosf(p.rotationAngle - Pi / 2) * p.moveSpeed;
		if (checknextstepy(2))
			p.y += sinf(p.rotationAngle - Pi / 2) * p.moveSpeed;
	}
	if(p.walk_right == 1)
	{
		if(checknextstepx(3))
			p.x += cosf(p.rotationAngle + Pi / 2) * p.moveSpeed;
		if(checknextstepy(3))
			p.y += sinf(p.rotationAngle + Pi / 2) * p.moveSpeed;
	}
}

void	walk_for_or_back(void)
{
	if (p.walk_for == 1)
	{
		if (checknextstepx(1))
			p.x += cosf(p.rotationAngle) * p.moveSpeed;
		if (checknextstepy(1))
			p.y += sinf(p.rotationAngle) * p.moveSpeed;
	}
	if (p.walk_back == 1)
	{
		if (checknextstepx(0))
			p.x -= cosf(p.rotationAngle) * p.moveSpeed;
		if (checknextstepy(0))
			p.y -= sinf(p.rotationAngle) * p.moveSpeed;	
	}
}
