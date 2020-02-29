/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:33:56 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 04:33:57 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		fill_others(char **tab, char **g_lines, int c, int j)
{
	int i;

	i = 0;
	while (tab[c][i])
	{
		g_lines[j][g_line++] = tab[c][i++];
	}
}

int			fill_others_center(char **tab, char **g_lines, int c, int j)
{
	int i;

	i = 0;
	while (tab[c][i])
	{
		g_lines[j][g_line] = tab[c][i++];
		if (g_lines[0][g_line] != '1' || g_lines[j][0] != '1' ||
			(g_line == g_save - 1 && g_lines[j][g_line] != '1'))
		{
			if (!unclosed_map())
				return (0);
		}
		if (!checknumber(g_lines[j][g_line]))
			return (0);
		g_line++;
	}
	return (1);
}

int			fill_others_last(char **tab, char **g_lines, int c, int j)
{
	int i;

	i = 0;
	while (tab[c][i])
	{
		g_lines[j][g_line] = tab[c][i++];
		if (g_lines[j][g_line] != '1')
		{
			ft_putstr("Error\n, Map must be closed");
			return (0);
		}
		if (!checknumber(g_lines[j][g_line]))
			return (0);
		g_line++;
	}
	return (1);
}

int			check_comma(char *color, int indice)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (color[i])
	{
		if (color[i] == ',')
			c++;
		i++;
	}
	if (c != 2)
	{
		if (indice == 1)
			ft_putstr("Error\ninvalide floor color, use 2 comma");
		else
		{
			ft_putstr("Error\ninvalide sky color, use 2 comma");
		}
		return (0);
	}
	return (1);
}
