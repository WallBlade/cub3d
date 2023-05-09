/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:51:07 by zel-kass          #+#    #+#             */
/*   Updated: 2023/05/09 18:09:23 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_ray2(t_cub *cub, double cameraX, t_ray *ray)
{
	ray->dir.x = cub->player->dir.x + cub->player->plane.x * cameraX;
	ray->dir.y = cub->player->dir.y + cub->player->plane.y * cameraX;
	ray->pos.x = cub->player->x;
	ray->pos.y = cub->player->y;
	ray->mapX = cub->player->mapX;
	ray->mapY = cub->player->mapY;
	ray->sideX = 0;
	ray->sideY = 0;
	ray->stepX = 0;
	ray->stepY = 0;
	if (ray->dir.x == 0)
		ray->dx = INFINITY;
	else
		ray->dx = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->dy = INFINITY;
	else
		ray->dy = fabs(1 / ray->dir.y);
}

t_ray	*init_ray(t_cub *cub, double cameraX)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	init_ray2(cub, cameraX, ray);
	if (ray->dir.x < 0)
	{
		ray->stepX = -1;
		ray->sideX = (ray->pos.x - ray->mapX) * ray->dx;
	}
	else
	{
		ray->stepX = 1;
		ray->sideX = (ray->mapX + 1.0 - ray->pos.x) * ray->dx;
	}
	if (ray->dir.y < 0)
	{
		ray->stepY = -1;
		ray->sideY = (ray->pos.y - ray->mapY) * ray->dy;
	}
	else
	{
		ray->stepY = 1;
		ray->sideY = (ray->mapY + 1.0 - ray->pos.y) * ray->dy;
	}
	return (ray);
}