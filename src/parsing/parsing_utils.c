/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:53:59 by zel-kass          #+#    #+#             */
/*   Updated: 2023/05/23 10:07:06 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_assets(char **assets)
{
	int		i;
	int		len;
	char	*valid;

	i = 0;
	if (!assets[0] || !assets[1] || !assets[2] || !assets[3])
		print_error("ERROR\nFailed loading textures", NULL);
	while (assets[i])
	{
		len = ft_strlen(assets[i]) - 4;
		valid = ".xpm";
		if (ft_strncmp(&assets[i][len], valid, 4) != 0)
			print_error("ERROR\nCorrupted texture name : ", assets[i]);
		i++;
	}
}

int	check_filename(char *name)
{
	int		len;
	char	*valid;

	len = ft_strlen(name) - 4;
	valid = ".cub";
	if (ft_strncmp(&name[len], valid, 4) != 0)
		print_error("Error\n", NULL);
	return (0);
}

int	is_data(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && (line[i] == ' ' && line[i] == '\t'))
		i++;
	if (ft_strncmp(&line[i], "NO", 2) == 0)
		return (1);
	else if (ft_strncmp(&line[i], "SO", 2) == 0)
		return (2);
	else if (ft_strncmp(&line[i], "WE", 2) == 0)
		return (3);
	else if (ft_strncmp(&line[i], "EA", 2) == 0)
		return (4);
	else if (ft_strncmp(&line[i], "F", 1) == 0)
		return (5);
	else if (ft_strncmp(&line[i], "C", 1) == 0)
		return (6);
	return (FALSE);
}

char	*clean_data(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		while (data[i] == ' ' || data[i] == '\t')
			i++;
		if (is_data(data + i) < 5 && is_data(data + i) > 0)
		{
			i += 3;
			while (data[i] == ' ' || data[i] == '\t')
				i++;
			break ;
		}
		else if (is_data(data + i) > 4)
		{
			i += 2;
			while (data[i] == ' ' || data[i] == '\t')
				i++;
			break ;
		}
	}
	return (data + i);
}

int	convert_colors(char *color)
{
	int		tab[3];
	int		ret;
	char	**tmp;

	tmp = ft_split(color, ',');
	if (!tmp[0] || !tmp[1] || !tmp[2])
		return (-1);
	tab[0] = ft_atoi(tmp[0]);
	tab[1] = ft_atoi(tmp[1]);
	tab[2] = ft_atoi(tmp[2]);
	if (tab[0] > 255 || tab[0] < 0)
		return (-1);
	if (tab[1] > 255 || tab[1] < 0)
		return (-1);
	if (tab[2] > 255 || tab[2] < 0)
		return (-1);
	ret = (tab[0] << 16) + (tab[1] << 8) + (tab[2] << 0);
	return (ret);
}
