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
			line[ft_strlen(line) - 1] = '\0';
			file[i++] = ft_strdup(line);
		}
	}
	file[i] = NULL;
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
		map[j++] = file[i];
	map[j] = NULL;
	return (map);
}

char	**get_paths(char **file)
{
	int		i;
	char	**paths;

	i = 0;
	paths = collect(sizeof(char *) * 5);
	if (!paths)
		return (NULL);
	while (file[i])
	{
		if (is_data(file[i]) == 1)
			paths[NO] = clean_data(file[i]);
		else if (is_data(file[i]) == 2)
			paths[SO] = clean_data(file[i]);
		else if (is_data(file[i]) == 3)
			paths[WE] = clean_data(file[i]);
		else if (is_data(file[i]) == 4)
			paths[EA] = clean_data(file[i]);
		i++;
	}
	paths[4] = NULL;
	return (paths);
}

int	*get_colors(char **file, int type)
{
	int		i;
	int		*tab;

	i = 0;
	while (file[i])
	{
		if (is_data(file[i]) == 5 && type == 1)
			tab = convert_colors(clean_data(file[i]));
		if (is_data(file[i]) == 6 && type == 2)
			tab = convert_colors(clean_data(file[i]));
		i++;
	}
	return (tab);
}
