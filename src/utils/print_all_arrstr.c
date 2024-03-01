/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all_arrstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:29:27 by sadoming          #+#    #+#             */
/*   Updated: 2024/03/01 15:59:37 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_all_arrstr(char **arr)
{
	size_t	i;

	i = 0;
	if (!ft_arr_strlen(arr))
		ft_printf_fd(1, "Null array\n");
	else
	{
		while (arr[i])
		{
			ft_printf_fd(1, "Pos |%u|: %s\n", i, arr[i]);
			i++;
		}
	}
}
