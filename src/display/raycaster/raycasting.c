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
	ray->posX_h = (double)cub->player->x;
	ray->posY_h = (double)cub->player->y;
	ray->posX_v = (double)cub->player->x;
	ray->posY_v = (double)cub->player->y;
	ray->dx = fabs((1 / sin(angle * PI / 180)) * cos(angle * PI / 180));
	ray->dy = fabs((1 / cos(angle * PI / 180)) * sin(angle * PI / 180));
	ray->angle = angle;
	return (ray);
}

double	castRay_h(t_cub *cub, t_ray *ray)
{
	double	posX;
	double	posY;

	
	while (1)
	{
		get_next_horizontal_point(ray);
		if (ray->angle > 180 && ray->angle < 360)
			posY = floor(ray->posY_h);
		else
			posY = floor(ray->posY_h);
		posX = floor(ray->posX_h);
		if ((int)posY >= 0 && (int)posY < ft_tablen(cub->map) && (int)posX >= 0 && (int)posX < ft_strlen(cub->map[(int)posY]))
		{
			if (cub->map[(int)posY][(int)posX] == '1')
				return (euc_distance(ray->posX_h, ray->posY_h, cub->player->x, cub->player->y));
		}
		else
			return (-1);
	}
}

double	castRay_v(t_cub *cub, t_ray *ray)
{
	double	posX;
	double	posY;

	while (1)
	{
		get_next_vertical_point(ray);
		posY = floor(ray->posY_v);
		if (ray->angle > 90 && ray->angle < 270)
			posX = floor(ray->posX_v);
		else
			posX = floor(ray->posX_v);
		if ((int)posY >= 0 && (int)posY < ft_tablen(cub->map) && (int)posX >= 0 && (int)posX < ft_strlen(cub->map[(int)posY]))
		{
			if (cub->map[(int)posY][(int)posX] == '1')
				return (euc_distance(ray->posX_v, ray->posY_v, cub->player->x, cub->player->y));
		}
		else
			return (-1);
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
	h_dist = castRay_h(cub, ray);
	v_dist = castRay_v(cub, ray);
	if (v_dist >= 0 && h_dist >= 0)
	{
		if (v_dist > h_dist)
			return (printf("horiz\n"), h_dist);
		else
			return (printf("vert\n"), v_dist);
	}
	if (v_dist < 0 && h_dist >= 0)
		return (printf("horiz\n"), h_dist);
	if (h_dist < 0 && v_dist >= 0)
		return (printf("vert\n"), v_dist);
	return (100);
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
		// printf("fish_eye: %f\n", cos((cub->player->angle - angle) * PI / 180));
		distances[i] = castRay(cub, angle) * cos((cub->player->angle - angle) * PI / 180);
		angle -= delta;
		i++;
	}
	return (distances);
}

double	*get_heights(t_cub *cub)
{
	double	*heights;
	int		i;
	int		j;

	i = WIDTH - 1;
	j = 0;
	heights = collect(sizeof(double) * WIDTH);
	if (!heights)
		return (NULL);
	while (i >= 0)
	{
		heights[j] = ((double)WALL_H * cub->distances[i]) / (double)HEIGHT;
		i--;
		j++;
	}
	return (heights);
}

// if ((int)floor(ray->posY_h) < 0 || (int)floor(ray->posY_h) >= ft_tablen(cub->map) || (int)floor(ray->posX_h) < 0 || (int)floor(ray->posX_h) >= ft_strlen(cub->map[0]))
// {
// 	printf("outY_float: %f outY_dec: %d\toutX_float: %f outY_dec:%d\n", ray->posY_h, (int)floor(ray->posY_h), ray->posX_h,(int)floor(ray->posX_h) );
// 	return (-1);
// }
// if ((int)floor(ray->posY_v) < 0 || (int)floor(ray->posY_v) >= ft_tablen(cub->map) || (int)floor(ray->posX_v) < 0 || (int)floor(ray->posX_v) >= ft_strlen(cub->map[0]))
// {
// 	printf("outY_float: %f outY_dec: %d\toutX_float: %f outY_dec:%d\n", ray->posY_v, (int)floor(ray->posY_v), ray->posX_v,(int)floor(ray->posX_v) );
// 	return (-1);
// }