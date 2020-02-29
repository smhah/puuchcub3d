/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_step_y.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 05:02:20 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 05:02:24 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		normy1(int i)
{
	int a;

	if (i == 1)
	{
		if (g_p.rotation_angle < 1.58 && g_p.rotation_angle > 1.56)
			a = (int)((g_p.y + 1 + sinf(g_p.rotation_angle) *
				(g_p.move_speed + TILESIZE / 2)) / TILESIZE);
		else
			a = (int)((g_p.y + sinf(g_p.rotation_angle) *
				(g_p.move_speed + TILESIZE / 2)) / TILESIZE);
		if (g_lines[a][(int)(g_p.x / TILESIZE)] == '0' ||
			check_player(g_lines[a][(int)(g_p.x / TILESIZE)]))
			return (1);
	}
	else if (i == 0)
	{
		a = (int)(g_p.y - sinf(g_p.rotation_angle) *
			(g_p.move_speed + TILESIZE / 2)) / TILESIZE;
		if (g_lines[a][(int)(g_p.x / TILESIZE)] == '0' ||
			check_player(g_lines[a][(int)(g_p.x / TILESIZE)]))
			return (1);
	}
	return (0);
}

int		normy2(int i)
{
	int a;

	if (i == 2)
	{
		a = (int)(g_p.y + sinf(g_p.rotation_angle - PI / 2) *
			(TILESIZE / 4 + g_p.move_speed)) / TILESIZE;
		if (g_lines[a][(int)(g_p.x / TILESIZE)] == '0' ||
			check_player(g_lines[a][(int)(g_p.x / TILESIZE)]))
			return (1);
	}
	else if (i == 3)
	{
		a = (int)(g_p.y + sinf(g_p.rotation_angle + PI / 2) *
			(TILESIZE / 4 + g_p.move_speed)) / TILESIZE;
		if (g_lines[a][(int)(g_p.x / TILESIZE)] == '0' ||
			check_player(g_lines[a][(int)(g_p.x / TILESIZE)]))
			return (1);
	}
	return (0);
}

int		checknextstepy(int i)
{
	if (i == 1 || i == 0)
		return (normy1(i));
	if (i == 2 || i == 3)
		return (normy2(i));
	return (0);
}
