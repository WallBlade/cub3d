/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:39:53 by zel-kass          #+#    #+#             */
/*   Updated: 2023/03/26 22:39:53 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	algo_dda(t_cub *cub, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if (ray->sideX < ray->sideY)
        {
          ray->sideX += ray->dx;
          ray->mapX += ray->stepX;
          ray->side = 0;
        }
        else
        {
          ray->sideY += ray->dy;
          ray->mapY += ray->stepY;
          ray->side = 1;
        }
        //Check if ray has hit a wall
		if (cub->map[ray->mapY][ray->mapX] == '1')
			hit = 1;
      } 
}

double	distance(t_ray *ray)
{
	double	distance;

	if (ray->side == 0)
		distance = ray->sideX - ray->dx;
	else
		distance = ray->sideY - ray->dy;
	return (distance);
}

double	*cast_ray(t_cub *cub)
{
	int	i;
	double	cameraX;
	double	*distances;
	t_ray	*ray;

	i = 0;
	distances = malloc(sizeof(double) * WIDTH);
	if (!distances)
		return (NULL);
	while (i < WIDTH)
	{
		cameraX = 2 * i / (double)WIDTH - 1;
		ray = init_ray(cub, cameraX);
		algo_dda(cub, ray);
		distances[i] = distance(ray);
		free(ray);
		i++;
	}
	return (distances);
}

double	*get_heights(t_cub *cub)
{
	double	*heights;
	int		i;
	// int		j;

	i = 0;
	// j = WIDTH - 1;
	heights = malloc(sizeof(double) * WIDTH);
	if (!heights)
		return (NULL);
	while (i < WIDTH)
	{
		heights[i] = ((double)WALL_H * cub->distances[i]) / 720;
		i++;
		// j--;
	}
	return (heights);
}
