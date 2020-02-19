#include "cub3d.h"

extern char** lines;
int j;
int check_all;

Screen sc;
int save;
int saveplayer;

fcolor fc;
ccolor cc;
orientation o;

char	**fixline(void)
{
	ft_putstr("Error\ninvalide map,");
	return(NULL);
}

char	**invalidemap(void)
{
	ft_putstr("Error\ninvalidemap");
	return(NULL);
}

int		is_player(char a)
{
	if(a == 'W' || a == 'N' || a == 'S' || a == 'E')
		return (1);
	return(0);
}

int   checknumber(char a)
{
    if (a != '1' && a != '2' && a != 'N' && a != '0' && a != 'W' && a != 'S' && a != 'E')
    {
        ft_putstr("Error\n, please use numbers{0;1;2}");
        return(0);
    }
    if(is_player(a))
	{
		o.sud = 0;
		o.est = 0;
		o.north = 0;
		o.ouest = 0;
		if(a == 'W')
		{
			ft_putstr("check\n");
			o.ouest = 1;
		}
		if (a == 'S')
			o.sud = 1;
		if (a == 'E')
			o.est = 1;
		if (a == 'N')
			o.north = 1;
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
	tab = ft_split(lines[j], ' ');
	while(tab[++c])
    {
		lines[j][c] = tab[c][0];
        if(lines[j][c] != '1')
        {
            ft_putstr("Error\n, Map must be closed");
            return(NULL);
        }
        if(!checknumber(lines[j][c]))
            return(NULL);
    }
	lines[j][c] = '\0';
	lines[++j] = NULL;
	j--;
	if (c != save)
		return(fixline());
	if(lines[j][0] > '9' || lines[j][0] <'0')
		return(invalidemap());
	j = 0;
	return(tab);
}
char	**unclosed_map(void)
{
		ft_putstr("Error\n, Map must be closed");
		return(NULL);
}

int		boucle1(int j, int c, char **tabx)
{
	while(tabx[++c])
	{
		lines[j][c] = tabx[c][0];
		if(lines[0][c] != '1' || lines[j][0] != '1' || ( c == save - 1 && lines[j][c] != '1'))
		{
			if(!unclosed_map())
				return(0);
		}
		if(!checknumber(lines[j][c]))
			return(0);
	}
	return(c);
}

char    **ft_read_map(int fd)
{
	int i;
	int c;
	int d;
	char **tabx;

	i = 0;
	j = 1;
	d = 0;
	while(get_next_line(fd, &lines[j]))
	{
		c = -1;
		tabx = ft_split(lines[j], ' ');
		if(!(c = boucle1(j, c, tabx)))
			return(NULL);
		if (c != save)
			return(fixline());
		lines[j][c] = '\0';
		if(lines[j][0] > '9' || lines[j][0] <'0')
			return(invalidemap());
		j++;
	}
	if(!last_line(tabx, j, c, lines))
		return(0);
	return(lines);
}

int		ft_reso(char	*read)
{
	char	**tab;

	tab = ft_split(read, ' ');
	if(!tab || tab[1] == NULL || tab[2] == NULL || tab[3] != NULL)
	{
		ft_putstr("Error\ninvalideresolution");
		return(0);
	}
	sc.h = ft_atoi(tab[1]);
	sc.w = ft_atoi(tab[2]);
	check_all++;
	return(1);
}

void	stocknopath(char *path)
{
	int i;
	int j;

	i = 0;
	j = 3;
		nopath = malloc(ft_strlen((char *)path) - 2);
		while(path[j])
			nopath[i++] = path[j++];
		nopath[i] = '\0';
	check_all++;
}

void	stocksopath(char *path)
{
	int i;
	int j;

	i = 0;
	j = 3;
		sopath = malloc(ft_strlen((char *)path) - 2);
		while(path[j])
			sopath[i++] = path[j++];
		sopath[i] = '\0';
	check_all++;
}

void	stockwepath(char *path)
{
	int i;
	int j;

	i = 0;
	j = 3;
	wepath = malloc(ft_strlen((char *)path) - 2);
	while(path[j])
		wepath[i++] = path[j++];
	wepath[i] = '\0';
	check_all++;
}

void	stockeapath(char *path)
{
	int i;
	int j;

	i = 0;
	j = 3;
	eapath = malloc(ft_strlen((char *)path) - 2);
	while(path[j])
		eapath[i++] = path[j++];
	eapath[i] = '\0';
	check_all++;
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
			ft_putstr("Error\ninvalide sky color, use 2 comma");
		return(0);
	}
	return(1);
}

void	stock_colors(char	**array, int indice)
{

	if(indice == 1)
	{
		fc.r = ft_atoi(array[0]);
		fc.g = ft_atoi(array[1]);
		fc.b = ft_atoi(array[2]);
		check_all++;
	}
	else
	{
		cc.r = ft_atoi(array[0]);
		cc.g = ft_atoi(array[1]);
		cc.b = ft_atoi(array[2]);
		check_all++;
	}
}

int		invalide_floor_celling_color(int indice)
{
	if (indice == 1)
		ft_putstr("Error\nInvalide floor color");
	else
		ft_putstr("Error\nInvalide celling color");
	return(0);
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
	floor_color = malloc(ft_strlen(color));
	while(color[j] < '0' || color[j] > '9')
		j++;
	while(color[j])
		floor_color[i++] = color[j++];
	floor_color[i] = '\0';
	array = ft_split(floor_color, ',');
	i = 0;
	while(array[i])
		i++;
	if(i != 3)
		return(invalide_floor_celling_color(indice));
	if(indice == 1)
		stock_colors(array, indice);
	else
		stock_colors(array, indice);
	return(1);
}


int		readfile(int fd)
{
	char **read;
	char	**tab;
	int i;
	int c;

	check_all = 0;
    saveplayer = 0;
	i = 0;
	read = malloc(sizeof(char **) * 100);
	lines = malloc(sizeof(char ** ) * 100);
	while(get_next_line(fd, &read[i]))
	{
		if(read[i][0] == 'R')
		{
			if(!ft_reso(read[i]))
				return(0);
		}
		else if(read[i][0] == 'N' && read[i][1] == 'O')
			stocknopath(read[i]);
		else if(read[i][0] == 'S' && read[i][1] == 'O')
			stocksopath(read[i]);
		else if(read[i][0] == 'W' && read[i][1] == 'E')
			stockwepath(read[i]);
		else if(read[i][0] == 'E' && read[i][1] == 'A')
			stockeapath(read[i]);
		else if(read[i][0] == 'F')
		{
			if(!stock_floor_celling_color(read[i], 1))
				return(0);
		}
		else if(read[i][0] == 'C')
		{
			if(!stock_floor_celling_color(read[i], 2))
				return(0);
		}
		else if(read[i][0] == '1')
		{
				c = -1;
				tab = ft_split(read[i], ' ');
				lines[0] = strdup(read[i]);
				while(tab[++c])
					lines[0][c] = tab[c][0];
				lines[0][c] = '\0';
				save = c;
				if(!(lines = ft_read_map(fd)))
					return(0);
				check_all++;
		}
		else if (read[i][0])
		{
			ft_putstr("Error\ninvalidefile");
			return(0);
		}
		i++;
	}
	if(check_all != 8)
	{
		printf("%d\n", check_all);
		ft_putstr("invalide file\n");
		return(0);
	}
	return(1);
}