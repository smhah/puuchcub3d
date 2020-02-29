/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:47:15 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 04:47:16 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		stock_floor_color(char **array, int indice)
{
	if (!check_if_char(array[0], indice) || !check_if_char(array[1], indice) ||
		!check_if_char(array[2], indice))
		return (0);
	if (!check_intervale(array[0], indice) || !check_intervale(array[1], indice)
		|| !check_intervale(array[2], indice))
		return (0);
	g_fc.r = ft_atoi(array[0]);
	g_fc.g = ft_atoi(array[1]);
	g_fc.b = ft_atoi(array[2]);
	g_check_all++;
	return (1);
}

int		stock_celling_color(char **array, int indice)
{
	if (!check_if_char(array[0], indice) || !check_if_char(array[1], indice)
		|| !check_if_char(array[2], indice))
		return (0);
	if (!check_intervale(array[0], indice) || !check_intervale(array[1], indice)
		|| !check_intervale(array[2], indice))
		return (0);
	g_cc.r = ft_atoi(array[0]);
	g_cc.g = ft_atoi(array[1]);
	g_cc.b = ft_atoi(array[2]);
	g_check_all++;
	return (1);
}

int		stock_colors(char **array, int indice)
{
	if (indice == 1)
	{
		if(!stock_floor_color(array, indice))
			return(0);
	}
	else
	{
		if(!stock_celling_color(array, indice))
			return(0);
	}
	return (1);
}

int		invalide_floor_celling_color(int indice)
{
	if (indice == 1)
		ft_putstr("Error\nInvalide floor color");
	else
		ft_putstr("Error\nInvalide celling color");
	return (0);
}

int		norme_stock_color(int indice, char **array, int i)
{
	if (i != 3)
		return (invalide_floor_celling_color(indice));
	if (indice == 1)
		i = stock_colors(array, indice);
	else
		i = stock_colors(array, indice);
	if (!i)
		return (0);
	return (1);
}
