#include "cub3d.h"

player p;

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
		p.walk_left = 1;
	if (key == 2)
	{
		p.walk_right = 1;
	}
	if (key == 13)
		p.walk_for = 1;
	if (key == 1)
		p.walk_back = 1;
	if (key == 123)
		p.cam_left = 1;
	if (key == 124)
		p.cam_right = 1;
	if (key == 126)
		p.look_up = 1;
	else if (key == 125)
		p.look_down = 1;
	return (0);
}

int keyreleased(int key)
{
	if (key == 0)
	{
		p.walk_left = -1;
	}
	if (key == 2)
	{
		p.walk_right = -1;
	}
	if (key == 13)
		p.walk_for = -1;
	if (key == 1)
		p.walk_back = -1;
	if (key == 123)
		p.cam_left = -1;
	if (key == 124)
		p.cam_right = -1;
	if (key == 126)
		p.look_up = -1;
	else if(key == 125)
		p.look_down = -1;
	return(0);
}