/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_map_closed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:23:55 by smessal           #+#    #+#             */
/*   Updated: 2023/04/17 15:41:55 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	skip_white(char **map, int *i, int *j, int type)
{
	if (type)
	{
		while (map && map[*i] && map[*i][*j] && (map[*i][*j] == ' '))
				*j += 1;
	}
	else
	{
		while (map && map[*i])
		{
			if (*j > ft_strlen(map[*i]) - 1)
				*i += 1;
			else if (map[*i][*j] && (map[*i][*j] == ' '))
				*i += 1;
			else
				break ;
		}
	}
}

void	skip_chars(char **map, int *i, int *j, int type)
{
	if (type)
	{
		while (map && map[*i] && map[*i][*j] && map[*i][*j] != ' ')
				*j += 1;
	}
	else
	{
		while (map && map[*i])
		{
			if (*j > ft_strlen(map[*i]) - 1)
				return ;
			else if (map[*i][*j] && (map[*i][*j] != ' '))
				*i += 1;
			else
				break ;
		}
	}
}

int	row_closed(char **map, int i)
{
	int	j;

	j = 0;
	skip_white(map, &i, &j, 1);
	while (map && map[i][j])
	{
		if (map[i][j] != '1')
			return (0);
		skip_chars(map, &i, &j, 1);
		if (map[i][j - 1] && map[i][j - 1] != '1')
			return (0);
		skip_white(map, &i, &j, 1);
	}
	return (1);
}

int	col_closed(char **map, int j)
{
	int	i;

	i = 0;
	skip_white(map, &i, &j, 0);
	while (map && map[i] && map[i][j])
	{
		if (map[i][j] != '1')
			return (0);
		skip_chars(map, &i, &j, 0);
		if (map[i - 1] && map[i - 1][j] != '1')
			return (0);
		skip_white(map, &i, &j, 0);
	}
	return (1);
}

int	map_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		if (!row_closed(map, i))
			return (0);
		i++;
	}
	i = 0;
	j = 0;
	while (j < longest_row(map))
	{
		if (!col_closed(map, j))
			return (0);
		j++;
	}
	return (1);
}
