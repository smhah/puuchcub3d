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
	if(1)
	{
		 //width, height, and bitcount are the key factors:
    int32_t width = 2;
    int32_t height = 2;
    uint16_t bitcount = 24;//<- 24-bit bitmap

    //take padding in to account
    int width_in_bytes = ((width * bitcount + 31) / 32) * 4;

    //total image size in bytes, not including header
    uint32_t imagesize = width_in_bytes * height;

    //this value is always 40, it's the sizeof(BITMAPINFOHEADER)
    const uint32_t biSize = 40;

    //bitmap bits start after headerfile, 
    //this is sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
    const uint32_t bfOffBits = 54; 

    //total file size:
    uint32_t filesize = 54 + imagesize;

    //number of planes is usually 1
    const uint16_t biPlanes = 1;

    //create header:
    //copy to buffer instead of BITMAPFILEHEADER and BITMAPINFOHEADER
    //to avoid problems with structure packing
    unsigned char header[54] = { 0 };
    memcpy(header, "BM", 2);
    memcpy(header + 2 , &filesize, 4);
    memcpy(header + 10, &bfOffBits, 4);
    memcpy(header + 14, &biSize, 4);
    memcpy(header + 18, &width, 4);
    memcpy(header + 22, &height, 4);
    memcpy(header + 26, &biPlanes, 2);
    memcpy(header + 28, &bitcount, 2);
    memcpy(header + 34, &imagesize, 4);

    //prepare pixel data:
    unsigned char* buf = malloc(imagesize);
    for(int row = height - 1; row >= 0; row--)
    {
        for(int col = 0; col < width; col++)
        {
            buf[row * width_in_bytes + col * 3 + 0] = 255;//blue
            buf[row * width_in_bytes + col * 3 + 1] = 0;//green
            buf[row * width_in_bytes + col * 3 + 2] = 0;//red
        }
    }

    FILE *fout = fopen("test.bmp", "wb");
    fwrite(header, 1, 54, fout);
    fwrite((char*)buf, 1, imagesize, fout);
    fclose(fout);
    free(buf);

    return 0;
	}
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


