#include "cub3d.h"

row rows;
player p;
sprite s;
text t;

void	rendersprite(void)
{
	direction_info();
	if(rows.xhit[g_i] < 0)
	{
		rows.xhit[g_i] *= -1;
		s.xc[r.id] = floor((rows.xhit[g_i]) / TILESIZE) * TILESIZE + ((tab[0] == 1) ? TILESIZE / (-2) : (TILESIZE / 2));
		s.yc[r.id] = floor(rows.yhit[g_i] / TILESIZE) * TILESIZE + TILESIZE / 2;
		tab[2] = 1;
	}
	else
	{
		s.xc[r.id] = floor(rows.xhit[g_i] / TILESIZE) * TILESIZE +  TILESIZE / 2;
		s.yc[r.id] = floor(rows.yhit[g_i] / TILESIZE) * TILESIZE + ((tab[1] == 1) ? TILESIZE / 2 : TILESIZE / (-2));
		tab[2] = 0;
	}
	find_point();
}

void	rectosprite(float spriteHeight, int i)
{
	int j;
	int y;

	j = sc.h / 2 - spriteHeight / 2 + p.look;
	c = j;
	if(j < 0)
		j = 0;
	while(j - c < spriteHeight && j < sc.h)
	{
		y = (int)((j - c) * TILESIZE) / spriteHeight;
			if(t.sprite[(int)s.xofset[r.id][g_i] + TILESIZE * y] != 0xff000000 && t.sprite[(int)s.xofset[r.id][g_i] + TILESIZE * y] != 0x000000)
				data[(int )i + (int )j * sc.w] = t.sprite[(int)s.xofset[r.id][g_i] + TILESIZE * y];
				//printf("color is%x\n", data[(int )i + (int )j * sc.w] = t.sprite[(int)s.xofset[r.id][g_i] + TILESIZE * y]);
		j++;
		//printf("heho\n");
	}
}

void	render3dsprite(void)
{
	float projectDistance;
	float spriteHeight;
	float dist;

	dist = sqrtf(powf(p.x - s.xc[r.id], 2) + powf(p.y - s.yc[r.id], 2));
	projectDistance = (sc.w / 2) / tan(fov / 2);
	spriteHeight = (projectDistance / dist) * TILESIZE;
	rectosprite(spriteHeight, r.id);
}
