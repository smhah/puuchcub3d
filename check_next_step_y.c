#include "cub3d.h"

player p;

int		normy1(int i)
{
	int a;

	if (i == 1)
	{
		if (p.rotationAngle < 1.58 && p.rotationAngle > 1.56)
			a = (int )((p.y + 1 + sinf(p.rotationAngle) * p.moveSpeed) / TILESIZE);
		else 
		a = (int )((p.y + sinf(p.rotationAngle) * p.moveSpeed) / TILESIZE);
		if(lines[a][(int)(p.x / TILESIZE)] == '0' || lines[a][(int)(p.x / TILESIZE)] == 'N')
			return(1);
		else
			return (0);;
	}
	else if (i == 0)
	{
		a = (int )(p.y - sinf(p.rotationAngle) * p.moveSpeed) / TILESIZE;
		if(lines[a][(int)(p.x / TILESIZE)] == '0' || lines[a][(int)(p.x / TILESIZE)] == 'N')
			return(1);
		else
			return (0);
	}
	return(0);
}

int		normy2(int i)
{
	int a;

	if (i == 2)
	{
		a = (int )(p.y + sinf(p.rotationAngle - Pi / 2) * p.moveSpeed) / TILESIZE;
		if(lines[a][(int)(p.x / TILESIZE)] == '0' || lines[a][(int)(p.x / TILESIZE)] == 'N')
			return(1);
		else
			return (0);
	}
	else if (i == 3)
	{
		a = (int )(p.y + sinf(p.rotationAngle + Pi / 2) * p.moveSpeed) / TILESIZE;
		if(lines[a][(int)(p.x / TILESIZE)] == '0' || lines[a][(int)(p.x / TILESIZE)] == 'N')
			return(1);
		else
			return (0);
	}
	return(0);
}

int checknextstepy(int i)
{
	if (i == 1 || i == 0)
		return(normy1(i));
	if ( i == 2 || i == 3)
		return(normy2(i));
	return(0);
}