#include "mlx.h"
#include "utils/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

typedef struct s_Screen{
	int	h;
	int w;
}Screen;

char    *nopath;
char    *sopath;
char    *wepath;
char    *eapath;
char	*floor_color;
char	*sky_color;

#define Pi 3.14
#define MAXINT 2147483647
#define TILESIZE 64
void    cast(float ray);

int		rayFacingDown(float angle);
int		rayFacingLeft(float angle);
int rayFacingLeft(float angle);
char		**ft_split(char const *s, char c);
int         ft_atoi(char *s);

void *img;
int a,b,c;
int *data;

int test;
//Field of Vu
float fov;
int v;
//
//Mini Map
float minimap;
//columnId
int columnId;

//Number of rays and Rays_width
float   Rays_width;
unsigned int   Num_rays;
// height and Weight of the map
int height;
int width;

// mlx variables
void *mlx_ptr;
void *win_ptr;
int		g_i;
//indices for walls
int		tab[3];

// rays
typedef struct s_text
{
	unsigned int	*txtr1;
	unsigned int	*txtr2;
	unsigned int	*txtr3;
	unsigned int 	*txtr4;
	unsigned int 	*sprite;
	int				txt_x;
	int				txt_y;
}text;

typedef struct s_castRay{
	float horizontalx;
	float horizontaly;
	float verticalx;
	float verticaly;
	float rayAngle;
	float wallHitx;
	float wallHity;
	float distance;
	float isRayFacingDown;
}castRay;

//castRay cast;

//Screen resolution
typedef struct s_Rays{
	float *rays;
	float rayHight;
	int id;
	castRay cast;
}Rays;

typedef struct s_row{
	float xhit[1000];
	float yhit[1000];
	float dist[1000];
    int id;
	float rayHight;
	castRay cast;
}row;

void	chosePoints(void);
void	sort(void);
void	horizontalintersect(float rayAngle);
void 	verticalintersect(float rayAngle);
void	cast(float rayAngle);
void	gps(int x, int y);
int		ft_xpm(unsigned int **info, char	*file);
int		ft_textures(void);
void	render3dsprite(void);
void	direction_info(void);
void    correctofsset(void);
void	find_point(void);
float	normalize(float rayAngle);
size_t	ft_strlen(const char *str);
int		rayFacingDown(float angle);
int		rayFacingLeft(float angle);
int rayFacingLeft(float angle);
char		**ft_split(char const *s, char c);
int         ft_atoi(char *s);
int 	readfile(int fd);
char    **ft_cube3d(int fd);
void    printmatrice(char **tab);
void	rendersprite(void);
void	blackscreen(void);
int		update();
void    castAllRays(void);
void    player_update(void);
void	walk_for_or_back(void);
void	walk_right_or_left(void);
int		keypress(int key);
int		keyreleased(int key);
void    render(void);
int		checknextstepx(int i);
int		checknextstepy(int i);
void	render3d(int i);
void	rectangle(int e, int L, unsigned color);

Rays r;
Screen sc;

// stock map into lines
char **lines;

float rayAngle;
typedef struct s_sprite
{
	float	x[10000][1000];
	float	y[10000][1000];
	float	xh[10000];
	float	xv[10000][1000];
	float	yv[10000][1000];
	float	yh[10000];
	float	dist[10000][1000];
	float	xc[10000];
	float	yc[10000];
	float	xprime[10000][1000];
	float	yprime[10000][1000];
	float	delta[10000];
	float	xofset[10000][1000];
	int		info[10000];
	int		sprite;
	int		saveh;
	int		savev;
    int     saveax[1000];
    int     saveay[1000];
    int     saves[1000][1000];
    int      i;
}sprite;

typedef struct s_player{
		float x;
		float y;
		float radius;
		float turnDirection; // -1 if left, +1 if right
		float walkDirection; // -1 if back, +1 if front
		float rotationAngle; // = Math.PI / 2;
		float moveSpeed; // = 3.0;
		float rotationSpeed; // = 3 * (Math.PI / 180);
		short walk_for;
		short walk_back;
		short cam_left;
		short cam_right;
		int		look;
		short	look_up;
		short	look_down;
		short	walk_right;
		short	walk_left;
		int map_a;
		int map_b;
}player;