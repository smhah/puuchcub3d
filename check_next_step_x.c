#include "cub3d.h"

player p;

int	normx1(int i)
{
	if (i == 1)
	{
		b = (int )((p.x + cosf(p.rotationAngle) * p.moveSpeed) / TILESIZE);
		if(lines[(int)(p.y / TILESIZE)][b] == '0' || lines[(int)(p.y / TILESIZE)][b] == 'N')
			return(1);
		else
			return (0);
	}
	else if (i == 0)
	{
		b = (int )(p.x - cosf(p.rotationAngle) * p.moveSpeed) / TILESIZE;
		if(lines[(int)(p.y / TILESIZE)][b] == '0' || lines[(int)(p.y / TILESIZE)][b] == 'N')
			return(1);
		else
			return (0);
	}
	return(0);
}

int normx2(int i)
{
	if (i == 2)
	{
		b = (int )(p.x + cosf(p.rotationAngle - Pi / 2) * p.moveSpeed) / TILESIZE;
		if(lines[(int)(p.y / TILESIZE)][b] == '0' || lines[(int)(p.y / TILESIZE)][b] == 'N')
			return(1);
		else
			return (0);
	}
	else if (i == 3)
	{
		b = (int )(p.x + cosf(p.rotationAngle + Pi / 2) * p.moveSpeed) / TILESIZE;
		if(lines[(int)(p.y / TILESIZE)][b] == '0' || lines[(int)(p.y / TILESIZE)][b] == 'N')
			return(1);
		else
			return (0);
	}
	return(0);
}
int checknextstepx(int i)
{
	int b;


	if (i == 1 || i == 0)
	{
		return(normx1(i));
	}
	if (i == 2 || i == 3)
	{
		return(normx2(i));
	}
	return(0);
}