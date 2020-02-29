/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:38:57 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 11:38:58 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_dist(void)
{
	int i;
	int e;

	i = 0;
	while (g_rows.xhit[i] < MAXINT - 100)
	{
		e = g_rows.xhit[i];
		if (e < 0)
			e = e * (-1);
		g_rows.dist[i] = sqrtf(powf(g_p.x - e, 2)
			+ powf(g_p.y - g_rows.yhit[i], 2));
		i++;
	}
	g_rows.dist[i] = MAXINT;
}

void	switchs(int i, int j)
{
	float tmp;

	tmp = g_rows.dist[i];
	g_rows.dist[i] = g_rows.dist[j];
	g_rows.dist[j] = tmp;
	tmp = g_rows.xhit[i];
	g_rows.xhit[i] = g_rows.xhit[j];
	g_rows.xhit[j] = tmp;
	tmp = g_rows.yhit[i];
	g_rows.yhit[i] = g_rows.yhit[j];
	g_rows.yhit[j] = tmp;
}

void	sort(void)
{
	int i;
	int j;

	j = 1;
	sprite_dist();
	i = 0;
	while (g_rows.dist[i] < MAXINT - 100)
	{
		j = i + 1;
		while (g_rows.dist[j] < MAXINT - 100)
		{
			if (g_rows.dist[i] > g_rows.dist[j])
				switchs(i, j);
			j++;
		}
		i++;
	}
	i = 0;
}
