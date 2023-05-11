/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:26:49 by smessal           #+#    #+#             */
/*   Updated: 2023/05/11 15:11:42 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	download_image(t_cub *cub, t_mlx asset, char *path)
{	
	asset.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, path,
			&asset.width, &asset.height);
	asset.height = 0;
	asset.width = 0;
	if (!asset.img_ptr)
		return (0);
	asset.addr = mlx_get_data_addr(asset.img_ptr, &asset.bpp,
			&asset.line_len, &asset.endian);
	return (1);
}
