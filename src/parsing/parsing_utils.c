/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:53:59 by zel-kass          #+#    #+#             */
/*   Updated: 2023/04/13 17:24:35 by smessal          ###   ########.fr       */
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
			return (PATH);
		else if (ft_strncmp(&line[i], "SO", 2) == 0)
			return (PATH);
		else if (ft_strncmp(&line[i], "WE", 2) == 0)
			return (PATH);
		else if (ft_strncmp(&line[i], "EA", 2) == 0)
			return (PATH);
		else if (ft_strncmp(&line[i], "F", 1) == 0)
			return (COLOR);
		else if (ft_strncmp(&line[i], "C", 1) == 0)
			return (COLOR);
	return (FALSE);
}
