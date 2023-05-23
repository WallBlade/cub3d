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
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->dx;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->dy;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (cub->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

double	distance(t_ray *ray)
{
	double	distance;

	if (ray->side == 0)
		distance = ray->side_x - ray->dx;
	else
		distance = ray->side_y - ray->dy;
	return (distance);
}

double	hit_point(t_ray *ray, double distance)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = ray->pos.y + distance * ray->dir.y;
	else
		wall_x = ray->pos.x + distance * ray->dir.x;
	wall_x -= floor((wall_x));
	return (wall_x);
}

double	*cast_ray(t_cub *cub)
{
	int		i;
	double	camera_x;
	t_ray	*ray;

	i = 0;
	while (i < WIDTH)
	{
		camera_x = 2 * i / (double)WIDTH - 1;
		ray = init_ray(cub, camera_x);
		algo_dda(cub, ray);
		cub->distances[i] = distance(ray);
		cub->hits[i] = hit_point(ray, cub->distances[i]);
		cub->tex[i] = get_orient(ray);
		free(ray);
		i++;
	}
	return (cub->distances);
}
