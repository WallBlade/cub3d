/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:51:07 by zel-kass          #+#    #+#             */
/*   Updated: 2023/05/06 17:31:53 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	get_first_horiz(t_cub *cub, t_ray *ray)
{
	double	x_incr;

	if (ray->f_dy > 0)
	{
		x_incr = ray->f_dx * (cub->player->y - floor(cub->player->y));
		ray->posY_h = floor(cub->player->y);
	}
	else
	{
		x_incr = ray->f_dx * (ceil(cub->player->y) - cub->player->y);
		ray->posY_h = ceil(cub->player->y);
	}
	ray->posX_h = cub->player->x + x_incr;
	return (euc_distance(ray->posX_h, ray->posY_h, cub->player->x, cub->player->y));
}

double	get_first_vert(t_cub *cub, t_ray *ray)
{
	double	y_incr;

	if (ray->f_dx > 0)
	{
		y_incr = ray->f_dy * (ceil(cub->player->x) - cub->player->x);
		ray->posX_v = ceil(cub->player->x);
	}
	else
	{
		y_incr = ray->f_dy * (cub->player->x - floor(cub->player->x));
		ray->posX_v = floor(cub->player->x);
	}
	ray->posY_v = cub->player->y + y_incr;
	return (euc_distance(ray->posX_v, ray->posY_v, cub->player->x, cub->player->y));
}

t_ray	*init_ray(t_cub *cub, double angle)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->f_dx = cos(angle * PI / 180);
	ray->f_dy = sin(angle * PI / 180);
	ray->dx = fabs((1 / ray->f_dy) * ray->f_dx);
	ray->dy = fabs((1 / ray->f_dx) * ray->f_dy);
	ray->angle = angle;
	get_first_horiz(cub, ray);
	get_first_vert(cub, ray);
	printf("angle: %f dx: %f dy: %f\n", angle, ray->f_dx, ray->f_dy);
	return (ray);
}

double euc_distance(double x1, double y1, double x2, double y2)
{
    double dx = fabs(x2 - x1);
    double dy = fabs(y2 - y1);
    return sqrt(dx * dx + dy * dy);
}

void	get_next_vertical_point(t_ray *ray)
{
	if (ray->angle >= 270 && ray->angle <= 360)
	{
		ray->posX_v += 1;
		ray->posY_v += ray->dy;
	}
	else if (ray->angle >= 180 && ray->angle <= 270)
	{
		ray->posX_v -= 1;
		ray->posY_v += ray->dy;
	}
	else if (ray->angle >= 90 && ray->angle <= 180)
	{
		ray->posX_v -= 1;
		ray->posY_v -= ray->dy;
	}
	else if (ray->angle >= 0 && ray->angle <= 90)
	{
		ray->posX_v += 1;
		ray->posY_v -= ray->dy;
	}
}

void	get_next_horizontal_point(t_ray *ray)
{
	if (ray->angle >= 270 && ray->angle <= 360)
	{
		ray->posY_h += 1;
		ray->posX_h += ray->dx;
	}
	else if (ray->angle >= 180 && ray->angle <= 270)
	{
		ray->posY_h += 1;
		ray->posX_h -= ray->dx;
	}
	else if (ray->angle >= 90 && ray->angle <= 180)
	{
		ray->posY_h -= 1;
		ray->posX_h -= ray->dx;
	}
	else if (ray->angle >= 0 && ray->angle <= 90)
	{
		ray->posY_h -= 1;
		ray->posX_h += ray->dx;
	}
}
