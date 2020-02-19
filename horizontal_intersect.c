#include "cub3d.h"

Rays r;
player p;
row rows;

void	stock_hhit(float ax, float ay, float angle)
{
	rows.xhit[rows.id] = ax;
	rows.yhit[rows.id++] = ay + (!rayFacingDown(angle) ? 1 : 0);
	rows.xhit[rows.id] = MAXINT;
	rows.yhit[rows.id] = MAXINT;
}

void	stock_hcast(float ax, float ay, float angle)
{
	r.cast.horizontalx = ax;
	r.cast.horizontaly = ay + (!rayFacingDown(angle) ? 1 : 0);
}

void	horizontalintersect(float rayAngle)
{
	float ystep;
	float xstep;
	float ay;
	float ax;
	float angle;

	angle = normalize(rayAngle);
	ystep = TILESIZE * (rayFacingDown(angle) ? 1 : -1);
	xstep = tan(angle) ? ystep / tan(angle) : 0;
	ay = (floor(p.y / TILESIZE) * TILESIZE) + (rayFacingDown(angle) ? TILESIZE : 0);
	ax = p.x + ((ay - p.y) / tan(angle));
	r.cast.distance = 0;
	if(!rayFacingDown(angle))
		ay--;
	while(ay >= 0 && ax >= 0 && ax < width && ay < height)
	{
		if(lines[(int )(ay) / TILESIZE][(int )(ax) / TILESIZE] == '2')
			stock_hhit(ax, ay, angle);
		if(lines[(int )(ay) / TILESIZE][(int )(ax) / TILESIZE] == '1')
		{
			stock_hcast(ax, ay, angle);
			break;
		}
		ax += xstep;
		ay += ystep;
	}
}