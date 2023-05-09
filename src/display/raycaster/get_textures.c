/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:26:49 by smessal           #+#    #+#             */
/*   Updated: 2023/05/09 20:51:51 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	download_image(t_cub *cub, char *path)
{	
	cub->imgs->img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, path,
			&cub->imgs->width, &cub->imgs->height);
	cub->imgs->height = 0;
	cub->imgs->width = 0;
	if (!cub->imgs->img_ptr)
		return (0);
	cub->imgs->addr = mlx_get_data_addr(cub->imgs->img_ptr, &cub->imgs->bpp,
			&cub->imgs->line_len, &cub->imgs->endian);
	return (1);
}
