/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 10:53:13 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 10:53:15 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	stock_hhit(float g_ax, float g_ay, float angle)
{
	g_rows.xhit[g_rows.id] = g_ax;
	g_rows.yhit[g_rows.id++] = g_ay + (!ray_facing_down(angle) ? 1 : 0);
	g_rows.xhit[g_rows.id] = MAXINT;
	g_rows.yhit[g_rows.id] = MAXINT;
}

void	stock_hcast(float g_ax, float g_ay, float angle)
{
	g_r.cast.horizontalx = g_ax;
	g_r.cast.horizontaly = g_ay + (!ray_facing_down(angle) ? 1 : 0);
}

float	init_calc(float rayangle)
{
	float angle;

	angle = normalize(rayangle);
	g_ystep = TILESIZE * (ray_facing_down(angle) ? 1 : -1);
	g_xstep = tan(angle) ? g_ystep / tan(angle) : 0;
	g_ay = (floor(g_p.y / TILESIZE) * TILESIZE) +
		(ray_facing_down(angle) ? TILESIZE : 0);
	g_ax = g_p.x + ((g_ay - g_p.y) / tan(angle));
	g_r.cast.distance = 0;
	return (angle);
}

void	horizontalintersect(float rayangle)
{
	float angle;

	angle = init_calc(rayangle);
	if (!ray_facing_down(angle))
		g_ay--;
	while (g_ay >= 0 && g_ax >= 0 && g_ax < g_width && g_ay < g_height)
	{
		if (g_lines[(int)(g_ay) / TILESIZE][(int)(g_ax) / TILESIZE] == '2')
			stock_hhit(g_ax, g_ay, angle);
		if (g_lines[(int)(g_ay) / TILESIZE][(int)(g_ax) / TILESIZE] == '1')
		{
			stock_hcast(g_ax, g_ay, angle);
			break ;
		}
		g_ax += g_xstep;
		g_ay += g_ystep;
	}
}
