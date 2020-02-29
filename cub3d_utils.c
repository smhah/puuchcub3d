/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 05:33:15 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 05:33:16 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

float		normalize(float rayangle)
{
	rayangle = fmod(rayangle, 2 * PI);
	while (rayangle < 0)
		rayangle += 2 * PI;
	return (rayangle);
}

int			ray_facing_down(float angle)
{
	if (sinf(angle) > 0)
		return (1);
	return (0);
}

int			ray_facing_left(float angle)
{
	if (cosf(angle) < 0)
		return (1);
	return (0);
}

void		gps(int x, int y)
{
	g_p.x = x + TILESIZE / 2;
	g_p.y = y + TILESIZE / 2;
}
