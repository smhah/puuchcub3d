	#include "cub3d.h"

Screen sc;    

void	screen_shot(void)
{
	filesize = 54 + 3 * sc.w * sc.h;
	imgg = (unsigned char *)m_malloc(3 * sc.w * sc.h);
	memset(imgg, 0, 3 * sc.w * sc.h);

	unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
	unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
	unsigned char bmppad[3] = {0,0,0};

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

	f = open("img.bmp", O_CREAT| O_RDWR);
	//fwrite(bmpfileheader,1,14,f);
	write(f, bmpfileheader, 14);
	//fwrite(bmpinfoheader,1,40,f);
	write(f, bmpinfoheader, 40);
	for(int i=0; i< sc.h; i++)
	{
		for(int j=0; j<sc.w; j++)
		{
			write(f, data + (sc.w * (sc.h - i) + j), 3);
		}
		write(f, bmppad, (4 - (sc.w * 3) % 4) % 4);
	}
	free(imgg);
	close(f);
}
// void		create_bmp()
// {
// 	int				fd;;

// 	init_screen();

// }