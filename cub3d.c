/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:31:13 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 04:31:15 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		render(void)
{
	unsigned int	color;

	g_r.id = 0;
	g_op.max_dist = sqrtf(powf(0 - (float)g_p.map_a *
		TILESIZE, 2) + powf(0 - (float)g_p.map_b * TILESIZE, 2));
	g_op.max_dist *= 0.85;
	while (g_r.id < Num_rays)
	{
		g_s.sprite = 0;
		color = 0xfa2c34;
		cast(g_r.rays[g_r.id]);
		render3d(g_r.id);
		g_i = g_s.sprite;
		while (g_i--)
		{
			if (g_rows.xhit[g_i] < MAXINT - 100 &&
				g_rows.dist[g_i] < fabsf(g_r.cast.distance))
			{
				rendersprite();
				if (g_s.xofset[g_r.id][g_i] > 0 && g_s.xofset[g_r.id][g_i] < 70)
					render3dsprite();
			}
		}
		g_r.id += 1;
	}
}

void		posplayer(int g_height, int g_width, char **g_lines, int indice)
{
	int a;
	int b;
	int x;
	int y;

	y = 0;
	a = 0;
	if (indice == 0)
	{
		while (y < g_height)
		{
			x = 0;
			b = 0;
			while (x < g_width)
			{
				if (is_player(g_lines[a][b]))
					gps(x, y);
				x += TILESIZE;
				b++;
			}
			y += TILESIZE;
			a++;
		}
	}
}

void		init_all(void)
{
	fov = 60 * (PI / 180);
	rays_width = 1;
	Num_rays = g_sc.w / rays_width;
	g_r.rays = m_malloc(sizeof(float) * Num_rays);
	g_r.id = 0;
	g_p.x = 0;
	g_p.y = 0;
	g_p.radius = 3;
	g_p.turn_direction = 0;
	g_p.walk_direction = 0;
	if (g_o.north)
		g_p.rotation_angle = PI / 2;
	if (g_o.sud)
		g_p.rotation_angle = (-PI) / 2;
	if (g_o.est)
		g_p.rotation_angle = PI;
	if (g_o.ouest)
		g_p.rotation_angle = 0;
	g_p.move_speed = 4;
	g_p.rotation_speed = 1.8 * PI / 180;
	g_p.look = 0;
	g_p.map_a = 0;
	g_p.map_b = 0;
}

int			beginning(int ac, char **av, int fd)
{
	g_mc = 0;
	if (ac < 2)
		return (wrong_argument());
	else if (ac > 2)
	{
		if (!check_file_name(av[2], 1))
			return (exit_cub3d(0));
		g_screenshot = 1;
	}
	else
		g_screenshot = -1;
	if (!check_file_name(av[1], 0))
		return (exit_cub3d(0));
	if ((fd = open(av[1], O_RDWR)) < 0)
		return (invalide_map_path());
	if (!readfile(fd))
	{
		exit_cub3d(0);
		return (0);
	}
	g_mlx_ptr = mlx_init();
	if ((!ft_textures()))
		return (exit_cub3d(0));
	return (1);
}

int			main(int ac, char **av)
{
	int fd;

	fd = 0;
	if (!beginning(ac, av, fd))
		return (0);
	init_all();
	while (g_lines[g_p.map_a])
		g_p.map_a++;
	g_height = TILESIZE * g_p.map_a;
	while (g_lines[0][g_p.map_b])
		g_p.map_b++;
	g_width = TILESIZE * g_p.map_b;
	if (g_screenshot == -1)
		g_win_ptr = mlx_new_window(g_mlx_ptr, g_sc.w, g_sc.h, "mlx 42");
	else
		return (screen());
	img = mlx_new_image(g_mlx_ptr, g_sc.w, g_sc.h);
	data = (int*)mlx_get_data_addr(img, &a, &b, &c);
	posplayer(g_height, g_width, g_lines, 0);
	mlx_loop_hook(g_mlx_ptr, update, 0);
	mlx_loop(g_mlx_ptr);
	return (0);
}
