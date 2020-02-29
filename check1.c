/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 05:28:39 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 05:28:41 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_orientation(char a)
{
	g_o.sud = 0;
	g_o.est = 0;
	g_o.north = 0;
	g_o.ouest = 0;
	if (a == 'W')
		g_o.ouest = 1;
	if (a == 'S')
		g_o.sud = 1;
	if (a == 'E')
		g_o.est = 1;
	if (a == 'N')
		g_o.north = 1;
}

int			check_char(char a)
{
	if (a != '1' && a != '2' && a != 'N' &&
		a != '0' && a != 'W' && a != 'S' && a != 'E')
		return (1);
	return (0);
}

int			checknumber(char a)
{
	if (check_char(a))
	{
		ft_putstr("Error\n, please use numbers{0;1;2}");
		return (0);
	}
	if (is_player(a))
	{
		init_orientation(a);
		g_saveplayer++;
	}
	if (g_saveplayer > 1)
	{
		ft_putstr("Error\n, multiple player");
		return (0);
	}
	return (1);
}

char		**last_line(char **tab, int j, int c, char **g_lines)
{
	if (g_saveplayer == 0)
	{
		ft_putstr("Error\nI don't see any player please enter one");
		return (NULL);
	}
	c = -1;
	g_line = 0;
	tab = ft_split(g_lines[j], ' ');
	while (tab[++c])
	{
		if (!fill_others_last(tab, g_lines, c, j))
			return (NULL);
	}
	g_lines[j][g_line] = '\0';
	g_lines[++j] = NULL;
	if (g_line != g_save)
		return (fixline());
	if (g_lines[j - 1][0] > '9' || g_lines[j - 1][0] < '0')
		return (invalidemap());
	j = 0;
	return (tab);
}

char		**unclosed_map(void)
{
	ft_putstr("Error\n, Map must be closed");
	return (NULL);
}
