#include "cub3d.h"

int		init_read_map(char **g_read, int fd, int i)
{
	int c;
	char	**tab;

	g_line = 0;
	c = -1;
	tab = ft_split(g_read[i], ' ');
	lines[0] = ft_strdup_m(g_read[i]);
	while(tab[++c])
		fill_others(tab, lines, c, 0);
	lines[0][g_line] = '\0';
	save = g_line;
	g_line = 0;
	if(!(lines = ft_read_map(fd)))
		return(0);
	check_all++;
	return(1);
}

char    **ft_read_map(int fd)
{
	j = 1;
	while(get_next_line(fd, &lines[j]))
	{
		if(lines[j][0] != '\0')
		{
			if(!part1_map())
				return(NULL);
		}
	}
	if(lines[j][0] != '\0')
	{
		if(!last_line(map.tabx, j, map.c, lines))
			return(0);
	}
	else
	{
		lines[j] = NULL;
		if(!check_last_line(lines[j - 1]))
			return(0);
	}
	return(lines);
}

int		part1_map(void)
{
	map.c = -1;
	map.tabx = ft_split(lines[j], ' ');
	if(!(map.c = boucle1(j, map.c, map.tabx)))
		return(0);
	if (g_line != save)
	{
		fixline();
		return(0);
	}
	if(lines[j][0] > '9' || lines[j][0] <'0')
	{
		invalidemap();
		return(0);
	}
	j++;
	return(1);
}

int		check_last_line(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if(s[i] != '1')
		{
			ft_putstr("Error\nunclosed map");
			return(0);
		}
		i++;
	}
	if(i != save)
		return(0);
	return(1);
}

int		boucle1(int j, int c, char **tabx)
{
	g_line = 0;
	while(tabx[++c])
	{
		if(!fill_others_center(tabx, lines, c, j))
			return(0);
	}
	lines[j][g_line] = '\0';
	return(c);
}