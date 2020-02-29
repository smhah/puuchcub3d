#include "cub3d.h"

void	rendersprite(void)
{
	direction_info();
	if(g_rows.xhit[g_i] < 0)
	{
		g_rows.xhit[g_i] *= -1;
		g_s.xc[g_r.id] = floor((g_rows.xhit[g_i]) / TILESIZE) * TILESIZE + ((g_tab[0] == 1) ? TILESIZE / (-2) : (TILESIZE / 2));
		g_s.yc[g_r.id] = floor(g_rows.yhit[g_i] / TILESIZE) * TILESIZE + TILESIZE / 2;
		g_tab[2] = 1;
	}
	else
	{
		g_s.xc[g_r.id] = floor(g_rows.xhit[g_i] / TILESIZE) * TILESIZE +  TILESIZE / 2;
		g_s.yc[g_r.id] = floor(g_rows.yhit[g_i] / TILESIZE) * TILESIZE + ((g_tab[1] == 1) ? TILESIZE / 2 : TILESIZE / (-2));
		g_tab[2] = 0;
	}
	find_point();
}


void	rectosprite(float spriteHeight, int i)
{
	int j;
	int y;

	j = g_sc.h / 2 - spriteHeight / 2 + g_p.look;
	c = j;
	if(j < 0)
		j = 0;
	while(j - c < spriteHeight && j < g_sc.h)
	{
		y = (int)((j - c) * TILESIZE) / spriteHeight;
			if(g_t.sprite[(int)g_s.xofset[g_r.id][g_i] + TILESIZE * y] != 0x000000 && check_color(g_t.sprite[(int)g_s.xofset[g_r.id][g_i] + TILESIZE * y]))
				data[(int )i + (int )j * g_sc.w] = g_t.sprite[(int)g_s.xofset[g_r.id][g_i] + TILESIZE * y];
				//printf("color is%x\n", data[(int )i + (int )j * g_sc.w] = g_t.sprite[(int)g_s.xofset[g_r.id][g_i] + TILESIZE * y]);
		j++;
		//printf("heho\n");
	}
}

void	render3dsprite(void)
{
	float projectDistance;
	float spriteHeight;
	float dist;

	dist = sqrtf(powf(g_p.x - g_s.xc[g_r.id], 2) + powf(g_p.y - g_s.yc[g_r.id], 2));
	projectDistance = (g_sc.w / 2) / tan(fov / 2);
	spriteHeight = (projectDistance / dist) * TILESIZE;
	rectosprite(spriteHeight, g_r.id);
}
