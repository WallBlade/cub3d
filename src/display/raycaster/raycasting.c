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
	ray->dx = sin(angle * PI / 180);
	ray->dy = cos(angle * PI / 180);
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
		if 
	}
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
	while (i < WIDTH)
	{
		angle = (double)FOV - ((double)FOV / 2) + (i * delta);
		distances[i] = castRay(cub, angle);
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
