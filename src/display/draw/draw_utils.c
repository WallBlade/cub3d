/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:38:43 by smessal           #+#    #+#             */
/*   Updated: 2023/05/23 11:40:59 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_color(t_cub *cub, t_draw *wall, int x)
{
	int	color;

	color = *(int *)(cub->imgs[cub->tex[x]].addr + \
	(int)round(((wall->i / wall->ratio))) * cub->imgs[cub->tex[x]].line_len + \
	(int)round((cub->hits[x] * (double)TEXT_W)) * \
	(cub->imgs[cub->tex[x]].bpp / 8));
	return (color);
}
