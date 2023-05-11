/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:18:45 by smessal           #+#    #+#             */
/*   Updated: 2023/05/11 15:53:52 by smessal          ###   ########.fr       */
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
			if (y < 720 / 2)
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

void render_walls(t_cub *cub)
{
    int x;
    int y;
    int color;
    double wall_height;
    double wall_top;
    double wall_bottom;
	double	i;
	double	ratio;

    // Loop through each column of the screen
    i = 0;
	for (x = 0; x < WIDTH; x++)
    {
        // Calculate the height of the wall
        wall_height = (double)HEIGHT / cub->heights[x];
        wall_top = (HEIGHT - wall_height) / 2;
        wall_bottom = wall_top + wall_height;
		ratio = wall_height / (double)TEXT_H;
        // Draw the wall
		i = 0;
		while (wall_top < 0)
		{
			i++;
			wall_top++;
		}
        for (y = 0; y < HEIGHT; y++)
        {
            if (y >= (int)wall_top && y < (int)wall_bottom) // Wall
			{
                /*      CHANGE COLOR BY CORRESPONDING PIXEL IN TEXTURE  */
				color = *(int *)(cub->imgs->addr + (int)round(((i / ratio))) *  cub->imgs->line_len + \
					(int)round((cub->hits[x] * (double)TEXT_W)) * (cub->imgs->bpp / 8));
				i++;
            	my_mlx_pixel_put(cub->bg, x, y, color);
			}
		}
    }
}
