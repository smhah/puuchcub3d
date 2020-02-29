#include "cub3d.h"

char		**fixline(void)
{
	ft_putstr("Error\ninvalide map,");
	return (NULL);
}

char		**invalidemap(void)
{
	ft_putstr("Error\ninvalidemap");
	return (NULL);
}

int			is_player(char a)
{
	if (a == 'W' || a == 'N' || a == 'S' || a == 'E')
		return (1);
	return (0);
}

int			check_intervale(char *s, int indice)
{
	int a;

	a = ft_atoi(s);
	if (a >= 0 && a <= 255)
		return (1);
	if (indice == 1)
		ft_putstr("Error\nInvalide Floor color, Please enter number between 0 & 255");
	else
		ft_putstr("Error\nInvalide Sky color, Please enter number between 0 & 255");
	return (0);
}

// char		*ft_first_split(char *s, int indice)
// {
// 	int i;
// 	char **tab;
// 	int a;
// 	int b;

// 	i = 0;
// 	tab = m_malloc(3);
// 	tab[0] = m_malloc(3);
// 	tab[1] = m_malloc(12);
// 	while(s[i])
// 	{
// 		while(s[i] && (s[i] == ' ' || s[i] == '\t'))
// 			i++;
		
// 	}
// }
int			check_if_char(char *s, int indice)
{
	int i;

	i = 0;
	s = ft_strtrim(s, " ");
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9'))
		{
			if (indice == 0)
				ft_putstr("Error\nInvalide resolution");
			if (indice == 1)
				ft_putstr("Error\ninvalide flo_or color");
			if (indice == 2)
				ft_putstr("Error\ninvalide sky color");
			return (0);
		}
		i++;
	}
	return (1);
}
