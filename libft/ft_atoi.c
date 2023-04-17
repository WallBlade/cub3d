/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:58:26 by smessal           #+#    #+#             */
/*   Updated: 2023/04/17 15:55:33 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 1;
	result = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 7 && nptr[i] <= 13)))
		i++;
	if (nptr[i] && (nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
		result = result * 10 + (nptr[i++] - '0');
	return (result * neg);
}
