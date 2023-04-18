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

float distance(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

float	castRay(t_cub *cub, float angle)
{
    float	dx;
    float	dy;
    float	posX;
    float	posY;
    int i;

	posX = cub->player->x;
	posY = cub->player->y;
	dx = cos(angle * PI / 180);
	dy = sin(angle * PI / 180);
	i = 0;
	while (i < 100)
    {
        if (cub->map[(int)posX][(int)posY] == '1')
        {
            return(distance(cub->player->x, cub->player->y, \
				posX, posY) * cos((angle - cub->player->angle) * PI / 180));
        }
        posX += dx;
        posY += dy;
        i++;
    }
	return (10000);
}


double	*angle(t_cub *cub)
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
		distances[i] = castRay(cub->player, angle);
		i++;
	}
	return (distances);
}