/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:36:04 by smessal           #+#    #+#             */
/*   Updated: 2023/04/17 15:40:08 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
