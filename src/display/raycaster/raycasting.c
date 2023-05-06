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

double	castRay_h(t_cub *cub, t_ray *ray)
{
	double	posX;
	double	posY;

	
	while (1)
	{
		posX = floor(ray->posX_h);
		if (ray->angle >= 0 && ray->angle <= 180)
			posY = round(ray->posY_h) - 1;
		else
			posY = round(ray->posY_h);
		if ((int)posY >= 0 && (int)posY < ft_tablen(cub->map) && (int)posX >= 0
			&& (int)posX < ft_strlen(cub->map[(int)posY]))
		{
			if (cub->map[(int)posY][(int)posX] == '1')
			{
				printf("pos_h: (%d, %d)\n", (int)posY, (int)posX);
				return (euc_distance(ray->posX_h, ray->posY_h, cub->player->x, cub->player->y));
			}
		}
		else
			return (-1);
		get_next_horizontal_point(ray);
	}
}

double	castRay_v(t_cub *cub, t_ray *ray)
{
	double	posX;
	double	posY;

	while (1)
	{
		posY = floor(ray->posY_v);
		if (ray->angle > 90 && ray->angle <= 270)
			posX = round(ray->posX_v) - 1;
		else
			posX = round(ray->posX_v);
		if ((int)posY >= 0 && (int)posY < ft_tablen(cub->map) && (int)posX >= 0
			&& (int)posX < ft_strlen(cub->map[(int)posY]))
		{
			if (cub->map[(int)posY][(int)posX] == '1')
			{
				printf("pos_v: (%d, %d)\n", (int)posY, (int)posX);
				return (euc_distance(ray->posX_v, ray->posY_v, cub->player->x, cub->player->y));
			}
		}
		else
			return (-1);
		get_next_vertical_point(ray);
	}
}

double	castRay(t_cub *cub, double angle)
{
	t_ray	*ray;
	double	h_dist;
	double	v_dist;

	ray = init_ray(cub, angle);
	if (!ray)
		return (0);
	printf("player pos (%f, %f)\tfirst intersect horiz: (%f, %f)\n", cub->player->x, cub->player->y, ray->posX_h, ray->posY_h);
	printf("player pos (%f, %f)\tfirst intersect vert: (%f, %f)\n", cub->player->x, cub->player->y, ray->posX_v, ray->posY_v);
	h_dist = castRay_h(cub, ray);
	v_dist = castRay_v(cub, ray);
	if (v_dist >= 0 && h_dist >= 0)
	{
		if (v_dist >= h_dist)
			return (printf("h_dist\n"), h_dist);
		else
			return (printf("v_dist\n"), v_dist);
	}
	if (v_dist < 0 && h_dist >= 0)
		return (printf("h_dist\n"), h_dist);
	if (h_dist < 0 && v_dist >= 0)
		return (printf("v_dist\n"), v_dist);
	return (100);
}

double	*distances(t_cub *cub)
{
	int		i;
	// double	diff;
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
		// diff = cos((angle - cub->player->angle) * PI / 180);
		// if (diff < 0)
		// 	diff += 360;
		distances[i] = castRay(cub, angle);
		printf("i: %d distance: %f\n", i ,distances[i]);
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
		heights[i] = ((double)WALL_H * cub->distances[i]) / 360;
		i++;
	}
	return (heights);
}
