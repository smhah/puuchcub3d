/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:38:27 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 04:38:28 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast(float rayangle)
{
	g_rows.id = 0;
	g_r.cast.wall_hit_x = MAXINT;
	g_r.cast.wall_hit_y = MAXINT;
	g_r.cast.horizontalx = MAXINT;
	g_r.cast.horizontaly = MAXINT;
	g_r.cast.verticalx = MAXINT;
	g_r.cast.verticaly = MAXINT;
	horizontalintersect(rayangle);
	verticalintersect(rayangle);
	g_s.sprite = g_rows.id;
	if (g_rows.id)
	{
		g_rows.id = 0;
		sort();
	}
	chose_points();
}

void	chose_points(void)
{
	float a;
	float b;
	float delta;

	a = sqrtf(powf(g_p.x - g_r.cast.verticalx, 2)
		+ powf(g_p.y - g_r.cast.verticaly, 2));
	b = sqrtf(powf(g_p.x - g_r.cast.horizontalx, 2)
		+ powf(g_p.y - g_r.cast.horizontaly, 2));
	if (a <= b)
	{
		g_r.cast.wall_hit_x = g_r.cast.verticalx;
		g_r.cast.wall_hit_y = g_r.cast.verticaly;
		g_r.cast.distance = a;
		delta = a;
	}
	else
	{
		g_r.cast.wall_hit_x = g_r.cast.horizontalx;
		g_r.cast.wall_hit_y = g_r.cast.horizontaly;
		g_r.cast.distance = b * (-1);
		delta = b;
	}
}
