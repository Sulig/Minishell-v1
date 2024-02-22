/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:40:50 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/12 19:05:31 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

static void	ft_nexttonull(t_list *tonull, int cnt)
{
	while (cnt > 1)
	{
		tonull = tonull->next;
		cnt--;
	}
	tonull->next = NULL;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		cnt;
	t_list	*t_free;

	cnt = ft_lstsize(*lst);
	while (cnt > 0)
	{
		t_free = *lst;
		ft_nexttonull(t_free, cnt);
		t_free = ft_lstlast(t_free);
		(*del)(t_free->content);
		free(t_free);
		cnt--;
	}
	*lst = NULL;
}
