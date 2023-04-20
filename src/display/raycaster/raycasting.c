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

double euc_distance(double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

double	castRay(t_cub *cub, double angle)
{
    double	dx;
    double	dy;
    double	posX;
    double	posY;
    int i;

	posX = (double)(cub->player->x);
	posY = (double)cub->player->y;
	dx = sin(angle * PI / 180);
	dy = cos(angle * PI / 180);
	i = 0;
	while (i < 100)
    {
		if (cub->map[(int)posY][(int)posX] == '1')
        {
            return(euc_distance((double)cub->player->x, (double)cub->player->y, \
				posX, posY) * cos((angle - cub->player->angle) * PI / 180));
        }
        posX += dx;
        posY += dy;
        i++;
    }
	return (10000);
}

double	*distances(t_cub *cub)
{
	int		i;
	double	angle;
	double	delta;
	double	*distances;

	i = 0;
	delta = FOV / WIDTH;
	distances = collect(sizeof(double) * WIDTH);
	if (!distances)
		return (0);
	while (i < WIDTH)
	{
		angle = FOV - (FOV / 2) + (i * delta);
		distances[i] = castRay(cub, angle);
		i++;
	}
	return (distances);
}
