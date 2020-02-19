#include "cub3d.h"

Screen sc;
text t;
Rays r;
player p;
fcolor fc;
ccolor cc;
opacity op;

unsigned int check_opacity(unsigned int hexcolor)
{
	double red;
	double green;
	double blue;
 
	op.opac = 1 - r.cast.distance / op.max_dist;
	red = ((hexcolor >> 16) & 255) * op.opac;
    green = ((hexcolor >> 8) & 255) * op.opac;
    blue = (hexcolor & 255) * op.opac;
	return(convert_rgb(red, green, blue));
}

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

	color = 0;
	check_sides(i);
	if(tab[0] == 0)
		t.txt_x = (int)r.cast.wallHitx % TILESIZE;
	else
		t.txt_x = (int)r.cast.wallHity % TILESIZE;
	projectDistance = (sc.w / 2) / tan(fov / 2);
	r.cast.distance = cosf(p.rotationAngle - r.rays[i]) * r.cast.distance;
	r.rayHight = (projectDistance / r.cast.distance) * TILESIZE;
	rectangle(i, color);
}


void	put_texture(int i, int j)
{
	if(tab[0] == 0 && tab[2] == 1)
		data[(int )i + (int )j * sc.w] = check_opacity(t.txtr1[t.txt_x + TILESIZE * t.txt_y]);
	else if(tab[0] == 0 && tab[2] == 0)
		data[(int )i + (int )j * sc.w] = check_opacity(t.txtr2[t.txt_x + TILESIZE * t.txt_y]);
	else if (tab[0] == 1 && tab[1] == 1)
		data[(int )i + (int )j * sc.w] = check_opacity(t.txtr4[t.txt_x + TILESIZE * t.txt_y]);
	else if (tab[0] == 1 && tab[1] == 0)
		data[(int )i + (int )j * sc.w] = check_opacity(t.txtr3[t.txt_x + TILESIZE * t.txt_y]);
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

unsigned int convert_rgb(int r, int g, int b)
{
	unsigned int color;

	color = r;
	color = (color << 8) + g;
	color = (color << 8) + b;
	return(color);
}

void	rectangle(int e, unsigned int color)
{
	int i;
	int j;
	int c;
	int save_x;

	color = 0xFFFFFF;
	save_x = e;
	i = e;
	c = 0;
	e = 0;
	j = sc.h / 2 - r.rayHight / 2 + p.look;
		c = j;
		while(e < j)
		{
			data[(int)i + (int)e *sc.w] = convert_rgb(cc.r, cc.g, cc.b);
			e++;
		}
		if(j < 0)
			j = 0;
		j = print_texture(j, c, i);
		while(j < sc.h)
		{
			data[(int)i + (int)j *sc.w] = convert_rgb(fc.r, fc.g, fc.b);
			j++;
		}
}


