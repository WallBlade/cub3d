/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_map_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:54:19 by smessal           #+#    #+#             */
/*   Updated: 2023/05/23 14:26:49 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid(char c, char *elems)
{
	int	i;

	i = 0;
	while (elems && elems[i])
	{
		if (c == elems[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_elem(char c, char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	rep_pos(char **map)
{
	int		i;
	char	*elems;
	int		ok;

	i = 0;
	ok = 0;
	elems = "NSEW";
	while (elems && elems[i])
	{
		if (!ok && count_elem(elems[i], map) != 0)
		{
			if (count_elem(elems[i], map) == 1)
				ok = 1;
			else
				return (0);
		}
		else if (count_elem(elems[i], map) != 0)
			return (0);
		i++;
	}
	if (ok)
		return (1);
	return (0);
}

void	map_elem(char **map)
{
	int		i;
	int		j;
	char	*elems;

	i = 0;
	elems = "01NSEW ";
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid(map[i][j], elems))
				print_error("ERROR\nWrong element in map", NULL, NULL);
			j++;
		}
		i++;
	}
	if (!rep_pos(map))
		print_error("ERROR\nMultiple starting points", NULL, NULL);
}
