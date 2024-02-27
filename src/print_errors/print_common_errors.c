/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_common_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:53:09 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/27 19:54:40 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/print_errors.h"

void	print_err_args(void)
{
	ft_printf_fd(2, Y);
	ft_printf_fd(2, "Please don't introduce arguments in ");
	ft_printf_fd(2, "minishell \nIt will not be interpreted\n");
	exit(1);
}

void	print_err_readline(void)
{
	ft_printf_fd(2, R);
	ft_printf_fd(2, "An error on readline has ocurred\n");
	ft_printf_fd(2, D);
}
