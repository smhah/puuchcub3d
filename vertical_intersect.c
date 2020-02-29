/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:06:13 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 11:06:14 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		stock_vhit(float g_ax, float g_ay, float angle)
{
	g_rows.xhit[g_rows.id] = (g_ax + (ray_facing_left(angle) ? 1 : 0)) * (-1);
	g_rows.yhit[g_rows.id++] = g_ay;
	g_rows.xhit[g_rows.id] = MAXINT;
	g_rows.yhit[g_rows.id] = MAXINT;
}

void		stock_vcast(float g_ax, float g_ay, float angle)
{
	g_r.cast.verticalx = g_ax + (ray_facing_left(angle) ? 1 : 0);
	g_r.cast.verticaly = g_ay;
}

float		init_calc_ver(float rayangle)
{
	float angle;

	angle = normalize(rayangle);
	g_xstep = TILESIZE * (ray_facing_left(angle) ? -1 : 1);
	g_ystep = g_xstep * (tan(angle));
	g_ax = (floor(g_p.x / TILESIZE) * TILESIZE) +
		(!ray_facing_left(angle) ? TILESIZE : 0);
	g_ay = g_p.y - (tan(angle) * (g_p.x - g_ax));
	return (angle);
}

void		verticalintersect(float rayangle)
{
	float angle;

	angle = init_calc_ver(rayangle);
	if (ray_facing_left(angle))
		g_ax--;
	while (g_ay >= 0 && g_ax >= 0 && g_ax < g_width && g_ay < g_height)
	{
		if (g_lines[(int)(g_ay) / TILESIZE][(int)(g_ax) / TILESIZE] == '2')
			stock_vhit(g_ax, g_ay, angle);
		if (g_lines[(int)(g_ay) / TILESIZE][(int)(g_ax) / TILESIZE] == '1')
		{
			stock_vcast(g_ax, g_ay, angle);
			break ;
		}
		g_ax += g_xstep;
		g_ay += g_ystep;
	}
}
