/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 10:46:34 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 10:46:35 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_last(int i, char const *s1, char const *set)
{
	char	*c;
	int		res;

	res = i;
	while (i)
	{
		c = ft_strchr(set, s1[i]);
		if (c != 0)
			res = i;
		else
			break ;
		i--;
	}
	return (res);
}

static int	find_first(int i, char const *s1, char const *set)
{
	char	*c;
	int		res;

	res = i;
	while (s1[i])
	{
		c = ft_strchr(set, s1[i]);
		if (c != 0)
		{
			i++;
			res = i;
		}
		else
			break ;
	}
	return (res);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		start;
	int		end;
	int		len;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	i = 0;
	start = find_first(i, s1, set);
	end = find_last(len, s1, set);
	if (start > end)
		len = 0;
	else
		len = end - start;
	if (!(res = (char *)m_malloc(len + 1)))
		return (0);
	res = ft_substr_trim(s1, start, len);
	return (res);
}
