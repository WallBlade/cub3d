/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:21:16 by smessal           #+#    #+#             */
/*   Updated: 2023/05/09 18:41:48 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cwords(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (s[i] != c && s[i] != ' ' && s[i] != '\t')
		{
			count++;
			while (s[i] && (s[i] != c && s[i] != ' ' && s[i] != '\t'))
				i++;
		}
		while (s[i] && (s[i] == c || s[i] == ' ' || s[i] == '\t'))
			i++;
	}
	return (count);
}

int	ft_wdlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s && s[i] && (s[i] != c  && s[i] != ' ' && s[i] != '\t'))
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char *s, char c)
{
	char	**big;
	int		i;
	int		j;
	int		k;

	big = collect(sizeof(char *) * (ft_cwords(s, c) + 1));
	if (!big)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_cwords(s, c))
	{
		k = 0;
		while (s[i] && (s[i] == c || s[i] == ' ' || s[i] == '\t'))
			i++;
		big[j] = collect(sizeof(char) * (ft_wdlen(s, c, i) + 1));
		if (!big[j])
			return (NULL);
		while (s[i] && (s[i] != c && s[i] != ' ' && s[i] != '\t'))
			big[j][k++] = s[i++];
		big[j++][k] = '\0';
	}
	big[j] = 0;
	return (big);
}
