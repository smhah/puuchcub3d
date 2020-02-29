/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:47:41 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 11:47:42 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bigcas1(void)
{
	if (g_tab[2] == 0)
	{
		if (g_s.xprime[g_r.id][g_i] >= g_s.xc[g_r.id])
			g_s.xofset[g_r.id][g_i] += TILESIZE / 2;
		else
			g_s.xofset[g_r.id][g_i] = TILESIZE -
				TILESIZE / 2 - g_s.xofset[g_r.id][g_i];
	}
	else
	{
		smallcas1();
	}
}

void	bigcas2(void)
{
	if (g_tab[2] == 0)
	{
		if (g_s.xprime[g_r.id][g_i] >= g_s.xc[g_r.id])
			g_s.xofset[g_r.id][g_i] = TILESIZE -
				TILESIZE / 2 - g_s.xofset[g_r.id][g_i];
		else
			g_s.xofset[g_r.id][g_i] += TILESIZE / 2;
	}
	else
		smallcas2();
}

void	correctofsset(void)
{
	if (g_tab[1] == 0)
		bigcas1();
	else
		bigcas2();
}

void	direction_info(void)
{
	if (ray_facing_left(normalize(g_r.rays[g_r.id])))
		g_tab[0] = 1;
	else
		g_tab[0] = 0;
	if (ray_facing_down(normalize(g_r.rays[g_r.id])))
		g_tab[1] = 1;
	else
		g_tab[1] = 0;
}

void	find_point(void)
{
	float a;
	float b;
	float angle;

	angle = normalize(g_r.rays[g_r.id]);
	angle = (PI - angle) * (-1);
	b = atan2(g_p.y - g_s.yc[g_r.id], g_p.x - g_s.xc[g_r.id]);
	b = normalize(b);
	a = angle - b;
	g_s.xprime[g_r.id][g_i] = g_p.x + (g_s.xc[g_r.id] - g_p.x) *
		cosf(a) - (g_s.yc[g_r.id] - g_p.y) * sinf(a);
	g_s.yprime[g_r.id][g_i] = g_p.y + (g_s.xc[g_r.id] - g_p.x) *
		sinf(a) + (g_s.yc[g_r.id] - g_p.y) * cosf(a);
	g_s.xofset[g_r.id][g_i] = sqrtf(powf(g_s.xprime[g_r.id][g_i]
		- g_s.xc[g_r.id], 2)
			+ powf(g_s.yprime[g_r.id][g_i] - g_s.yc[g_r.id], 2));
	correctofsset();
}
