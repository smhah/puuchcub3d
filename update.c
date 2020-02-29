#include "cub3d.h"

void    player_update(void)
{
	if (g_p.cam_left == 1) // left
		g_p.rotation_angle -= g_p.rotation_speed;
	if (g_p.cam_right == 1) //right
		g_p.rotation_angle += g_p.rotation_speed;
	if (g_p.walk_for == 1 || g_p.walk_back == 1)
		walk_for_or_back();
	if (g_p.walk_left == 1 || g_p.walk_right == 1)
		walk_right_or_left();
	if (g_p.look_up == 1 && g_p.look < 300)
			g_p.look+=10;
	if (g_p.look_down == 1 && g_p.look > (-300))
		g_p.look-=10;
}

void    cast_all_rays(void)
{
	int i;

	i = 0;
	g_rayangle = g_p.rotation_angle - (g_fov / 2);
	while (i < g_num_rays)
	{
		g_r.rays[i] = g_rayangle;
		g_rayangle += g_fov / g_num_rays;
		i += 1;
	}
}

void	blackscreen(void)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < g_sc.w)
	{
		y = 0;
		while (y < g_sc.h)
		{
			g_data[(int )x + (int )y * g_sc.w] = 0x000000;
			y++;
		}
		x++;
	}
}

int	keyexit(int key)
{
	(void)key;
	return (exit_cub3d(0));
}

int update()
{
	static char i;
	//clock_t b, e;
	mlx_hook(g_win_ptr , 2 , 0 ,  keypress, 0);
	mlx_hook(g_win_ptr, 3 , 0 ,  keyreleased,  0);
	mlx_hook(g_win_ptr, 17,0L, keyexit, 0);
	player_update();
	cast_all_rays();
	render();
	mlx_clear_window(g_mlx_ptr, g_win_ptr);
	if (!i || i++ == 127)
		mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img, 0 , 0);
	return (0);
}