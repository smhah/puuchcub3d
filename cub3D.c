#include "cub3d.h"

player	p;
sprite	s;
row		rows;
opacity op;
orientation o;

void    render(void)
{
	unsigned int	color;

	r.id = 0;
	op.max_dist = sqrtf(powf(0 - sc.w, 2) + powf(0 - sc.h, 2));
	op.max_dist *= 0.85;
	while(r.id < Num_rays)
	{
		s.sprite = 0;
		color = 0xfa2c34;
		cast(r.rays[r.id]);
		render3d(r.id);
		g_i = s.sprite;
		while(g_i--)
		{
			if(rows.xhit[g_i] < MAXINT - 100 && rows.dist[g_i] < fabsf(r.cast.distance))
			{
				rendersprite();
				 if(s.xofset[r.id][g_i] > 0 && s.xofset[r.id][g_i] < 70)
				 	render3dsprite();
			}
		}
		r.id+=1;
	}
}

void    posplayer(int height, int width, char **lines, int indice)
{
	int a;
	int b;
	int x;
	int y;

	y = 0;
	a = 0;
	if(indice == 0)
	{
		while(y < height)
		{
			x = 0;
			b = 0;
			while(x < width)
			{
				if(is_player(lines[a][b]))
					gps(x, y);
				x+=TILESIZE;
				b++;
			}
			y+=TILESIZE;
			a++;
		}
	}
}

void	*m_malloc(size_t n)
{
	void *t;

	t = malloc(n);
	if(!t)
		return(NULL);
	ptr_m[g_mc++].ptr = t;
	return(t);
}

void	init_all(void)
{
	fov = 60 * (Pi / 180);
	Rays_width = 1;
	Num_rays = sc.w / Rays_width;
	r.rays = m_malloc(sizeof(float) * Num_rays);
	r.id = 0;
	p.x = 0;
	p.y = 0;
	p.radius = 3;
	p.turnDirection = 0;
	p.walkDirection = 0;
	if(o.north)
		p.rotationAngle = Pi / 2;
	if(o.sud)
		p.rotationAngle = (-Pi) / 2;
	if(o.est)
		p.rotationAngle = Pi;
	if(o.ouest)
		p.rotationAngle = 0;
	p.moveSpeed = 4;
	p.rotationSpeed = 1.8 * Pi / 180;
	p.look = 0;
	p.map_a = 0;
	p.map_b = 0;
	screenshot = 0;
}

int		wrong_format(void)
{
	ft_putstr("Error\nWrong map format");
	return(0);
}

int		wrong_argument(void)
{
	ft_putstr("please enter 2 arguments");
	return(0);
}

int		check_file_name(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		while(s[i] != '.')
		{
			if(s[i] == '\0')
				return(wrong_format());
			i++;
		}
		i++;
		if(s[i])
		{
			if(s[i++] != 'c')
				return(wrong_format());
			if(s[i++] != 'u')
				return(wrong_format());
			if(s[i++] != 'b')
				return(wrong_format());
			if(s[i])
				return(wrong_format());
		}
	}
	return(1);
}

int	free_all(void)
{
	int i;

	i = 0;
	while(i < g_mc)
	{
		free(ptr_m[i++].ptr);
		i++;
	}
	free(read);
	free(lines);
	return(0);
}

int main(int ac, char **av)
{
	int fd;
	(void)av;
	(void)ac;

	// if(ac != 2)
	// 	return(wrong_argument());
	g_mc = 0;
	if(!check_file_name("map.cub"))
		return(0);
	fd = open("map.cub", O_RDWR);
	if(!readfile(fd))
	{	
		//system("leaks cub3D");	
		return(0);
	}	//free_all();
	init_all();
	while(lines[p.map_a])
		p.map_a++;
	height = TILESIZE * p.map_a;
	while(lines[0][p.map_b])
		p.map_b++;
	width = TILESIZE * p.map_b;
	mlx_ptr = mlx_init();
	if((!ft_textures()))
		return (0);
	win_ptr = mlx_new_window(mlx_ptr, sc.w, sc.h, "mlx 42");
	img = mlx_new_image(mlx_ptr, sc.w, sc.h);
	data = (int*)mlx_get_data_addr(img, &a, &b, &c);
	posplayer(height, width, lines, 0);
	mlx_loop_hook(mlx_ptr, update, 0);
 	mlx_loop(mlx_ptr);
	return (0);
}
