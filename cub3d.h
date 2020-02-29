/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 06:05:48 by smhah             #+#    #+#             */
/*   Updated: 2020/02/29 06:05:49 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define PI 3.14
# define MAXINT 2147483647
# define TILESIZE 64
# define BUFFER_SIZE 300

# include <string.h>
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

void					init_orientation(char a);
int						check_char(char a);
int						checknumber(char a);
char					**last_line(char **tab, int j, int c, char **g_lines);
char					**unclosed_map(void);
int						check_comma(char *color, int indice);

void					fill_others(char **tab, char **g_lines, int c, int j);
int						fill_others_center(char **tab, char **g_lines, int c, int j);
int						fill_others_last(char **tab, char **g_lines, int c, int j);
int						g_save;
int						g_saveplayer;
//errors
int						invalide_map_path(void);
int						wrong_argument(void);
int						wrong_format(int indice);
int						check_file_name(char *s, int indice);
int						check_extension(char *s, int indice);

void					posplayer(int g_height, int g_width, char **g_lines, int indice);
int						init_read_map(char **g_read, int fd, int i);
char					**ft_read_map(int fd);
int						part1_map(void);
int						check_last_line(char *s);
int						boucle1(int j, int c, char **tabx);
char					**fixline(void);
char					**invalidemap(void);
int						is_player(char a);
int						check_intervale(char *s, int indice);
int						check_if_char(char *s, int indice);
int						g_j;
char					**last_line(char **tab, int j, int c, char **g_lines);
int						g_check_all;
void					stocknopath(char *path);
void					stocksopath(char *path);
void					stockwepath(char *path);
void					stockeapath(char *path);
int						stock_floor_color(char	**array, int indice);
int						stock_celling_color(char **array, int indice);
int						stock_colors(char	**array, int indice);
int						invalide_floor_celling_color(int indice);
int						norme_stock_color(int indice, char **array, int i);

unsigned char			bmppad[3];
unsigned char			bmpfileheader[14];
unsigned char			bmpinfoheader[40];
int						screen(void);
int						ft_strcmp(char *s1, char *s2);
int						check_color(unsigned int hexcolor);
int						free_all(void);
int						exit_cub3d(int indice);
char					**g_read;
void					*m_malloc(size_t n);
int						check_player(char a);
int						g_f;
unsigned char			*g_imgg;
int						g_filesize;  //w is your image width, h is image height, both int
int						g_screenshot;
void					screen_shot(void);
//get next
int						get_next_line(int fd, char **line);
size_t					ft_strlen(const char *str);
char					*ft_strchr(const char *str, int c);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_substr(char const *s, unsigned int start, size_t len);
int						g_save;
int						g_save_player;
int						g_line;
void					fill_others(char **tab, char **g_lines, int c, int j);
int						fill_others_last(char **tab, char **g_lines, int c, int j);
int						fill_others_center(char **tab, char **g_lines, int c, int j);
typedef struct			s_Screen{
	int					h;
	int 				w;
}						t_screen;
//
char					*nopath;
char					*sopath;
char					*wepath;
char					*eapath;
char					*floor_color;
char					*sky_color;
char					*ft_strdup_m(char *str);
void					cast(float ray);
char					*ft_strdup(char *str);
int						ray_facing_down(float angle);
int						ray_facing_left(float angle);
int						ray_facing_left(float angle);
char					**ft_split(char const *s, char c);
int						ft_atoi(char *s);
char					*ft_strtrim(char const *s1, char const *set);
char					*ft_substr1(char const *s, unsigned int start, size_t len);

typedef struct 			s_malloc
{
	void				*ptr;
}						t_malloc;
int						g_mc;
t_malloc				ptr_m[10000];

void					*img;
int						a;
int						b;
int						c;
int						*data;

int						test;
//Field of Vu
float					fov;
int						v;
//
//Mini Map
float					minimap;
//columnId
int						columnId;

//Number of rays and rays_width
float					rays_width;
int						Num_rays;
// g_height and Weight of the map
int						g_height;
int						g_width;

// mlx variables
void					*g_mlx_ptr;
void					*g_win_ptr;
int						g_i;
//indices for walls
int						g_tab[3];

// rays
typedef struct 			s_text
{
	unsigned int		*txtr1;
	unsigned int		*txtr2;
	unsigned int		*txtr3;
	unsigned int		*txtr4;
	unsigned int		*sprite;
	int					txt_x;
	int					txt_y;
}						t_text;

typedef struct 			s_cast_ray{
	float				horizontalx;
	float				horizontaly;
	float				verticalx;
	float				verticaly;
	float				wall_hit_x;
	float				wall_hit_y;
	float				distance;
}						t_cast_ray;

//castRay cast;

//Screen resolution
typedef struct			s_rays{
	float				*rays;
	float				ray_hight;
	int					id;
	t_cast_ray			cast;
}						t_rays;

typedef struct			s_row{
	float				xhit[1000];
	float				yhit[1000];
	float				dist[1000];
	int					id;
	float				ray_hight;
	t_cast_ray				cast;
}						t_row;

typedef struct			s_opacity{
	float				opac;
	float				max_dist;
}						t_opacity;
char					*ft_substr_trim(char const *s, unsigned int start, size_t len);
void					ft_putstr(char *s);
int						is_player(char a);
unsigned int			convert_rgb(int r, int g, int b);
unsigned int			check_opacity(unsigned int hexcolor);
char					**ft_read_map(int fd);
void					chose_points(void);
void					sort(void);
void					horizontalintersect(float rayangle);
void 					verticalintersect(float rayangle);
void					cast(float rayangle);
void					gps(int x, int y);
int						ft_xpm(unsigned int **info, char	*file);
int						ft_textures(void);
void					render3dsprite(void);
void					direction_info(void);
void    				correctofsset(void);
void					find_point(void);
float					normalize(float rayangle);
size_t					ft_strlen(const char *str);
int						ray_facing_down(float angle);
int						ray_facing_left(float angle);
int						ray_facing_left(float angle);
char					**ft_split(char const *s, char c);
int         			ft_atoi(char *s);
int 					readfile(int fd);
char    				**ft_cube3d(int fd);
void    				printmatrice(char **tab);
void					rendersprite(void);
void					blackscreen(void);
int						update();
void    				cast_all_rays(void);
void    				player_update(void);
void					walk_for_or_back(void);
void					walk_right_or_left(void);
int						keypress(int key);
int						keyreleased(int key);
void    				render(void);
int						checknextstepx(int i);
int						checknextstepy(int i);
void					render3d(int i);
void					rectangle(int e, unsigned color);
char					**g_lines;

float					g_rayangle;
typedef struct			s_sprite
{
	float				xc[10000];
	float				yc[10000];
	float				xprime[10000][1000];
	float				yprime[10000][1000];
	float				xofset[10000][1000];
	int					sprite;
	int     			i;
}						t_sprite;

typedef struct			s_player{
		float			x;
		float			y;
		float			radius;
		float			turn_direction;
		float			walk_direction;
		float			rotation_angle;
		float			move_speed;
		float			rotation_speed;
		short			walk_for;
		short			walk_back;
		short			cam_left;
		short			cam_right;
		int				look;
		short			look_up;
		short			look_down;
		short			walk_right;
		short			walk_left;
		int				map_a;
		int				map_b;
}						t_player;

typedef struct			s_fcolor{
	int					r;
	int					g;
	int					b;
}						t_fcolor;

typedef struct			s_read_map{
	char				**tabx;
	int					i;
	int					c;
	int					d;
}						t_readmap;

typedef struct			s_ccolor{
	int					r;
	int					g;
	int					b;
}						t_ccolor;

typedef struct			s_orientation{
	short				north;
	short				sud;
	short				est;
	short				ouest;
}						t_orientation;
t_player				g_p;
t_sprite				g_s;
t_row					g_rows;
t_opacity				g_op;
t_orientation			g_o;
t_fcolor				g_fc;
t_ccolor				g_cc;
t_screen				g_sc;
t_rays					g_r;
t_text					g_t;
t_readmap				g_map;
#endif
