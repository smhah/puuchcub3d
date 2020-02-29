#include "cub3d.h"
  
int		screen(void)
{
	img = mlx_new_image(g_mlx_ptr, g_sc.w, g_sc.h);
	data = (int*)mlx_get_data_addr(img, &a, &b, &c);
	posplayer(g_height, g_width, g_lines, 0);
	cast_all_rays();
	render();
	screen_shot();
	free_all();
	return(0);
}

void	stock_bmp_header(void)
{
	int i;

	bmppad[0] = 0;
	bmppad[1] = 1;
	bmppad[2] = 2;
	i = 2;
	bmpfileheader[0] = 'B';
	bmpfileheader[1] = 'M';
	while(i < 8)
		bmpfileheader[i++] = 0;
	bmpfileheader[i++] = 54;
	while(i < 12)
		bmpfileheader[i++] = 0;
}

void	stock_bmp_info()
{
	int i;

	i = 0;
	bmpinfoheader[i++] = 40;
	while(i < 12)
		bmpinfoheader[i++] = 0;
	bmpinfoheader[i++] = 1;
	bmpinfoheader[i++] = 0;
	bmpinfoheader[i++] = 24;
	bmpinfoheader[i] = 0;
}

void	continue_stock(void)
{
	g_filesize = 54 + 3 * g_sc.w * g_sc.h;
	g_imgg = (unsigned char *)malloc(3 * g_sc.w * g_sc.h);
	memset(g_imgg, 0, 3 * g_sc.w * g_sc.h);
	bmpfileheader[ 2] = (unsigned char)(g_filesize    );
	bmpfileheader[ 3] = (unsigned char)(g_filesize>> 8);
	bmpfileheader[ 4] = (unsigned char)(g_filesize>>16);
	bmpfileheader[ 5] = (unsigned char)(g_filesize>>24);
	bmpinfoheader[ 4] = (unsigned char)(       g_sc.w    );
	bmpinfoheader[ 5] = (unsigned char)(       g_sc.w>> 8);
	bmpinfoheader[ 6] = (unsigned char)(       g_sc.w>>16);
	bmpinfoheader[ 7] = (unsigned char)(       g_sc.w>>24);
	bmpinfoheader[ 8] = (unsigned char)(       g_sc.h    );
	bmpinfoheader[ 9] = (unsigned char)(       g_sc.h>> 8);
	bmpinfoheader[10] = (unsigned char)(       g_sc.h>>16);
	bmpinfoheader[11] = (unsigned char)(       g_sc.h>>24);
}

void	screen_shot(void)
{
	int i;
	int j;

	stock_bmp_header();
	stock_bmp_info();
	continue_stock();
	g_f = open("img.bmp", O_WRONLY| O_CREAT, S_IRUSR | S_IWUSR);
	write(g_f, bmpfileheader, 14);
	write(g_f, bmpinfoheader, 40);
	i = 0;
	while(i < g_sc.h)
	{
		j = 0;
		while(j < g_sc.w)
		{
			write(g_f, data + (g_sc.w * (g_sc.h - i) + j), 3);
			j++;
		}
		write(g_f, bmppad, (4 - (g_sc.w * 3) % 4) % 4);
		i++;;
	}
	free(g_imgg);
	close(g_f);
}