#include "cub3d.h"

row rows;
Rays r;
player p;

void	sprite_dist(void)
{
	int i;
	int e;

	i = 0;
	while(rows.xhit[i] < MAXINT - 100)
	{
		e = rows.xhit[i];
		if( e < 0)
			e = e * (-1);
		rows.dist[i] = sqrtf(powf(p.x - e, 2) + powf(p.y - rows.yhit[i], 2));
		i++;
	}
	rows.dist[i] = MAXINT;
}

void	switchs(int i, int j)
{
	float tmp;

	tmp = rows.dist[i];
	rows.dist[i] = rows.dist[j];
	rows.dist[j] = tmp;
	tmp = rows.xhit[i];
	rows.xhit[i] = rows.xhit[j];
	rows.xhit[j] = tmp;
	tmp = rows.yhit[i];
	rows.yhit[i] = rows.yhit[j];
	rows.yhit[j] = tmp;
}

void	sort(void)
{
	int i;
	int j;

	j = 1;
	sprite_dist();
	i = 0;
	while(rows.dist[i] < MAXINT - 100)
	{
		j = i + 1;
		while(rows.dist[j] < MAXINT - 100)
		{
			if(rows.dist[i] > rows.dist[j])
				switchs(i, j);
			j++;
		}
		i++;
	}
	i = 0;
}