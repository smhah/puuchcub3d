#include "cub3d.h"

player p;

void    player_update(void)
{
	if (p.cam_left == 1) // left
		p.rotationAngle -= p.rotationSpeed;
	if (p.cam_right == 1) //right
		p.rotationAngle += p.rotationSpeed;
	if(p.walk_for == 1 || p.walk_back == 1)
		walk_for_or_back();
	if(p.walk_left == 1 || p.walk_right == 1)
		walk_right_or_left();
	if (p.look_up == 1 && p.look < 300)
	{
			p.look+=10;
	}
	if (p.look_down == 1 && p.look > (-300))
	{
		p.look-=10;
	}
}

void    castAllRays(void)
{
	int i;

	columnId = 0;
	i = 0;
	rayAngle = p.rotationAngle - (fov / 2);
	while(i < Num_rays)
	{
		r.rays[columnId] = rayAngle;
		rayAngle += fov / Num_rays;
		i+=1;
		columnId++;
	}
}

void	blackscreen(void)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(x < sc.w)
	{
		y = 0;
		while(y < sc.h)
		{
			data[(int )x + (int )y * sc.w] = 0x000000;
			y++;
		}
		x++;
	}
}

int update()
{
	static char i;
	//clock_t b, e;
	mlx_hook(win_ptr , 2 , 0 ,  keypress, 0);
	mlx_hook(win_ptr, 3 , 0 ,  keyreleased,  0);
	player_update();
	castAllRays();
	mlx_clear_window(mlx_ptr, win_ptr);
	render();
	if(screenshot == 0)
	{
		screen_shot();
	}
	if (!i || i++ == 127)
		mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0 , 0);
	screenshot++;
	return (0);
}