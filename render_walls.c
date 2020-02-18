#include "cub3d.h"

Screen sc;
text t;
Rays r;
player p;

void	check_sides(int i)
{
	if(r.cast.distance < 0)
	{
		tab[0] = 0;
		r.cast.distance *= (-1);
	}
	else
		tab[0] = 1;
	if(rayFacingLeft(normalize(r.rays[i])))
		tab[1] = 1;
	else
		tab[1] = 0;
	if(rayFacingDown(normalize(r.rays[i])))
		tab[2] = 1;
	else
		tab[2] = 0;	
}

void	render3d(int i)
{
	float projectDistance;
	unsigned int	color;

	check_sides(i);
	if(tab[0] == 0)
		t.txt_x = (int)r.cast.wallHitx % TILESIZE;
	else
		t.txt_x = (int)r.cast.wallHity % TILESIZE;
	projectDistance = (sc.w / 2) / tan(fov / 2);
	r.cast.distance = cosf(p.rotationAngle - r.rays[i]) * r.cast.distance;
	r.rayHight = (projectDistance / r.cast.distance) * TILESIZE;
	rectangle(i, 2, color);
}

void	put_texture(int i, int j)
{
	if(tab[0] == 0 && tab[2] == 1)
		data[(int )i + (int )j * sc.w] = t.txtr1[t.txt_x + TILESIZE * t.txt_y];
	else if(tab[0] == 0 && tab[2] == 0)
		data[(int )i + (int )j * sc.w] = t.txtr2[t.txt_x + TILESIZE * t.txt_y];
	else if (tab[0] == 1 && tab[1] == 1)
		data[(int )i + (int )j * sc.w] = t.txtr4[t.txt_x + TILESIZE * t.txt_y];
	else if (tab[0] == 1 && tab[1] == 0)
		data[(int )i + (int )j * sc.w] = t.txtr3[t.txt_x + TILESIZE * t.txt_y];
}

int		print_texture(int j, int c, int i)
{
	while(j - c <= r.rayHight && j < sc.h)
	{
		t.txt_y = (int)((j - c) * TILESIZE) / r.rayHight;
		put_texture(i, j);
		j++;
	}
	return(j);
}

void	rectangle(int e, int L, unsigned color)
{
	int i;
	int j;
	int c;
	int i_end;
	int save_x;

	save_x = e;
	i = e;
	c = 0;
	e = 0;
	j = sc.h / 2 - r.rayHight / 2 + p.look;
		c = j;
		while(e < j)
		{
			data[(int)i + (int)e *sc.w] = 0x77b5fe;
			e++;
		}
		if(j < 0)
			j = 0;
		j = print_texture(j, c, i);
		while(j < sc.h)
		{
			data[(int)i + (int)j *sc.w] = 0xffa54f;
			j++;
		}
}