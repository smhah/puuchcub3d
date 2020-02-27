#include "cub3d.h"

int		exit_cub3d(int indice)
{
	free_all();
	//system("leaks cub3D");
	if(indice == 1)
		mlx_destroy_window(mlx_ptr, win_ptr);
	exit(-1);
	return(0);
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

int	free_all(void)
{
	int o;

	o = 0;
	while(o < g_mc)
	{
		free(ptr_m[o].ptr);
		o++;
	}
	return(0);
}