#include "cub3d.h"

char	*ft_substr_trim(char const *s, unsigned int start, size_t len)
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