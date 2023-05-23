/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:59:07 by smessal           #+#    #+#             */
/*   Updated: 2023/05/23 11:51:17 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_display(t_cub *cub)
{
	if (cub->imgs[0].img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->imgs[0].img_ptr);
	if (cub->imgs[1].img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->imgs[1].img_ptr);
	if (cub->imgs[2].img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->imgs[2].img_ptr);
	if (cub->imgs[3].img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->imgs[3].img_ptr);
	if (cub->bg->img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->bg->img_ptr);
	if (cub->win_ptr)
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	if (cub->mlx_ptr)
		mlx_destroy_display(cub->mlx_ptr);
	free(cub->mlx_ptr);
	free_gc();
	exit(1);
}

void	free_tab(int**tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}
