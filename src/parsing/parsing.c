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
	file = collect(sizeof(char *) * count + 1);
	if (!file)
		return (close(fd), NULL);
	while (i < count)
	{
		line = NULL;
		line = get_next_line(fd);
		if (line && line[0] != '\0' && line[0] != '\n')
		{
			line[ft_strlen(line) - 1] = '\0';
			file[i++] = ft_strdup(line);
		}
		free(line);
	}
	return (close(fd), file);
}

char	**get_paths(char **file)
{
	int		i;
	int		j;
	char	**paths;

	i = 0;
	j = 0;
	paths = collect(sizeof(char *) * 7);
	if (!paths)
		return (NULL);
	while (i < 6)
	{
		if (is_data(file[i]) == PATH)
			paths[j++] = ft_strdup(file[i++]);
	}
	paths[j] = NULL;
	return (paths);
}

char	**get_colors(char **file)
{
	int		i;
	int		j;
	char	**colors;

	i = 0;
	j = 0;
	colors = collect(sizeof(char *) * 3);
	if (!colors)
		return (NULL);
	while (i < 6)
	{
		if (is_data(file[i]) == COLOR)
			colors[j++] = ft_strdup(file[i++]);
	}
	colors[j] = NULL;
	return (colors);
}


// char	**get_map(int fd)
// {
// 	char	**map;

// 	map = collect(sizeof)
// }