#include "cub3d.h"

player p;

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while(s[i])
		write(1, &s[i++], 1);
}

float	normalize(float rayAngle)
{
	rayAngle = fmod(rayAngle, 2 * Pi);
	while(rayAngle < 0)
		rayAngle += 2 * Pi;
	return(rayAngle);
}

int		rayFacingDown(float angle)
{
	if (sinf(angle) > 0)
		return(1);
	 return(0);
}

int		rayFacingLeft(float angle)
{
	if (cosf(angle) < 0)
		return (1);
	return(0);
}

void	gps(int x, int y)
{
	p.x = x + TILESIZE / 2;
	p.y = y + TILESIZE / 2;
}
