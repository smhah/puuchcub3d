/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:29:37 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 11:29:39 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	check_opacity(unsigned int hexcolor)
{
	double red;
	double green;
	double blue;

	g_op.opac = 1 - g_r.cast.distance / g_op.max_dist;
	red = ((hexcolor >> 16) & 255) * g_op.opac;
	green = ((hexcolor >> 8) & 255) * g_op.opac;
	blue = (hexcolor & 255) * g_op.opac;
	return (convert_rgb(red, green, blue));
}

int				check_color(unsigned int hexcolor)
{
	double red;
	double green;
	double blue;

	red = ((hexcolor >> 16) & 255);
	green = ((hexcolor >> 8) & 255);
	blue = (hexcolor & 255);
	if (hexcolor == 0x000000)
		return (0);
	return (red == green && green == blue);
}

void			check_sides(int i)
{
	if (g_r.cast.distance < 0)
	{
		g_tab[0] = 0;
		g_r.cast.distance *= (-1);
	}
	else
		g_tab[0] = 1;
	if (ray_facing_left(normalize(g_r.rays[i])))
		g_tab[1] = 1;
	else
		g_tab[1] = 0;
	if (ray_facing_down(normalize(g_r.rays[i])))
		g_tab[2] = 1;
	else
		g_tab[2] = 0;
}
