/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:17:31 by smessal           #+#    #+#             */
/*   Updated: 2023/05/09 18:22:54 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_move(int keysym)
{
	if (keysym == 'w')
		return ('w');
	else if (keysym == 'a')
		return ('a');
	else if (keysym == 's')
		return ('s');
	else if (keysym == 'd')
		return ('d');
	else
		return (0);
}

void	update_player_fw(t_cub *cub, double incr_x, double incr_y)
{
	double	posX;
	double	posY;

	posX = cub->player->x + incr_x * cub->player->dir.x;
	posY = cub->player->y + incr_y * cub->player->dir.y;
	if (cub->map[(int)floor(posY)][(int)floor(posX)] == '1')
		return ;
	else
	{
		cub->player->x += incr_x * cub->player->dir.x;
		cub->player->y += incr_y * cub->player->dir.y;
		cub->player->mapX = (int)floor(cub->player->x);
		cub->player->mapY = (int)floor(cub->player->y);
	}
}

void	update_player_side(t_cub *cub, double incr_x, double incr_y)
{
	double	posX;
	double	posY;

	posX = cub->player->x + incr_x * cub->player->plane.x;
	posY = cub->player->y + incr_y * cub->player->plane.y;
	if (cub->map[(int)floor(posY)][(int)floor(posX)] == '1')
		return ;
	else
	{
		cub->player->x += incr_x * cub->player->plane.x;
		cub->player->y += incr_y * cub->player->plane.y;
		cub->player->mapX = (int)floor(cub->player->x);
		cub->player->mapY = (int)floor(cub->player->y);
	}
}

void	move_player(int keysym, t_cub *cub)
{
	if (keysym == 'w')
		update_player_fw(cub, 0.2, 0.2);
	else if (keysym == 's')
		update_player_fw(cub, -0.2, -0.2);
	else if (keysym == 'a')
		update_player_side(cub, -0.2, -0.2);
	else if (keysym == 'd')
		update_player_side(cub, 0.2, 0.2);
}

void	update_player_rotate(t_cub *cub, int angle)
{
	double	new_x;
	double	new_y;
	double	max_abs;
	
	new_x = cub->player->dir.x * cos(angle * PI / 180) - cub->player->dir.y * sin(angle * PI / 180);
	new_y = cub->player->dir.x * sin(angle * PI / 180) + cub->player->dir.y * cos(angle * PI / 180);
	max_abs = fmax(fabs(new_x), fabs(new_y));
	if (max_abs > 1.0) 
	{
		new_x /= max_abs;
		new_y /= max_abs;
	}
	cub->player->dir.x = new_x;
	cub->player->dir.y = new_y;
	cub->player->plane = determine_plane(cub->player->dir);
}

void	rotate_player(int keysym, t_cub *cub)
{	
	if (keysym == 65363)
	{
		update_player_rotate(cub, 10);
	}
	else if (keysym == 65361)
	{
		update_player_rotate(cub, -10);
	}
}
