#include "cub3d.h"

void	stock_hhit(float ax, float ay, float angle)
{
	g_rows.xhit[g_rows.id] = ax;
	g_rows.yhit[g_rows.id++] = ay + (!ray_facing_down(angle) ? 1 : 0);
	g_rows.xhit[g_rows.id] = MAXINT;
	g_rows.yhit[g_rows.id] = MAXINT;
}

void	stock_hcast(float ax, float ay, float angle)
{
	g_r.cast.horizontalx = ax;
	g_r.cast.horizontaly = ay + (!ray_facing_down(angle) ? 1 : 0);
}

void	horizontalintersect(float rayangle)
{
	float ystep;
	float xstep;
	float ay;
	float ax;
	float angle;

	angle = normalize(rayangle);
	ystep = TILESIZE * (ray_facing_down(angle) ? 1 : -1);
	xstep = tan(angle) ? ystep / tan(angle) : 0;
	ay = (floor(g_p.y / TILESIZE) * TILESIZE) + (ray_facing_down(angle) ? TILESIZE : 0);
	ax = g_p.x + ((ay - g_p.y) / tan(angle));
	g_r.cast.distance = 0;
	if(!ray_facing_down(angle))
		ay--;
	while(ay >= 0 && ax >= 0 && ax < g_width && ay < g_height)
	{
		if(g_lines[(int )(ay) / TILESIZE][(int )(ax) / TILESIZE] == '2')
			stock_hhit(ax, ay, angle);
		if(g_lines[(int )(ay) / TILESIZE][(int )(ax) / TILESIZE] == '1')
		{
			stock_hcast(ax, ay, angle);
			break;
		}
		ax += xstep;
		ay += ystep;
	}
}