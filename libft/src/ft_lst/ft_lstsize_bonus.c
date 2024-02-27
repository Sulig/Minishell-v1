/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:55:09 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/22 16:27:39 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	cnt;

	cnt = 0;
	while (lst != 0)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}
