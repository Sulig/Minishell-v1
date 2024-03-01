/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:45:41 by sadoming          #+#    #+#             */
/*   Updated: 2024/03/01 16:10:24 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	split_intotokens(char *command)
{
	char	**arr;

	arr = ft_split(command, ' ');
	print_all_arrstr(arr);
	arr = ft_auto_free_arr(arr);
}
