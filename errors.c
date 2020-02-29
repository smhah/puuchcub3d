/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 10:06:28 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 10:06:30 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		invalide_map_path(void)
{
	ft_putstr("Error\ninvalide map path\n");
	return (0);
}

int		wrong_argument(void)
{
	ft_putstr("Error\nplease enter 2 arguments");
	return (0);
}

int		wrong_format(int indice)
{
	if (indice == 0)
		ft_putstr("Error\nWrong map format");
	else
		ft_putstr("Error\nWrong save format");
	if (indice == 1)
		g_screenshot = 1;
	return (0);
}

int		check_file_name(char *s, int indice)
{
	if (indice == 1 && ft_strcmp("--save", s))
		return (wrong_format(indice));
	if (indice == 0)
	{
		if (!check_extension(s, indice))
			return (0);
	}
	return (1);
}

int		check_extension(char *s, int indice)
{
	int i;

	i = 0;
	while (s[i])
	{
		while (s[i] != '.')
		{
			if (s[i] == '\0')
				return (wrong_format(indice));
			i++;
		}
		i++;
		if (s[i])
		{
			if (s[i++] != 'c')
				return (wrong_format(indice));
			if (s[i++] != 'u')
				return (wrong_format(indice));
			if (s[i++] != 'b')
				return (wrong_format(indice));
			if (s[i])
				return (wrong_format(indice));
		}
	}
	return (1);
}
