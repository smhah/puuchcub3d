/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:53:27 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 11:53:28 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	stocknopath(char *path)
{
	int i;
	int j;

	i = 0;
	j = 3;
	g_nopath = m_malloc(ft_strlen((char *)path) - 2);
	while (path[j])
		g_nopath[i++] = path[j++];
	g_nopath[i] = '\0';
	g_check_all++;
}

void	stocksopath(char *path)
{
	int i;
	int j;

	i = 0;
	j = 3;
	g_sopath = m_malloc(ft_strlen((char *)path) - 2);
	while (path[j])
		g_sopath[i++] = path[j++];
	g_sopath[i] = '\0';
	g_check_all++;
}

void	stockwepath(char *path)
{
	int i;
	int j;

	i = 0;
	j = 3;
	g_wepath = m_malloc(ft_strlen((char *)path) - 2);
	while (path[j])
		g_wepath[i++] = path[j++];
	g_wepath[i] = '\0';
	g_check_all++;
}

void	stockeapath(char *path)
{
	int i;
	int j;

	i = 0;
	j = 3;
	g_eapath = m_malloc(ft_strlen((char *)path) - 2);
	while (path[j])
		g_eapath[i++] = path[j++];
	g_eapath[i] = '\0';
	g_check_all++;
}
