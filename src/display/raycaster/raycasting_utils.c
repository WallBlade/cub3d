/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:51:07 by zel-kass          #+#    #+#             */
/*   Updated: 2023/05/23 10:33:23 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_ray2(t_cub *cub, double cameraX, t_ray *ray)
{
	ray->dir.x = cub->player->dir.x + cub->player->plane.x * cameraX;
	ray->dir.y = cub->player->dir.y + cub->player->plane.y * cameraX;
	ray->pos.x = cub->player->x;
	ray->pos.y = cub->player->y;
	ray->map_x = cub->player->map_x;
	ray->map_y = cub->player->map_y;
	ray->side_x = 0;
	ray->side_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	if (ray->dir.x == 0)
		ray->dx = INFINITY;
	else
		ray->dx = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->dy = INFINITY;
	else
		ray->dy = fabs(1 / ray->dir.y);
}

void	ray_conditions(t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (ray->pos.x - ray->map_x) * ray->dx;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - ray->pos.x) * ray->dx;
	}
	if (ray->dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (ray->pos.y - ray->map_y) * ray->dy;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - ray->pos.y) * ray->dy;
	}
}

t_ray	*init_ray(t_cub *cub, double cameraX)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	init_ray2(cub, cameraX, ray);
	ray_conditions(ray);
	return (ray);
}

int	get_orient(t_ray *ray)
{
	if (ray->dir.y > 0 && ray->side == 1)
		return (SO);
	else if (ray->dir.y < 0 && ray->side == 1)
		return (NO);
	else if (ray->dir.x > 0 && ray->side == 0)
		return (EA);
	else if (ray->dir.x < 0 && ray->side == 0)
		return (WE);
	else
		return (0);
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
