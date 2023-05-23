/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:57:44 by zel-kass          #+#    #+#             */
/*   Updated: 2023/05/23 11:11:37 by zel-kass         ###   ########.fr       */
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

	plane.x = dir.y * -1;
	plane.y = dir.x;
	return (plane);
}

void	load_data(t_player *player, char **map, int x, int y)
{
	player->x = x + 0.5;
	player->y = y + 0.5;
	player->map_x = x;
	player->map_y = y;
	player->dir = determine_dir(map[y][x]);
	player->plane = determine_plane(player->dir);
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
				load_data(player, map, x, y);
				break ;
			}
			x++;
		}
		y++;
	}
	return (player);
}
