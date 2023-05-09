/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:39:57 by zel-kass          #+#    #+#             */
/*   Updated: 2023/03/26 22:39:57 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**get_file(int fd, int count)
{
	int		i;
	char	*line;
	char	**file;

	i = 0;
	file = collect(sizeof(char *) * (count + 1));
	if (!file)
		return (close(fd), NULL);
	while (i < count)
	{
		line = NULL;
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (line[0] != '\0' && line[0] != '\n')
		{
			if (line[ft_strlen(line) - 1] == '\n')
				line[ft_strlen(line) - 1] = '\0';
			file[i++] = ft_strdup(line);
		}
	}
	file[i] = NULL;
	if (file[0] == NULL)
		print_error("ERROR\nEmpty file", NULL);
	return (close(fd), file);
}

char	**get_map(char **file)
{
	int		i;
	int		j;
	int		len;
	char	**map;

	i = 5;
	j = 0;
	len = ft_tablen(file);
	map = collect(sizeof(char *) * (len - i));
	if (!map)
		return (NULL);
	while (++i < len)
	{
		
		map[j++] = ft_strdup(file[i]);
	}
	map[j] = NULL;
	return (map);
}

char	**get_assets(char **file)
{
	int		i;
	char	**assets;

	i = 0;
	assets = collect(sizeof(char *) * 5);
	if (!assets)
		return (NULL);
	while (i < 6)
	{
		if (is_data(file[i]) == 1)
			assets[NO] = clean_data(file[i]);
		else if (is_data(file[i]) == 2)
			assets[SO] = clean_data(file[i]);
		else if (is_data(file[i]) == 3)
			assets[WE] = clean_data(file[i]);
		else if (is_data(file[i]) == 4)
			assets[EA] = clean_data(file[i]);
		i++;
	}
	assets[4] = NULL;
	check_assets(assets);
	return (assets);
}

int	get_colors(char **file, int type)
{
	int		i;
	int		tab;

	i = 0;
	tab = 0;
	while (i < 6)
	{
		if (is_data(file[i]) == 5 && type == 1)
			tab = convert_colors(clean_data(file[i]));
		if (is_data(file[i]) == 6 && type == 2)
			tab = convert_colors(clean_data(file[i]));
		i++;
	}
	if (tab == -1)
		print_error("ERROR\nCorrupted color", NULL);
	return (tab);
}

void	get_data(int fd, int count, t_cub *cub)
{
	char	**file;

	file = get_file(fd, count);
	cub->assets = get_assets(file);
	cub->floor = get_colors(file, 1);
	cub->ceiling = get_colors(file, 2);
	cub->map = get_map(file);
	close(fd);
}