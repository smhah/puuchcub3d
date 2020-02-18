#include "cub3d.h"

player	p;
sprite	s;
row		rows;

void    render(void)
{
	unsigned int	color;
	int				i;

	r.id = 0;
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
				if(lines[a][b] == 'N')
					gps(x, y);
				x+=TILESIZE;
				b++;
			}
			y+=TILESIZE;
			a++;
		}
	}
}

void	init_all(void)
{
	fov = 60 * (Pi / 180);
	Rays_width = 1;
	Num_rays = sc.w / Rays_width;
	r.rays = malloc(sizeof(float) * Num_rays);
	r.id = 0;
	p.x = 0;
	p.y = 0;
	p.radius = 3;
	p.turnDirection = 0;
	p.walkDirection = 0;
	p.rotationAngle = 0;
	p.moveSpeed = 4;
	p.rotationSpeed = 3 * Pi / 180;
	p.look = 0;
	p.map_a = 0;
	p.map_b = 0;
}

int main()
{
	int fd;

	fd = open("map.txt", O_RDWR);
	if(!readfile(fd))
		return(0);
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