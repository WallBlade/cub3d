/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:53:59 by zel-kass          #+#    #+#             */
/*   Updated: 2023/04/12 23:44:09 by zel-kass         ###   ########.fr       */
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
		if (ft_strncmp(line, "NO", 2) == 0)
			return (PATH);
		else if (ft_strncmp(line, "SO", 2) == 0)
			return (PATH);
		else if (ft_strncmp(line, "WE", 2) == 0)
			return (PATH);
		else if (ft_strncmp(line, "EA", 2) == 0)
			return (PATH);
		else if (ft_strncmp(line, "F", 1) == 0)
			return (COLOR);
		else if (ft_strncmp(line, "C", 1) == 0)
			return (COLOR);
	return (FALSE);
}