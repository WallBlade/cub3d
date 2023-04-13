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
# define PATH 100
# define COLOR 101

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <limits.h>
#include "../libft/libft.h"

typedef	struct s_cub
{
	char	**colors;
	char	**paths;
	char	**map;
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

int		search_nl(char *line);
char    *clean_buf(char *buf, int red);
char	*clean_line(char *line, char *buf);
int		count_lines(char *arg);
char	*get_next_line(int fd);

/*---------------------------Init---------------------------*/

t_cub	*init_cub(char *arg);

/*-----------------------Parsing-utils----------------------*/

int		is_data(char *line);
int		check_filename(char *name);
void	print_error(char *str, char *arg);

/*--------------------------Parsing-------------------------*/

char	**get_file(int fd, int count);
char	**get_map(char **file);
char	**get_paths(char **file);
char	**get_colors(char **file);

#endif