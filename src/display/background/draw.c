/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:18:45 by smessal           #+#    #+#             */
/*   Updated: 2023/04/18 18:12:54 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_mlx *bg, int x, int y, int color)
{
	char	*dst;

	dst = bg->addr + (y * bg->line_len + x * (bg->bpp / 8));
	*(unsigned int *)dst = color;
}


void	draw_background(t_cub *cub)
{
	int		x;
	int		y;

	y = 0;
	while (y < 720)
	{
		x = 0;
		while (x < 1080)
		{
			if (y > 720 / 2)
				my_mlx_pixel_put(cub->bg, x, y, cub->ceiling);
			else
				my_mlx_pixel_put(cub->bg, x, y, cub->floor);
			x++;
		}
		y++;
	}
	return ;
}

int	render(t_cub *cub)
{
	draw_background(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, \
		cub->bg->img_ptr, 0, 0);
	return (0);
}
