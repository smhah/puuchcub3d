
#include "cub3d.h"

sprite s;
player p;

void    bigcas1(void)
{
    if(tab[2] == 0)
		{
			if(s.xprime[r.id][g_i] >= s.xc[r.id])
				s.xofset[r.id][g_i] += TILESIZE / 2;
			else
				s.xofset[r.id][g_i] = TILESIZE - TILESIZE / 2 - s.xofset[r.id][g_i];
		}
		else
		{
			if(tab[0] == 1)
			{
				if(s.yprime[r.id][g_i] <= s.yc[r.id])
					s.xofset[r.id][g_i] += TILESIZE / 2;
				else
					s.xofset[r.id][g_i] = TILESIZE - TILESIZE / 2 - s.xofset[r.id][g_i];
			}
			else
			{
				if(s.yprime[r.id][g_i] >= s.yc[r.id])
					s.xofset[r.id][g_i] += TILESIZE / 2;
				else
					s.xofset[r.id][g_i] = TILESIZE - TILESIZE / 2 - s.xofset[r.id][g_i];
			}
		}
}

void    bigcas2(void)
{
    if(tab[2] == 0)
    {
        if(s.xprime[r.id][g_i] >= s.xc[r.id])
            s.xofset[r.id][g_i] = TILESIZE - TILESIZE / 2 - s.xofset[r.id][g_i];
        else
            s.xofset[r.id][g_i] += TILESIZE / 2;
    }
    else
    {
        if(tab[0] == 1)
        {
            if(s.yprime[r.id][g_i] >= s.yc[r.id])
                s.xofset[r.id][g_i] = TILESIZE - TILESIZE / 2 - s.xofset[r.id][g_i];
            else
                s.xofset[r.id][g_i] += TILESIZE / 2;
        }
        else
        {
            if(s.yprime[r.id][g_i] <= s.yc[r.id])
                s.xofset[r.id][g_i] = TILESIZE - TILESIZE / 2 - s.xofset[r.id][g_i];
            else
                s.xofset[r.id][g_i] += TILESIZE / 2;
        }
    }
}

void    correctofsset(void)
{
    if(tab[1] == 0)
	{
		bigcas1();
	}
	else
	{
        bigcas2();
	}
}

void	direction_info(void)
{
	if(rayFacingLeft(normalize(r.rays[r.id])))
		tab[0] = 1;
	else
		tab[0] = 0;
	if(rayFacingDown(normalize(r.rays[r.id])))
		tab[1] = 1;
	else
		tab[1] = 0;
}

void	find_point(void)
{
	float a;
	float b;
	float angle;

	angle = normalize(r.rays[r.id]);
	angle = (Pi - angle) * (-1);
	b = atan2(p.y - s.yc[r.id], p.x - s.xc[r.id]);
	b = normalize(b);
	a = angle - b;
	s.xprime[r.id][g_i] = p.x + (s.xc[r.id] - p.x) * cosf(a) - (s.yc[r.id] - p.y) * sinf(a);
	s.yprime[r.id][g_i] = p.y + (s.xc[r.id] - p.x) * sinf(a) + (s.yc[r.id] - p.y) * cosf(a);
	s.xofset[r.id][g_i] = sqrtf(powf(s.xprime[r.id][g_i] - s.xc[r.id], 2) + powf(s.yprime[r.id][g_i] - s.yc[r.id], 2));
    correctofsset();
}