/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_step_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:55:10 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 04:55:11 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_player(char a)
{
	if (a == 'W' || a == 'N' || a == 'S' || a == 'E')
		return (1);
	return (0);
}

int		normx1(int i)
{
	int b;

	if (i == 1)
	{
		b = (int)((g_p.x + cosf(g_p.rotation_angle) *
			(g_p.move_speed + TILESIZE / 2)) / TILESIZE);
		if (g_lines[(int)(g_p.y / TILESIZE)][b] == '0' ||
			check_player(g_lines[(int)(g_p.y / TILESIZE)][b]))
			return (1);
		else
			return (0);
	}
	else if (i == 0)
	{
		b = (int)(g_p.x - cosf(g_p.rotation_angle) *
			(g_p.move_speed + TILESIZE / 2)) / TILESIZE;
		if (g_lines[(int)(g_p.y / TILESIZE)][b] == '0' ||
			check_player(g_lines[(int)(g_p.y / TILESIZE)][b]))
			return (1);
		else
			return (0);
	}
	return (0);
}

int		normx2(int i)
{
	int b;

	if (i == 2)
	{
		b = (int)(g_p.x + cosf(g_p.rotation_angle - PI / 2) *
			(TILESIZE / 4 + g_p.move_speed)) / TILESIZE;
		if (g_lines[(int)(g_p.y / TILESIZE)][b] == '0' ||
			check_player(g_lines[(int)(g_p.y / TILESIZE)][b]))
			return (1);
		else
			return (0);
	}
	else if (i == 3)
	{
		b = (int)(g_p.x + cosf(g_p.rotation_angle + PI / 2) *
			(TILESIZE / 4 + g_p.move_speed)) / TILESIZE;
		if (g_lines[(int)(g_p.y / TILESIZE)][b] == '0' ||
			check_player(g_lines[(int)(g_p.y / TILESIZE)][b]))
			return (1);
		else
			return (0);
	}
	return (0);
}

int		checknextstepx(int i)
{
	if (i == 1 || i == 0)
		return (normx1(i));
	if (i == 2 || i == 3)
		return (normx2(i));
	return (0);
}
