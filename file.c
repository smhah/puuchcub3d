extern char** lines;
int j;
#include "cub3d.h"
Screen sc;
int save;
int saveplayer;

char	**fixline(void)
{
	printf("Error\ninvalide map, fix line %d", j + 1);
	return(NULL);
}

char	**invalidemap(void)
{
	printf("Error\ninvalidemap");
	return(NULL);
}
int   checknumber(char a)
{
    if (a != '1' && a != '2' && a != 'N' && a != '0')
    {
        printf("Error\n, please use numbers{0;1;2}");
        return(0);
    }
    if(a == 'N')
        saveplayer++;
    if(saveplayer > 1)
    {
        printf("Error\n, multiple player");
        return(0);
    }
    return(1);
}


char    **ft_cub3d(int fd)
{
	int i;
	int c;
	int d;
	char **tab;

	i = 0;
	j = 1;
	d = 0;
	while(get_next_line(fd, &lines[j]))
	{
		c = -1;
		tab = ft_split(lines[j], ' ');
		while(tab[++c])
        {
		 	lines[j][c] = tab[c][0];
            if(lines[0][c] != '1' || lines[j][0] != '1' || ( c == save - 1 && lines[j][c] != '1'))
            {
                printf("Error\n, Nap must be closed");
                return(NULL);
            }
            if(!checknumber(lines[j][c]))
                return(NULL);
        }
		if (c != save)
			return(fixline());
		lines[j][c] = '\0';
		if(lines[j][0] > '9' || lines[j][0] <'0')
			return(invalidemap());
		j++;
	}
	c = -1;
	tab = ft_split(lines[j], ' ');
	while(tab[++c])
    {
		lines[j][c] = tab[c][0];
        if(lines[j][c] != '1')
        {
            printf("Error\n, Map must be closed");
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
	return(lines);
}

int		ft_reso(char	*read)
{
	char	**tab;

	tab = ft_split(read, ' ');
	if(!tab || tab[1] == NULL || tab[2] == NULL || tab[3] != NULL)
	{
		printf("Error\ninvalideresolution");
		return(0);
	}
	sc.h = ft_atoi(tab[1]);
	sc.w = ft_atoi(tab[2]);
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
}

// void	stock_floor_color(char *color)
// {
// 	floor_color = malloc(ft_strlen(char *)color);
// 	while()
// }
int		readfile(int fd)
{
	char **read;
	char	**tab;
	char	**resolution;
	int i;
	int c;

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
		// else if(read[i][0] == 'F')
		// {
		// 	stock_floor_color(read[i]);
		// }
		else if(read[i][0] >= '0' && read[i][0] <= '9')
		{
				c = -1;
				//printf("read[i] %s\n", read[i]);
				tab = ft_split(read[i], ' ');
				lines[0] = strdup(read[i]);
				while(tab[++c])
					lines[0][c] = tab[c][0];
				lines[0][c] = '\0';
				save = c;
				if(!(lines = ft_cub3d(fd)))
					return(0);
		}
		else if (read[i][0])
		{
			printf("Error\ninvalidefile");
			return(0);
		}
		i++;
	}
	return(1);
}