/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:51:07 by zel-kass          #+#    #+#             */
/*   Updated: 2023/05/02 17:56:31 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		ray->posY_v -= ray->dy;
	}
	else if (ray->angle >= 180 && ray->angle <= 270)
	{
		ray->posX_v -= 1;
		ray->posY_v -= ray->dy;
	}
	else if (ray->angle >= 90 && ray->angle <= 180)
	{
		ray->posX_v -= 1;
		ray->posY_v += ray->dy;
	}
	else if (ray->angle >= 0 && ray->angle <= 90)
	{
		ray->posX_v += 1;
		ray->posY_v += ray->dy;
	}
}

void	get_next_horizontal_point(t_ray *ray)
{
	if (ray->angle >= 270 && ray->angle <= 360)
	{
		ray->posY_h -= 1;
		ray->posX_h += ray->dx;
	}
	else if (ray->angle >= 180 && ray->angle <= 270)
	{
		ray->posY_h -= 1;
		ray->posX_h -= ray->dx;
	}
	else if (ray->angle >= 90 && ray->angle <= 180)
	{
		ray->posY_h += 1;
		ray->posX_h -= ray->dx;
	}
	else if (ray->angle >= 0 && ray->angle <= 90)
	{
		ray->posY_h += 1;
		ray->posX_h += ray->dx;
	}
}