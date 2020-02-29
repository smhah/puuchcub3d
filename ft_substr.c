/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:03:40 by smhah             #+#    #+#             */
/*   Updated: 2019/10/21 04:57:37 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_substr1(char const *s, unsigned int start, size_t len)
{
	char		*buf;
	size_t		i;

	i = 0;
	if (s)
	{
		if (!(buf = (char *)m_malloc(sizeof(char) * (len + 1))))
			return (0);
	}
	else
		return (0);
	while ((i < len) && (start + i < ft_strlen(s)))
	{
		buf[i] = s[start + i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

char	*ft_strdup_m(char *str)
{
	size_t			leng;
	unsigned int	i;
	char			*dup;

	i = 0;
	leng = ft_strlen((char *)str);
	dup = (char *)m_malloc((sizeof(char) * (leng + 1)));
	if (dup == 0)
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = str[i];
	return (dup);
}
