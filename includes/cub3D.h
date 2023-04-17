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
# define NO 0
# define SO 1
# define WE 2
# define EA 3

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

typedef struct s_cub
{
	int		floor;
	int		ceiling;
	char	**paths;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	t_mlx	*bg;
	t_mlx	*imgs;
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
/*--------------------Display--------------------------------*/
void		init_mlx(t_cub *cub);
int			handle_keypress(int keysym, t_cub *cub);

/*-------------------------UTILS-----------------------------*/

int			ft_tablen(char **tab);
int			longest_row(char **tab);

/*-------------------------ERRORS---------------------------*/
/*--MAP--*/

int			map_closed(char **map);
int			map_elem(char **map);

#endif