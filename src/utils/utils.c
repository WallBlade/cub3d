/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:36:04 by smessal           #+#    #+#             */
/*   Updated: 2023/05/09 13:57:43 by smessal          ###   ########.fr       */
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
	free_gc();
	exit(EXIT_FAILURE);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

int	longest_row(char **tab)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (tab && tab[i])
	{
		if (ft_strlen(tab[i]) > len)
			len = ft_strlen(tab[i]);
		i++;
	}
	return (len);
}
