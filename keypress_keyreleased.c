/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_keyreleased.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:07:07 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 11:07:08 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		keypress(int key)
{
	if (key == 53)
	{
		free_all();
		exit(1);
	}
	if (key == 0)
		g_p.walk_left = 1;
	if (key == 2)
		g_p.walk_right = 1;
	if (key == 13)
		g_p.walk_for = 1;
	if (key == 1)
		g_p.walk_back = 1;
	if (key == 123)
		g_p.cam_left = 1;
	if (key == 124)
		g_p.cam_right = 1;
	if (key == 126)
		g_p.look_up = 1;
	else if (key == 125)
		g_p.look_down = 1;
	return (0);
}

int		keyreleased(int key)
{
	if (key == 0)
	{
		g_p.walk_left = -1;
	}
	if (key == 2)
		g_p.walk_right = -1;
	if (key == 13)
		g_p.walk_for = -1;
	if (key == 1)
		g_p.walk_back = -1;
	if (key == 123)
		g_p.cam_left = -1;
	if (key == 124)
		g_p.cam_right = -1;
	if (key == 126)
		g_p.look_up = -1;
	else if (key == 125)
		g_p.look_down = -1;
	return (0);
}
