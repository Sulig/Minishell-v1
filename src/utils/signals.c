/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:12:37 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/28 19:47:59 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../include/minishell_general_library.h"

void	ft_interrupthandler(int signal)
{
	ft_printf("Interrupted by signal %i\n", signal);
}

void	start_signals(void)
{
	signal(SIGINT, ft_interrupthandler);
	signal(SIGQUIT, ft_interrupthandler);
}
