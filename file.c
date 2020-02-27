#include "cub3d.h"

extern char** lines;

Screen sc;
int save;
int saveplayer;

fcolor fc;
ccolor cc;
orientation o;

void	init_orientation(char a)
{
	o.sud = 0;
	o.est = 0;
	o.north = 0;
	o.ouest = 0;
	if(a == 'W')
		o.ouest = 1;
	if (a == 'S')
		o.sud = 1;
	if (a == 'E')
		o.est = 1;
	if (a == 'N')
		o.north = 1;
}

int		check_char(char a)
{
	if (a != '1' && a != '2' && a != 'N' &&
		a != '0' && a != 'W' && a != 'S' && a != 'E')
			return(1);
	return(0);
}

int   checknumber(char a)
{
    if (check_char(a))
    {
        ft_putstr("Error\n, please use numbers{0;1;2}");
        return(0);
    }
    if(is_player(a))
	{
		init_orientation(a);
        saveplayer++;
	}
    if(saveplayer > 1)
    {
        ft_putstr("Error\n, multiple player");
        return(0);
    }
    return(1);
}

char	**last_line(char **tab, int j, int c, char **lines)
{
	if(saveplayer == 0)
	{
		ft_putstr("Error\nI don't see any player please enter one");
		return(NULL);
	}
	c = -1;
	g_line = 0;
	tab = ft_split(lines[j], ' ');
	while(tab[++c])
    {
		if(!fill_others_last(tab, lines, c, j))
			return(NULL);
    }
	lines[j][g_line] = '\0';
	lines[++j] = NULL;
	if (g_line != save)
		return(fixline());
	if(lines[j - 1][0] > '9' || lines[j - 1][0] <'0')
		return(invalidemap());
	j = 0;
	return(tab);
}

char	**unclosed_map(void)
{
		ft_putstr("Error\n, Map must be closed");
		return(NULL);
}

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
	sc.h = (ft_atoi(tab[1]) > 1440 ? 1440 : ft_atoi(tab[1]));
	sc.w = (ft_atoi(tab[2]) > 2550 ? 2550 : ft_atoi(tab[1]));
	check_all++;
	return(1);
}

int		check_comma(char *color, int indice)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while(color[i])
	{
		if(color[i] == ',')
			c++;
		i++;
	}
	if(c != 2)
	{
		if (indice == 1)
			ft_putstr("Error\ninvalide floor color, use 2 comma");
		else
		{
			ft_putstr("Error\ninvalide sky color, use 2 comma");
		}
		return(0);
	}
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

void		fill_others(char **tab, char **lines, int c, int j)
{
	int i;

	i = 0;
	while(tab[c][i])
	{
		lines[j][g_line++] = tab[c][i++];
	}
}
int			fill_others_center(char **tab, char **lines, int c, int j)
{
	int i;

	i = 0;
	while(tab[c][i])
	{
		lines[j][g_line] = tab[c][i++];
		if(lines[0][g_line] != '1' || lines[j][0] != '1'
			|| ( g_line == save - 1 && lines[j][g_line] != '1'))
				{
					if(!unclosed_map())
					return(0);
				}
		if(!checknumber(lines[j][g_line]))
			return(0);
		g_line++;
	}
	return(1);
}

int		fill_others_last(char **tab, char **lines, int c, int j)
{
	int i;

	i = 0;
	while(tab[c][i])
	{
		lines[j][g_line] = tab[c][i++];
		if(lines[j][g_line] != '1')
        {
            ft_putstr("Error\n, Map must be closed");
            return(0);
        }
        if(!checknumber(lines[j][g_line]))
            return(0);
			g_line++;
	}
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

	check_all = 0;
    saveplayer = 0;
	i = 0;
	g_read = m_malloc(sizeof(char **) * 100);
	lines = m_malloc(sizeof(char ** ) * 100);
	if(!readfile2(i, fd))
		return(0);
	if(check_all != 8)
	{
		ft_putstr("invalide file\n");
		return(0);
	}
	return(1);
}