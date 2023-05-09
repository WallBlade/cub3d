/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:14:46 by zel-kass          #+#    #+#             */
/*   Updated: 2023/04/03 17:14:46 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		return (-1);
	check_filename(argv[1]);
	cub = init_cub(argv[1]);
	map_closed(cub->map);
	map_elem(cub->map);
	cub->distances = cast_ray(cub);
	cub->heights = get_heights(cub);
	init_mlx(cub);
	free_gc();
	return (0);
}