#include "cub3d.h"

int keypress(int key)
{
	if(key == 53)
	{
		//exit_cub3d();
		free_all();
		//system("leaks cub3D");
		exit(1);
	}
	
	//if()
	if (key == 0)
		g_p.walk_left = 1;
	if (key == 2)
	{
		g_p.walk_right = 1;
	}
	if (key == 13)
		g_p.walk_for = 1;
	if (key == 1)
		g_p.walk_back = 1;
	if (key == 123)
		g_p.cam_left = 1;
	if (key == 124)
		g_p.cam_right = 1;
	if (key == 126)
		g_p.look_up = 1;
	else if (key == 125)
		g_p.look_down = 1;
	return (0);
}

int keyreleased(int key)
{
	if (key == 0)
	{
		g_p.walk_left = -1;
	}
	if (key == 2)
	{
		g_p.walk_right = -1;
	}
	if (key == 13)
		g_p.walk_for = -1;
	if (key == 1)
		g_p.walk_back = -1;
	if (key == 123)
		g_p.cam_left = -1;
	if (key == 124)
		g_p.cam_right = -1;
	if (key == 126)
		g_p.look_up = -1;
	else if(key == 125)
		g_p.look_down = -1;
	return(0);
}