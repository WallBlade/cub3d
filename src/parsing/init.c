/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:43:56 by zel-kass          #+#    #+#             */
/*   Updated: 2023/04/17 15:49:26 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_cub	*init_cub(char *arg)
{
	int		fd;
	t_cub	*cub;
	int		count;
	char	**file;

	cub = collect(sizeof(t_cub));
	if (!cub)
		return (NULL);
	count = count_lines(arg);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = get_file(fd, count);
	cub->map = get_map(file);
	cub->paths = get_paths(file);
	cub->floor = get_colors(file, 1);
	cub->ceiling = get_colors(file, 2);
	return (cub);
}
