#include "cub3d.h"

unsigned int check_opacity(unsigned int hexcolor)
{
	double red;
	double green;
	double blue;
 
	g_op.opac = 1 - g_r.cast.distance / g_op.max_dist;
	red = ((hexcolor >> 16) & 255) * g_op.opac;
    green = ((hexcolor >> 8) & 255) * g_op.opac;
    blue = (hexcolor & 255) * g_op.opac;
	return(convert_rgb(red, green, blue));
}

int		check_color(unsigned int hexcolor)
{
	double red;
	double green;
	double blue;
 
	red = ((hexcolor >> 16) & 255);
    green = ((hexcolor >> 8) & 255);
    blue = (hexcolor & 255);
	if(hexcolor == 0x000000)
		return(0);
	return(red == green && green == blue);
}

void	check_sides(int i)
{
	if(g_r.cast.distance < 0)
	{
		g_tab[0] = 0;
		g_r.cast.distance *= (-1);
	}
	else
		g_tab[0] = 1;
	if(ray_facing_left(normalize(g_r.rays[i])))
		g_tab[1] = 1;
	else
		g_tab[1] = 0;
	if(ray_facing_down(normalize(g_r.rays[i])))
		g_tab[2] = 1;
	else
		g_tab[2] = 0;	
}

void	render3d(int i)
{
	float projectDistance;
	unsigned int	color;

	color = 0;
	check_sides(i);
	if(g_tab[0] == 0)
		g_t.txt_x = (int)g_r.cast.wall_hit_x % TILESIZE;
	else
		g_t.txt_x = (int)g_r.cast.wall_hit_y % TILESIZE;
	projectDistance = (g_sc.w / 2) / tan(fov / 2);
	g_r.cast.distance = cosf(g_p.rotation_angle - g_r.rays[i]) * g_r.cast.distance;
	g_r.ray_hight = (projectDistance / g_r.cast.distance) * TILESIZE;
	rectangle(i, color);
}

void	put_texture(int i, int j)
{
	if(g_tab[0] == 0 && g_tab[2] == 1)
		data[(int )i + (int )j * g_sc.w] = check_opacity(g_t.txtr1[g_t.txt_x + TILESIZE * g_t.txt_y]);
	else if(g_tab[0] == 0 && g_tab[2] == 0)
		data[(int )i + (int )j * g_sc.w] = check_opacity(g_t.txtr2[g_t.txt_x + TILESIZE * g_t.txt_y]);
	else if (g_tab[0] == 1 && g_tab[1] == 1)
		data[(int )i + (int )j * g_sc.w] = check_opacity(g_t.txtr4[g_t.txt_x + TILESIZE * g_t.txt_y]);
	else if (g_tab[0] == 1 && g_tab[1] == 0)
		data[(int )i + (int )j * g_sc.w] = check_opacity(g_t.txtr3[g_t.txt_x + TILESIZE * g_t.txt_y]);
}

int		print_texture(int j, int c, int i)
{
	while(j - c <= g_r.ray_hight && j < g_sc.h)
	{
		g_t.txt_y = (int)((j - c) * TILESIZE) / g_r.ray_hight;
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
	j = g_sc.h / 2 - g_r.ray_hight / 2 + g_p.look;
		c = j;
		while(e < j)
		{
			data[(int)i + (int)e *g_sc.w] = convert_rgb(g_cc.r, g_cc.g, g_cc.b);
			e++;
		}
		if(j < 0)
			j = 0;
		j = print_texture(j, c, i);
		while(j < g_sc.h)
		{
			data[(int)i + (int)j *g_sc.w] = convert_rgb(g_fc.r, g_fc.g, g_fc.b);
			j++;
		}
}


