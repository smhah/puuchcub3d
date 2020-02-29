/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 10:07:23 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 10:07:25 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		wrong_colors(int indice)
{
	if (indice == 1)
	{
		ft_putstr("Error\ninvalide floor color");
	}
	else
	{
		ft_putstr("Error\ninvalide celling color");
	}
	return (0);
}

int		check_next(char *s, int i, int indice)
{
	if (indice == 1)
	{
		if (s[i] == 'F' && s[i + 1] != '\0')
			return (wrong_colors(indice));
	}
	else
	{
		if (s[i] == 'C' && s[i + 1] != '\0')
			return (wrong_colors(indice));
	}
	return (1);
}

int		exit_cub3d(int indice)
{
	free_all();
	if (indice == 1)
		mlx_destroy_window(g_mlx_ptr, g_win_ptr);
	exit(-1);
	return (0);
}

void	*m_malloc(size_t n)
{
	void *t;

	t = malloc(n);
	if (!t)
		return (NULL);
	g_ptr_m[g_mc++].ptr = t;
	return (t);
}

int		free_all(void)
{
	int o;

	o = 0;
	while (o < g_mc)
	{
		free(g_ptr_m[o].ptr);
		o++;
	}
	return (0);
}
