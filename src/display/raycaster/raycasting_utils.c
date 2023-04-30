/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:51:07 by zel-kass          #+#    #+#             */
/*   Updated: 2023/04/30 17:19:21 by smessal          ###   ########.fr       */
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
	if (angle <= )
	*x -= 1;
	*y += dy;
}

void	get_next_horizontal_point(double *x, double *y, double dx, double angle)
{
	*y += 1;
	*x -= dx;
}