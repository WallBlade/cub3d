/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:46:04 by zel-kass          #+#    #+#             */
/*   Updated: 2023/04/12 18:47:57 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_garbage	**singleton(void)
{
	static t_garbage	*collect;

	return (&collect);
}

void	*collect(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	add_front(singleton(), ptr);
	return (ptr);
}

int	lstsize_garb(t_garbage *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	add_front(t_garbage **lst, void *ptr)
{
	t_garbage	*collect;

	collect = malloc(sizeof(t_garbage));
	if (!collect)
		return ;
	collect->ptr = ptr;
	collect->next = *lst;
	*lst = collect;
	return ;
}

void	free_gc(void)
{
	t_garbage	*collect;
	t_garbage	*tmp;

	collect = (*singleton());
	while (collect)
	{
		free(collect->ptr);
		collect->ptr = NULL;
		tmp = collect;
		collect = collect->next;
		free(tmp);
	}
}