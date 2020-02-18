#include "cub3d.h"

Rays r;
row rows;
sprite s;
player p;

void	cast(float rayAngle)
{
	rows.id = 0;
	r.cast.wallHitx = MAXINT;
	r.cast.wallHity = MAXINT;
	r.cast.horizontalx = MAXINT;
	r.cast.horizontaly = MAXINT;
	r.cast.verticalx = MAXINT;
	r.cast.verticaly = MAXINT;
	s.xh[s.sprite] = MAXINT;
	s.yh[s.sprite] = MAXINT;
	s.xv[r.id][s.sprite] = MAXINT;
	s.xh[s.sprite] = MAXINT;
	s.x[r.id][s.sprite] = MAXINT;
	s.y[r.id][s.sprite] = MAXINT;
	s.dist[r.id][s.sprite] = 0;
	horizontalintersect(rayAngle);
	verticalintersect(rayAngle);
	s.sprite = rows.id;
	if(rows.id)
	{
		rows.id = 0;
		sort();
	}
	chosePoints();
}

void	chosePoints()
{
	float a;
	float b;
	float c;
	float d;
	float delta;

	a = sqrtf(powf(p.x - r.cast.verticalx, 2) + powf(p.y - r.cast.verticaly, 2));
	b = sqrtf(powf(p.x - r.cast.horizontalx, 2) + powf(p.y - r.cast.horizontaly, 2));
	if (a <= b)
	{
		r.cast.wallHitx = r.cast.verticalx;
		r.cast.wallHity = r.cast.verticaly;
		r.cast.distance = a;
		delta = a;
	}
	else
	{
		r.cast.wallHitx = r.cast.horizontalx;
		r.cast.wallHity = r.cast.horizontaly;
		r.cast.distance = b * (-1);
		delta = b;
	}
}