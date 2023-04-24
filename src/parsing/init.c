/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:43:56 by zel-kass          #+#    #+#             */
/*   Updated: 2023/04/24 15:43:46 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

double	determine_angle(char c)
{
	if (c == 'E')
		return (0.0);
	else if (c == 'N')
		return (90.0);
	else if (c == 'W')
		return (180.0);
	else if (c == 'S')
		return (270.0);
	else
		return (-1);
}

t_player	*player_data(char **map)
{
	int			x;
	int			y;
	t_player	*player;

	y = 0;
	player = collect(sizeof(t_player));
	if (!player)
		return (NULL);
	while (map && map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_player(map[y][x]))
			{	
				player->x = x;
				player->y = y;
				player->angle = determine_angle(map[y][x]);
				break ;
			}
			x++;
		}
		y++;
	}
	return (player);
}

t_cub	*init_cub(char *arg)
{
	int		fd;
	t_cub	*cub;
	int		count;
	char	**file;

	cub = collect(sizeof(t_cub));
	if (!cub)
		return (NULL);
	count = count_lines(arg);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = get_file(fd, count);
	cub->map = get_map(file);
	cub->paths = get_paths(file);
	cub->floor = get_colors(file, 1);
	cub->ceiling = get_colors(file, 2);
	cub->mlx_ptr = NULL;
	cub->win_ptr = NULL;
	cub->bg = collect(sizeof(t_cub));
	cub->imgs = NULL;
	cub->player = player_data(cub->map);
	cub->plane_dist = ((double)WIDTH / 2) / tan((double)FOV / 2);
	
	return (cub);
}

void	init_mlx(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		return ;
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, HEIGHT, WIDTH, "CUB");
	if (!cub->win_ptr)
		return (free(cub->win_ptr));
	cub->bg->img_ptr = mlx_new_image(cub->mlx_ptr, HEIGHT, WIDTH);
	cub->bg->addr= mlx_get_data_addr(cub->bg->img_ptr, &cub->bg->bpp, \
						&cub->bg->line_len, &cub->bg->endian);
	mlx_hook(cub->win_ptr, KeyPress, KeyPressMask, &handle_keypress, cub);
	mlx_loop_hook(cub->mlx_ptr, &render, cub);
	mlx_loop(cub->mlx_ptr);
	if (cub->bg->img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->bg->img_ptr);
	if (cub->win_ptr)
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	if (cub->mlx_ptr)
		mlx_destroy_display(cub->mlx_ptr);
	
}