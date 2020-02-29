#include "cub3d.h"

void	stock_vhit(float ax, float ay, float angle)
{
	g_rows.xhit[g_rows.id] = (ax + (ray_facing_left(angle) ? 1 : 0)) * (-1);
	g_rows.yhit[g_rows.id++] = ay;
	g_rows.xhit[g_rows.id] = MAXINT;
	g_rows.yhit[g_rows.id] = MAXINT;
}

void	stock_vcast(float ax, float ay, float angle)
{
	g_r.cast.verticalx = ax + (ray_facing_left(angle) ? 1 : 0);
	g_r.cast.verticaly = ay;
}

void 	verticalintersect(float rayangle)
{
	float xstep;
	float ystep;
	float ay;
	float ax;
	float angle;

	angle = normalize(rayangle);
	xstep = TILESIZE * (ray_facing_left(angle) ? -1 : 1);
	ystep = xstep * (tan(angle));
	ax = (floor(g_p.x / TILESIZE) * TILESIZE) + (!ray_facing_left(angle) ? TILESIZE : 0);
	ay = g_p.y - (tan(angle) * (g_p.x - ax));
	if(ray_facing_left(angle))
		ax--;
	while(ay >= 0 && ax >= 0 && ax < g_width && ay < g_height)
	{
		if(g_lines[(int )(ay) / TILESIZE][(int )(ax) / TILESIZE] == '2')
			stock_vhit(ax, ay, angle);
		if(g_lines[(int )(ay) / TILESIZE][(int )(ax) / TILESIZE] == '1')
		{
			stock_vcast(ax, ay, angle);
			break;
		}
		ax += xstep;
		ay += ystep;
	}
}