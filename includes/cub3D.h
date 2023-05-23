/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:30:46 by zel-kass          #+#    #+#             */
/*   Updated: 2023/03/26 19:30:46 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 42
# define WIDTH 1080
# define HEIGHT 720
# define GREEN 0x00FF00
# define WALL_H 1000
# define FOV 90
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define PI 3.14159265358979323846
# define TEXT_W 64
# define TEXT_H 64

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <limits.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

typedef struct s_draw
{
	double	height;
    double	top;
    double	bottom;
	double	i;
	double	ratio;
}			t_draw;

typedef struct s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct s_ray
{
	double	dy;
	double	dx;
	t_pos	pos;
	int		map_x;
	int		map_y;
	t_pos	dir;
	int		step_x;
	int		step_y;
	double	side_x;
	double	side_y;
	double	camera_x;
	int		side;
}		t_ray;


typedef struct s_mlx
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}		t_mlx;

typedef struct s_player
{
	double	x;
	double	y;
	int		map_x;
	int		map_y;
	t_pos	dir;
	t_pos	plane;
}		t_player;

typedef struct s_cub
{
	int			floor;
	int			ceiling;
	char		**assets;
	char		**map;
	void		*mlx_ptr;
	void		*win_ptr;
	double		plane_dist;
	double		*distances;
	double		*heights;
	int			*tex;
	double		*hits;
	t_ray		*ray;
	t_mlx		*bg;
	t_mlx		*imgs;
	t_player	*player;
}		t_cub;


typedef struct s_garbage
{
	void				*ptr;
	struct s_garbage	*next;
}		t_garbage;

/*---------------------Garbage-collector--------------------*/

t_garbage	**singleton(void);
void		*collect(size_t size);
int			lstsize_garb(t_garbage *lst);
void		add_front(t_garbage **lst, void *ptr);
void		free_gc(void);

/*-----------------------Get-next-line----------------------*/

int			search_nl(char *line);
char		*clean_buf(char *buf, int red);
char		*clean_line(char *line, char *buf);
int			count_lines(char *arg);
char		*get_next_line(int fd);

/*---------------------------Init---------------------------*/

t_cub		*init_cub(char *arg);
void		init_mlx(t_cub *cub);
t_player	*player_data(char **map);
t_pos		determine_dir(char c);
t_pos		determine_plane(t_pos dir);
int			is_player(char c);

/*-----------------------Parsing-utils----------------------*/

int			is_data(char *line);
int			check_filename(char *name);
char		*clean_data(char *path);
int			convert_colors(char *color);
void		check_assets(char **assets);

/*--------------------------Parsing-------------------------*/

char		**get_file(int fd, int count);
char		**get_map(char **file);
char		**get_paths(char **file);
int			get_colors(char **file, int type);
void		get_data(int fd, int count, t_cub *cub);

/*-----------------------Raycasting-------------------------*/

double		*cast_ray(t_cub *cub);
t_ray		*init_ray(t_cub *cub, double cameraX);
double		*get_heights(t_cub *cub);
double		hit_point(t_ray *ray, double distance);
/*--textures--*/
int			download_image(t_cub *cub, t_mlx *asset, char *path);

/*--------------------------Events--------------------------*/

int			handle_keypress(int keysym, t_cub *cub);
int			mouse_click(t_cub *cub);

/*---utils----*/
int			is_move(int keysym);
void		update_player(t_cub *cub, double incr_x, double incr_y, int option);
void		update_player_rotate(t_cub *cub, int angle);
void		update_player_side(t_cub *cub, double incr_x, double incr_y);
void		update_player_fw(t_cub *cub, double incr_x, double incr_y);
int			get_orient(t_ray *ray);
void		move_player(int keysym, t_cub *cub);
void		rotate_player(int keysym, t_cub *cub);

/*--------------------------Utils---------------------------*/

int			ft_tablen(char **tab);
int			longest_row(char **tab);
void		print_error(char *str, char *arg);

/*--------------------------Errors--------------------------*/
/*--err_map_closed--*/

int			row_closed(char **map, int i);
void		map_closed(char **map);

/*--err_map_elem--*/

void		map_elem(char **map);

/*---------------------------Draw---------------------------*/

int			render(t_cub *cub);
void 		render_walls(t_cub *cub);
int			get_color(t_cub *cub, t_draw *wall, int x);

/*---------------------------Free---------------------------*/

void		free_tab(int **tab);
void		free_display(t_cub *cub);

#endif