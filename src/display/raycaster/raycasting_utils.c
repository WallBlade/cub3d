/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:51:07 by zel-kass          #+#    #+#             */
/*   Updated: 2023/04/30 18:20:05 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double euc_distance(double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

void	get_next_vertical_point(double *x, double *y, double dy, double angle)
{
	if (angle >= 270 && angle <= 360)
	{
		*x += 1;
		*y += dy;
	}
	else if (angle >= 180 && angle <= 270)
	{
		*x -= 1;
		*y -= dy;
	}
	else if (angle >= 90 && angle <= 180)
	{
		*x -= 1;
		*y += dy;
	}
	else if (angle >= 0 && angle <= 90)
	{
		*x += 1;
		*y += dy;
	}
}

void	get_next_horizontal_point(double *x, double *y, double dx, double angle)
{
	if (angle >= 270 && angle <= 360)
	{
		*y -= 1;
		*x += dx;
	}
	else if (angle >= 180 && angle <= 270)
	{
		*y -= 1;
		*x -= dx;
	}
	else if (angle >= 90 && angle <= 180)
	{
		*y += 1;
		*x -= dx;
	}
	else if (angle >= 0 && angle <= 90)
	{
		*y += 1;
		*x += dx;
	}
}