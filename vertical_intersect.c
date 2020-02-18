#include "cub3d.h"

Rays r;
player p;
row rows;

void	stock_vhit(float ax, float ay, float angle)
{
	rows.xhit[rows.id] = (ax + (rayFacingLeft(angle) ? 1 : 0)) * (-1);
	rows.yhit[rows.id++] = ay;
	rows.xhit[rows.id] = MAXINT;
	rows.yhit[rows.id] = MAXINT;
}

void	stock_vcast(float ax, float ay, float angle)
{
	r.cast.verticalx = ax + (rayFacingLeft(angle) ? 1 : 0);
	r.cast.verticaly = ay;
}

void 	verticalintersect(float rayAngle)
{
	float xstep;
	float ystep;
	float ay;
	float ax;
	float angle;

	angle = normalize(rayAngle);
	xstep = TILESIZE * (rayFacingLeft(angle) ? -1 : 1);
	ystep = xstep * (tan(angle));
	ax = (floor(p.x / TILESIZE) * TILESIZE) + (!rayFacingLeft(angle) ? TILESIZE : 0);
	ay = p.y - (tan(angle) * (p.x - ax));
	if(rayFacingLeft(angle))
		ax--;
	while(ay >= 0 && ax >= 0 && ax < width && ay < height)
	{
		if(lines[(int )(ay) / TILESIZE][(int )(ax) / TILESIZE] == '2')
			stock_vhit(ax, ay, angle);
		if(lines[(int )(ay) / TILESIZE][(int )(ax) / TILESIZE] == '1')
		{
			stock_vcast(ax, ay, angle);
			break;
		}
		ax += xstep;
		ay += ystep;
	}
}