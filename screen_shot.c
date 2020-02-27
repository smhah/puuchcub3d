#include "cub3d.h"

Screen sc;    

int		screen(void)
{
	img = mlx_new_image(mlx_ptr, sc.w, sc.h);
	data = (int*)mlx_get_data_addr(img, &a, &b, &c);
	posplayer(height, width, lines, 0);
	castAllRays();
	render();
	screen_shot();
	//system("leaks cub3D");
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
	filesize = 54 + 3 * sc.w * sc.h;
	imgg = (unsigned char *)malloc(3 * sc.w * sc.h);
	memset(imgg, 0, 3 * sc.w * sc.h);
	bmpfileheader[ 2] = (unsigned char)(filesize    );
	bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
	bmpfileheader[ 4] = (unsigned char)(filesize>>16);
	bmpfileheader[ 5] = (unsigned char)(filesize>>24);
	bmpinfoheader[ 4] = (unsigned char)(       sc.w    );
	bmpinfoheader[ 5] = (unsigned char)(       sc.w>> 8);
	bmpinfoheader[ 6] = (unsigned char)(       sc.w>>16);
	bmpinfoheader[ 7] = (unsigned char)(       sc.w>>24);
	bmpinfoheader[ 8] = (unsigned char)(       sc.h    );
	bmpinfoheader[ 9] = (unsigned char)(       sc.h>> 8);
	bmpinfoheader[10] = (unsigned char)(       sc.h>>16);
	bmpinfoheader[11] = (unsigned char)(       sc.h>>24);
}

void	screen_shot(void)
{
	int i;
	int j;

	stock_bmp_header();
	stock_bmp_info();
	continue_stock();
	f = open("img.bmp", O_WRONLY| O_CREAT, S_IRUSR | S_IWUSR);
	write(f, bmpfileheader, 14);
	write(f, bmpinfoheader, 40);
	i = 0;
	while(i < sc.h)
	{
		j = 0;
		while(j < sc.w)
		{
			write(f, data + (sc.w * (sc.h - i) + j), 3);
			j++;
		}
		write(f, bmppad, (4 - (sc.w * 3) % 4) % 4);
		i++;;
	}
	free(imgg);
	close(f);
}