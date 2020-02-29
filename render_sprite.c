/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:14:36 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 11:14:37 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rendersprite(void)
{
	direction_info();
	if (g_rows.xhit[g_i] < 0)
	{
		g_rows.xhit[g_i] *= -1;
		g_s.xc[g_r.id] = floor((g_rows.xhit[g_i]) / TILESIZE)
			* TILESIZE + ((g_tab[0] == 1) ? TILESIZE / (-2) : (TILESIZE / 2));
		g_s.yc[g_r.id] = floor(g_rows.yhit[g_i]
			/ TILESIZE) * TILESIZE + TILESIZE / 2;
		g_tab[2] = 1;
	}
	else
	{
		g_s.xc[g_r.id] = floor(g_rows.xhit[g_i] / TILESIZE)
			* TILESIZE + TILESIZE / 2;
		g_s.yc[g_r.id] = floor(g_rows.yhit[g_i] / TILESIZE) *
			TILESIZE + ((g_tab[1] == 1) ? TILESIZE / 2 : TILESIZE / (-2));
		g_tab[2] = 0;
	}
	find_point();
}

void	rectosprite(float sprite_height, int i)
{
	int j;
	int y;
	int c;

	j = g_sc.h / 2 - sprite_height / 2 + g_p.look;
	c = j;
	if (j < 0)
		j = 0;
	while (j - c < sprite_height && j < g_sc.h)
	{
		y = (int)((j - c) * TILESIZE) / sprite_height;
		if (g_t.sprite[(int)g_s.xofset[g_r.id][g_i] + TILESIZE * y] != 0x000000
			&& check_color(g_t.sprite[(int)g_s.xofset[g_r.id][g_i]
				+ TILESIZE * y]))
			g_data[(int)i + (int)j * g_sc.w] =
				g_t.sprite[(int)g_s.xofset[g_r.id][g_i] + TILESIZE * y];
		j++;
	}
}

void	render3dsprite(void)
{
	float project_distance;
	float sprite_height;
	float dist;

	dist = sqrtf(powf(g_p.x - g_s.xc[g_r.id], 2) +
		powf(g_p.y - g_s.yc[g_r.id], 2));
	project_distance = (g_sc.w / 2) / tan(g_fov / 2);
	sprite_height = (project_distance / dist) * TILESIZE;
	rectosprite(sprite_height, g_r.id);
}
