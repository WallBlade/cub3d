/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:26:09 by smessal           #+#    #+#             */
/*   Updated: 2023/05/23 11:09:44 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_player(int keysym, t_cub *cub)
{	
	if (keysym == 65363)
	{
		update_player_rotate(cub, 5);
	}
	else if (keysym == 65361)
	{
		update_player_rotate(cub, -5);
	}
}

void	move_player(int keysym, t_cub *cub)
{
	if (keysym == 'w')
		update_player_fw(cub, 0.1, 0.1);
	else if (keysym == 's')
		update_player_fw(cub, -0.1, -0.1);
	else if (keysym == 'a')
		update_player_side(cub, -0.1, -0.1);
	else if (keysym == 'd')
		update_player_side(cub, 0.1, 0.1);
}

int	handle_keypress(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
	{
		if (cub->bg->img_ptr)
			mlx_destroy_image(cub->mlx_ptr, cub->bg->img_ptr);
		if (cub->win_ptr)
			mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
		if (cub->mlx_ptr)
			mlx_destroy_display(cub->mlx_ptr);
		free(cub->mlx_ptr);
		free_gc();
		exit(1);
	}
	if (is_move(keysym))
	{
		move_player(keysym, cub);
	}
	rotate_player(keysym, cub);
	return (keysym);
}
