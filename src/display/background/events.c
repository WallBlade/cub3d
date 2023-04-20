/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:26:09 by smessal           #+#    #+#             */
/*   Updated: 2023/04/20 13:10:42 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	handle_keypress(int keysym, t_cub *cub)
{
	if (keysym)
		printf("test\n");
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
	return (keysym);
}
