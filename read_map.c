/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:12:35 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 11:12:36 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_read_map(char **g_read, int fd, int i)
{
	int		c;
	char	**tab;

	g_line = 0;
	c = -1;
	tab = ft_split(g_read[i], ' ');
	g_lines[0] = ft_strdup_m(g_read[i]);
	while (tab[++c])
		fill_others(tab, g_lines, c, 0);
	g_lines[0][g_line] = '\0';
	g_save = g_line;
	g_line = 0;
	if (!(g_lines = ft_read_map(fd)))
		return (0);
	g_check_all++;
	return (1);
}

char	**ft_read_map(int fd)
{
	g_j = 1;
	while (get_next_line(fd, &g_lines[g_j]))
	{
		if (g_lines[g_j][0] != '\0')
		{
			if (!part1_map())
				return (NULL);
		}
	}
	if (g_lines[g_j][0] != '\0')
	{
		if (!last_line(g_map.tabx, g_j, g_map.c, g_lines))
			return (0);
	}
	else
	{
		g_lines[g_j] = NULL;
		if (!check_last_line(g_lines[g_j - 1]))
			return (0);
	}
	return (g_lines);
}

int		part1_map(void)
{
	g_map.c = -1;
	g_map.tabx = ft_split(g_lines[g_j], ' ');
	if (!(g_map.c = boucle1(g_j, g_map.c, g_map.tabx)))
		return (0);
	if (g_line != g_save)
	{
		fixline();
		return (0);
	}
	if (g_lines[g_j][0] > '9' || g_lines[g_j][0] < '0')
	{
		invalidemap();
		return (0);
	}
	g_j++;
	return (1);
}

int		check_last_line(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1')
		{
			ft_putstr("Error\nunclosed map");
			return (0);
		}
		i++;
	}
	if (i != g_save)
		return (0);
	return (1);
}

int		boucle1(int j, int c, char **tabx)
{
	g_line = 0;
	while (tabx[++c])
	{
		if (!fill_others_center(tabx, g_lines, c, j))
			return (0);
	}
	g_lines[g_j][g_line] = '\0';
	return (c);
}
