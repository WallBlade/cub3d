/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:43:56 by zel-kass          #+#    #+#             */
/*   Updated: 2023/05/11 16:26:16 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_cub	*init_cub(char *arg)
{
	int		fd;
	t_cub	*cub;
	int		count;

	cub = collect(sizeof(t_cub));
	if (!cub)
		return (NULL);
	count = count_lines(arg);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (NULL);
	get_data(fd, count, cub);
	cub->mlx_ptr = NULL;
	cub->win_ptr = NULL;
	cub->bg = collect(sizeof(t_cub));
	cub->imgs = NULL;
	cub->player = player_data(cub->map);
	cub->plane_dist = ((double)WIDTH / 2) / tan((double)FOV / 2);
	cub->distances = collect(sizeof(double) * WIDTH);
	cub->heights = collect(sizeof(double) * WIDTH);
	cub->hits = collect(sizeof(double) * WIDTH);
	cub->tex = collect(sizeof(double) * WIDTH);
	return (cub);
}

void	init_assets(t_cub *cub)
{
	int		check;
	t_mlx	*assets;

	check = 0;
	assets = collect(sizeof(t_mlx) * 4);
	if (!assets)
		return ;
	if (download_image(cub, &assets[NO], cub->assets[NO]))
		check += 1;
	if (download_image(cub, &assets[SO], cub->assets[SO]))
		check += 1;
	if (download_image(cub, &assets[WE], cub->assets[WE]))
		check += 1;
	if (download_image(cub, &assets[EA], cub->assets[EA]))
		check += 1;
	if (check != 4)
		print_error("ERROR\nFailed loading textures", NULL);
	cub->imgs = assets;
}

void	init_mlx(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		return ;
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, WIDTH, HEIGHT, "CUB");
	if (!cub->win_ptr)
		return (free(cub->win_ptr));
	cub->bg->img_ptr = mlx_new_image(cub->mlx_ptr, WIDTH, HEIGHT);
	cub->bg->addr= mlx_get_data_addr(cub->bg->img_ptr, &cub->bg->bpp, \
						&cub->bg->line_len, &cub->bg->endian);
	init_assets(cub);
	mlx_hook(cub->win_ptr, KeyPress, KeyPressMask, &handle_keypress, cub);
	mlx_loop_hook(cub->mlx_ptr, &render, cub);
	mlx_loop(cub->mlx_ptr);
	if (cub->bg->img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->bg->img_ptr);
	if (cub->win_ptr)
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	if (cub->mlx_ptr)
		mlx_destroy_display(cub->mlx_ptr);
	
}
