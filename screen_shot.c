/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_shot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:34:02 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 11:34:03 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		screen(void)
{
	g_img = mlx_new_image(g_mlx_ptr, g_sc.w, g_sc.h);
	g_data = (int*)mlx_get_data_addr(g_img, &g_imga, &g_imgb, &g_imgc);
	posplayer(g_height, g_width, g_lines, 0);
	cast_all_rays();
	render();
	screen_shot();
	free_all();
	return (0);
}

void	stock_bmp_header(void)
{
	int i;

	g_bmppad[0] = 0;
	g_bmppad[1] = 1;
	g_bmppad[2] = 2;
	i = 2;
	g_bmpfileheader[0] = 'B';
	g_bmpfileheader[1] = 'M';
	while (i < 8)
		g_bmpfileheader[i++] = 0;
	g_bmpfileheader[i++] = 54;
	while (i < 12)
		g_bmpfileheader[i++] = 0;
}

void	stock_bmp_info(void)
{
	int i;

	i = 0;
	g_bmpinfoheader[i++] = 40;
	while (i < 12)
		g_bmpinfoheader[i++] = 0;
	g_bmpinfoheader[i++] = 1;
	g_bmpinfoheader[i++] = 0;
	g_bmpinfoheader[i++] = 24;
	g_bmpinfoheader[i] = 0;
}

void	continue_stock(void)
{
	g_filesize = 54 + 3 * g_sc.w * g_sc.h;
	g_imgg = (unsigned char *)malloc(3 * g_sc.w * g_sc.h);
	memset(g_imgg, 0, 3 * g_sc.w * g_sc.h);
	g_bmpfileheader[2] = (unsigned char)(g_filesize);
	g_bmpfileheader[3] = (unsigned char)(g_filesize >> 8);
	g_bmpfileheader[4] = (unsigned char)(g_filesize >> 16);
	g_bmpfileheader[5] = (unsigned char)(g_filesize >> 24);
	g_bmpinfoheader[4] = (unsigned char)(g_sc.w);
	g_bmpinfoheader[5] = (unsigned char)(g_sc.w >> 8);
	g_bmpinfoheader[6] = (unsigned char)(g_sc.w >> 16);
	g_bmpinfoheader[7] = (unsigned char)(g_sc.w >> 24);
	g_bmpinfoheader[8] = (unsigned char)(g_sc.h);
	g_bmpinfoheader[9] = (unsigned char)(g_sc.h >> 8);
	g_bmpinfoheader[10] = (unsigned char)(g_sc.h >> 16);
	g_bmpinfoheader[11] = (unsigned char)(g_sc.h >> 24);
}

void	screen_shot(void)
{
	int i;
	int j;

	stock_bmp_header();
	stock_bmp_info();
	continue_stock();
	g_f = open("img.bmp", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	write(g_f, g_bmpfileheader, 14);
	write(g_f, g_bmpinfoheader, 40);
	i = 0;
	while (i < g_sc.h)
	{
		j = 0;
		while (j < g_sc.w)
		{
			write(g_f, g_data + (g_sc.w * (g_sc.h - i) + j), 3);
			j++;
		}
		write(g_f, g_bmppad, (4 - (g_sc.w * 3) % 4) % 4);
		i++;
	}
	free(g_imgg);
	close(g_f);
}
