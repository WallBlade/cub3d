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
# define WALL_H 500
# define FOV 90
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define PI 3.14159265358979323846

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

typedef struct s_ray
{
	double	dy;
	double	dx;
	double	posX_v;
	double	posY_v;
	double	posX_h;
	double	posY_h;
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
	int		x;
	int		y;
	double	angle;
}		t_player;

typedef struct s_cub
{
	int			floor;
	int			ceiling;
	char		**paths;
	char		**map;
	void		*mlx_ptr;
	void		*win_ptr;
	double		plane_dist;
	double		*distances;
	double		*heights;
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
double		determine_angle(char c);
int			is_player(char c);



/*-----------------------Parsing-utils----------------------*/

int			is_data(char *line);
int			check_filename(char *name);
void		print_error(char *str, char *arg);
char		*clean_data(char *path);
int			convert_colors(char *color);


/*--------------------------Parsing-------------------------*/

char		**get_file(int fd, int count);
char		**get_map(char **file);
char		**get_paths(char **file);
int			get_colors(char **file, int type);
/*-----------------------Raycasting-------------------------*/

double 	euc_distance(double x1, double y1, double x2, double y2);
double	castRay(t_cub *cub, double angle);
double	*distances(t_cub *cub);
double	*get_heights(t_cub *cub);
double	euc_distance(double x1, double y1, double x2, double y2);
void	get_next_vertical_point(double *x, double *y, double dy, double angle);
void	get_next_horizontal_point(double *x, double *y, double dx, double angle);


/*--------------------------Events--------------------------*/

int			handle_keypress(int keysym, t_cub *cub);

/*--------------------------Utils---------------------------*/

int			ft_tablen(char **tab);
int			longest_row(char **tab);

/*--------------------------Errors--------------------------*/
/*--err_map_closed--*/

int			map_closed(char **map);
int			map_elem(char **map);

/*---------------------------Draw---------------------------*/

int			render(t_cub *cub);
void 		render_walls(t_cub *cub);

#endif