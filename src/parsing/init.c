/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:43:56 by zel-kass          #+#    #+#             */
/*   Updated: 2023/05/08 19:25:39 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

t_pos	determine_dir(char c)
{
	t_pos	dir;
	
	if (c == 'E')
	{
		dir.x = 1;
		dir.y = 0;
	}
	else if (c == 'N')
	{
		dir.x = 0;
		dir.y = -1;
	}
	else if (c == 'W')
	{
		dir.x = -1;
		dir.y = 0;
	}
	else
	{
		dir.x = 0;
		dir.y = 1;
	}
	return (dir);
}

t_pos	determine_plane(t_pos dir)
{
	t_pos	plane;

	(void)dir;
	if (dir.x == 0)
	{
		plane.x = dir.y * -1;
		plane.y = dir.x;
	}
	else
	{
		plane.x = dir.y;
		plane.y = dir.x * -1;
	}
	return (plane);
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
				player->x = x + 0.5;
				player->y = y + 0.5;
				player->mapX = x;
				player->mapY = y;
				player->dir = determine_dir(map[y][x]);
				player->plane = determine_plane(player->dir);
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

	cub = collect(sizeof(t_cub));
	if (!cub)
		return (NULL);
	count = count_lines(arg);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (NULL);
	get_data(fd, count, cub);
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
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, WIDTH, HEIGHT, "CUB");
	if (!cub->win_ptr)
		return (free(cub->win_ptr));
	cub->bg->img_ptr = mlx_new_image(cub->mlx_ptr, WIDTH, HEIGHT);
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