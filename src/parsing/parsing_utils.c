/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:53:59 by zel-kass          #+#    #+#             */
/*   Updated: 2023/04/16 14:15:51 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_error(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
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

char	*clean_data(char *path)
{
	char	*ret;
	char	**line;

	line = ft_split(path, ' ');
	if (line[1])
		ret = ft_strdup(line[1]);
	return (ret);
}
