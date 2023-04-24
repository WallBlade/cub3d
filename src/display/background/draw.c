/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:18:45 by smessal           #+#    #+#             */
/*   Updated: 2023/04/24 15:29:12 by smessal          ###   ########.fr       */
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
	// draw_background(cub);
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
    int wall_top;
    int wall_bottom;

    // Loop through each column of the screen
    for (x = 0; x < WIDTH; x++)
    {
        // Calculate the height of the wall
        wall_height = (double)HEIGHT / cub->heights[x];
        wall_top = (HEIGHT - WALL_H) / 2;
        wall_bottom = wall_top + wall_height;

        // Draw the wall
        for (y = 0; y < HEIGHT; y++)
        {
            if (y < wall_top) // Ceiling
                color = cub->ceiling;
            else if (y >= wall_top && y < wall_bottom) // Wall
                color = GREEN << 8;
            else // Floor
                color = cub->floor;

            my_mlx_pixel_put(cub->mlx_ptr, x, y, color);
        }
    }
}

// int get_wall_texture_color(t_cub *cub, int x, int y, double wall_height, double distance)
// {
//     int texture_x;
//     int texture_y;
//     double texture_distance;
//     int color;

//     // Calculate the distance from the top of the wall to the current pixel
//     texture_distance = (y - (cub->screen_height - wall_height) / 2.0) / wall_height;

//     // Calculate the coordinates of the corresponding point on the wall texture
//     texture_x = (int)(texture_distance * TEXTURE_WIDTH);
//     texture_y = (int)(distance * TEXTURE_HEIGHT) % TEXTURE_HEIGHT;

//     // Get the color of the corresponding pixel in the wall texture
//     color = cub->textures[TEXTURE_INDEX_WALL][texture_y][texture_x];

//     return color;
// }

