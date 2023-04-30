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

t_ray	*init_ray(t_cub *cub, double angle)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->posX_h = cub->player->x;
	ray->posY_h = cub->player->y;
	ray->posX_v = cub->player->x;
	ray->posY_v = cub->player->y;
	ray->dy = (1 / sin(angle * PI / 180)) * sin(angle * PI / 180);
	ray->dx = (1 / sin(angle * PI / 180)) * cos(angle * PI / 180);
	return (ray);
}

double	castRay(t_cub *cub, double angle)
{
	t_ray	*ray;

	ray = init_ray(cub, angle);
	if (!ray)
		return (0);
	while (1)
	{
		get_next_horizontal_point(&ray->posX_h, &ray->posY_h, ray->dx);
		get_next_vertical_point(&ray->posX_v, &ray->posY_v, ray->dy);
		if (cub->map[(int)ray->posY_h][(int)ray->posX_h] == '1')
			return (free(ray), euc_distance(ray->posX_h, ray->posY_h, cub->player->x, cub->player->y));
		else if (cub->map[(int)ray->posY_v][(int)ray->posX_v] == '1')
			return (free(ray), euc_distance(ray->posX_h, ray->posY_h, cub->player->x, cub->player->y));
	}
	return (0);
}

double	*distances(t_cub *cub)
{
	int		i;
	double	angle;
	double	delta;
	double	*distances;

	i = 0;
	delta = (double)FOV / (double)WIDTH;
	distances = malloc(sizeof(double) * WIDTH);
	if (!distances)
		return (0);
	angle = cub->player->angle + (double)FOV / 2;
	while (i < WIDTH)
	{
		if (angle < 0)
			angle += 360;
		else if (angle > 360)
			angle -= 360;
		// printf("angle: %f\n", angle);
		distances[i] = castRay(cub, angle);
		angle -= delta;
		i++;
	}
	return (distances);
}

double	*get_heights(t_cub *cub)
{
	double	*heights;
	int		i;

	i = 0;
	heights = collect(sizeof(double) * WIDTH);
	if (!heights)
		return (NULL);
	while (i < WIDTH)
	{
		heights[i] = ((double)WALL_H * cub->distances[i]) / cub->plane_dist;
		i++;
	}
	return (heights);
}
