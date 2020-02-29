#include "cub3d.h"

void	walk_right_or_left(void)
{
	if(g_p.walk_left == 1 )
	{
		if (checknextstepx(2))
			g_p.x += cosf(g_p.rotation_angle - PI / 2) * g_p.move_speed;
		if (checknextstepy(2))
			g_p.y += sinf(g_p.rotation_angle - PI / 2) * g_p.move_speed;
	}
	if(g_p.walk_right == 1)
	{
		if(checknextstepx(3))
			g_p.x += cosf(g_p.rotation_angle + PI / 2) * g_p.move_speed;
		if(checknextstepy(3))
			g_p.y += sinf(g_p.rotation_angle + PI / 2) * g_p.move_speed;
	}
}

void	walk_for_or_back(void)
{
	if (g_p.walk_for == 1)
	{
		if (checknextstepx(1))
			g_p.x += cosf(g_p.rotation_angle) * g_p.move_speed;
		if (checknextstepy(1))
			g_p.y += sinf(g_p.rotation_angle) * g_p.move_speed;
	}
	if (g_p.walk_back == 1)
	{
		if (checknextstepx(0))
			g_p.x -= cosf(g_p.rotation_angle) * g_p.move_speed;
		if (checknextstepy(0))
			g_p.y -= sinf(g_p.rotation_angle) * g_p.move_speed;	
	}
}
