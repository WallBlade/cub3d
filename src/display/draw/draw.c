/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:18:45 by smessal           #+#    #+#             */
/*   Updated: 2023/05/23 11:19:39 by smessal          ###   ########.fr       */
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
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
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
	cub->distances = cast_ray(cub);
	cub->heights = get_heights(cub);
	render_walls(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, \
		cub->bg->img_ptr, 0, 0);
	return (0);
}

void	init_wall(t_cub *cub, t_draw wall, int x)
{
	wall.height = (double)HEIGHT / cub->heights[x];
	wall.top = (HEIGHT - wall.height) / 2;
	wall.bottom =  wall.top + wall.height;
	wall.ratio = wall.height / (double)TEXT_H;
	wall.i = 0;
	while (wall.top < 0)
	{
		wall.i++;
		wall.top++;
	}
}

void render_walls(t_cub *cub)
{
    int x;
    int y;
    int color;
	t_draw	wall;

	x = 0;
	while (x < WIDTH)
    {
		init_wall(cub, wall, x);
		y = 0;
        while (y < HEIGHT)
        {
            if (y >= (int)wall.top && y < (int)wall.bottom) // Wall
			{
				color = *(int *)(cub->imgs[cub->tex[x]].addr + (int)round(((wall.i / wall.ratio))) *  cub->imgs[cub->tex[x]].line_len + \
					(int)round((cub->hits[x] * (double)TEXT_W)) * (cub->imgs[cub->tex[x]].bpp / 8));
				wall.i++;
            	my_mlx_pixel_put(cub->bg, x, y, color);
			}
			y++;
		}
		x++;
    }
}
