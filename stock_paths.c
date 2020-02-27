#include "cub3d.h"

void	stocknopath(char *path)
{
	int i;
	int j;

	i = 0;
	j = 3;
		nopath = m_malloc(ft_strlen((char *)path) - 2);
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
		sopath = m_malloc(ft_strlen((char *)path) - 2);
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
	wepath = m_malloc(ft_strlen((char *)path) - 2);
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
	eapath = m_malloc(ft_strlen((char *)path) - 2);
	while(path[j])
		eapath[i++] = path[j++];
	eapath[i] = '\0';
	check_all++;
}
