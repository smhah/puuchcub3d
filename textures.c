/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:54:50 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 11:54:51 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_xpm(unsigned int **info, char	*file)
{
	int		fd;
	void	*img;
	int		tab[5];

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putstr("Error\ninvalide path");
		return (0);
	}
	close(fd);
	img = mlx_xpm_file_to_image(g_mlx_ptr, file, &tab[0], &tab[1]);
	*info = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
	free(img);
	return (1);
}

int		ft_textures(void)
{
	char			*file5;

	file5 = "utils/pictures/barrel.xpm";
	if (!ft_xpm(&g_t.txtr1, g_eapath))
		return (0);
	if (!ft_xpm(&g_t.txtr2, g_sopath))
		return (0);
	if (!ft_xpm(&g_t.txtr3, g_nopath))
		return (0);
	if (!ft_xpm(&g_t.txtr4, g_wepath))
		return (0);
	if (!ft_xpm(&g_t.sprite, file5))
		return (0);
	return (1);
}
