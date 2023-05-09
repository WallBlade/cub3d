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

double	hit_point(t_ray *ray, double distance)
{
	double	wallX;
	
	if (ray->side == 0) 
		wallX = ray->pos.y + distance * ray->dir.y;
	else
		wallX = ray->pos.x + distance * ray->dir.x;
    wallX -= floor((wallX));
	return (wallX);
}

double	*cast_ray(t_cub *cub)
{
	int	i;
	double	cameraX;
	t_ray	*ray;

	i = 0;
	while (i < WIDTH)
	{
		cameraX = 2 * i / (double)WIDTH - 1;
		ray = init_ray(cub, cameraX);
		algo_dda(cub, ray);
		cub->distances[i] = distance(ray);
		cub->hits[i] = hit_point(ray, cub->distances[i]);
		free(ray);
		i++;
	}
	return (cub->distances);
}

double	*get_heights(t_cub *cub)
{
	int		i;

	i = 0;
	while (i < WIDTH)
	{
		cub->heights[i] = ((double)WALL_H * cub->distances[i]) / (double)HEIGHT;
		i++;
	}
	return (cub->heights);
}
