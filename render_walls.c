/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:19:53 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 11:19:54 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			render3d(int i)
{
	float			project_distance;
	unsigned int	color;

	color = 0;
	check_sides(i);
	if (g_tab[0] == 0)
		g_t.txt_x = (int)g_r.cast.wall_hit_x % TILESIZE;
	else
		g_t.txt_x = (int)g_r.cast.wall_hit_y % TILESIZE;
	project_distance = (g_sc.w / 2) / tan(g_fov / 2);
	g_r.cast.distance = cosf(g_p.rotation_angle -
		g_r.rays[i]) * g_r.cast.distance;
	g_r.ray_hight = (project_distance / g_r.cast.distance) * TILESIZE;
	rectangle(i, color);
}

void			put_texture(int i, int j)
{
	if (g_tab[0] == 0 && g_tab[2] == 1)
		g_data[(int)i + (int)j * g_sc.w] =
			check_opacity(g_t.txtr1[g_t.txt_x + TILESIZE * g_t.txt_y]);
	else if (g_tab[0] == 0 && g_tab[2] == 0)
		g_data[(int)i + (int)j * g_sc.w] =
			check_opacity(g_t.txtr2[g_t.txt_x + TILESIZE * g_t.txt_y]);
	else if (g_tab[0] == 1 && g_tab[1] == 1)
		g_data[(int)i + (int)j * g_sc.w] =
			check_opacity(g_t.txtr4[g_t.txt_x + TILESIZE * g_t.txt_y]);
	else if (g_tab[0] == 1 && g_tab[1] == 0)
		g_data[(int)i + (int)j * g_sc.w] =
			check_opacity(g_t.txtr3[g_t.txt_x + TILESIZE * g_t.txt_y]);
}

int				print_texture(int j, int c, int i)
{
	while (j - c <= g_r.ray_hight && j < g_sc.h)
	{
		g_t.txt_y = (int)((j - c) * TILESIZE) / g_r.ray_hight;
		put_texture(i, j);
		j++;
	}
	return (j);
}

unsigned int	convert_rgb(int r, int g, int b)
{
	unsigned int color;

	color = r;
	color = (color << 8) + g;
	color = (color << 8) + b;
	return (color);
}

void			rectangle(int e, unsigned int color)
{
	int i;
	int j;
	int c;
	int save_x;

	color = 0xFFFFFF;
	save_x = e;
	i = e;
	c = 0;
	e = 0;
	j = g_sc.h / 2 - g_r.ray_hight / 2 + g_p.look;
	c = j;
	while (e < j)
	{
		g_data[(int)i + (int)e * g_sc.w] = convert_rgb(g_cc.r, g_cc.g, g_cc.b);
		e++;
	}
	if (j < 0)
		j = 0;
	j = print_texture(j, c, i);
	while (j < g_sc.h)
	{
		g_data[(int)i + (int)j * g_sc.w] = convert_rgb(g_fc.r, g_fc.g, g_fc.b);
		j++;
	}
}
