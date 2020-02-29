/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:52:26 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 11:52:27 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	smallcas1(void)
{
	if (g_tab[0] == 1)
	{
		if (g_s.yprime[g_r.id][g_i] <= g_s.yc[g_r.id])
			g_s.xofset[g_r.id][g_i] += TILESIZE / 2;
		else
			g_s.xofset[g_r.id][g_i] = TILESIZE -
				TILESIZE / 2 - g_s.xofset[g_r.id][g_i];
	}
	else
	{
		if (g_s.yprime[g_r.id][g_i] >= g_s.yc[g_r.id])
			g_s.xofset[g_r.id][g_i] += TILESIZE / 2;
		else
			g_s.xofset[g_r.id][g_i] = TILESIZE -
				TILESIZE / 2 - g_s.xofset[g_r.id][g_i];
	}
}

void	smallcas2(void)
{
	if (g_tab[0] == 1)
	{
		if (g_s.yprime[g_r.id][g_i] >= g_s.yc[g_r.id])
			g_s.xofset[g_r.id][g_i] = TILESIZE -
				TILESIZE / 2 - g_s.xofset[g_r.id][g_i];
		else
			g_s.xofset[g_r.id][g_i] += TILESIZE / 2;
	}
	else
	{
		if (g_s.yprime[g_r.id][g_i] <= g_s.yc[g_r.id])
			g_s.xofset[g_r.id][g_i] = TILESIZE -
				TILESIZE / 2 - g_s.xofset[g_r.id][g_i];
		else
			g_s.xofset[g_r.id][g_i] += TILESIZE / 2;
	}
}
