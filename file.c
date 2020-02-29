#include "cub3d.h"

int		ft_reso(char *g_read)
{
	char	**tab;

	tab = ft_split(g_read, ' ');
	if(!tab || tab[1] == NULL || tab[2] == NULL ||
		tab[3] != NULL || tab[0][1] != '\0')
	{
		ft_putstr("Error\ninvalideresolution");
		return(0);
	}
	if(!check_if_char(tab[1], 0) || !check_if_char(tab[2], 0))
		return(0);
	g_sc.h = (ft_atoi(tab[1]) > 1440 ? 1440 : ft_atoi(tab[1]));
	g_sc.w = (ft_atoi(tab[2]) > 2560 ? 2560 : ft_atoi(tab[1]));
	g_check_all++;
	return(1);
}
int		stock_floor_celling_color(char *color, int indice)
{
	int i;
	int j;
	char **array;

	if(!check_comma(color, indice))
		return(0);
	i = 0;
	j = 1;
	floor_color = m_malloc(ft_strlen(color));
	while(color[j] < '0' || color[j] > '9')
		j++;
	while(color[j])
		floor_color[i++] = color[j++];
	floor_color[i] = '\0';
	array = ft_split(floor_color, ',');
	i = 0;
	while(array[i])
		i++;
	if(!norme_stock_color(indice, array , i))
		return(0);
	return(1);
}


int		split2(int i, int fd)
{
	if(g_read[i][0] == 'F')
	{
		if(!stock_floor_celling_color(g_read[i], 1))
			return (0);
	}
	else if(g_read[i][0] == 'C')
	{
		if(!stock_floor_celling_color(g_read[i], 2))
			return(0);
	}
	else if(g_read[i][0] == '1')
	{
		if(!init_read_map(g_read, fd, i))
			return(0);
	}
	else if (g_read[i][0])
	{
		ft_putstr("Error\ninvalidefile");
		return(0);
	}
	return(1);
}

int		readfile2(int i, int fd)
{
	while(get_next_line(fd, &g_read[i]))
	{
		if(g_read[i][0] == 'R')
		{
			if(!ft_reso(g_read[i]))
				return(0);
		}
		else if(g_read[i][0] == 'N' && g_read[i][1] == 'O')
			stocknopath(g_read[i]);
		else if(g_read[i][0] == 'S' && g_read[i][1] == 'O')
			stocksopath(g_read[i]);
		else if(g_read[i][0] == 'W' && g_read[i][1] == 'E')
			stockwepath(g_read[i]);
		else if(g_read[i][0] == 'E' && g_read[i][1] == 'A')
			stockeapath(g_read[i]);
		else
			if(!split2(i, fd))
				return(0);
		i++;
	}
	return(1);
}

int		readfile(int fd)
{
	int i;

	g_check_all = 0;
    g_saveplayer = 0;
	i = 0;
	g_read = m_malloc(sizeof(char **) * 100);
	g_lines = m_malloc(sizeof(char ** ) * 100);
	if(!readfile2(i, fd))
		return(0);
	if(g_check_all != 8)
	{
		ft_putstr("Error\ninvalide file\n");
		return(0);
	}
	return(1);
}