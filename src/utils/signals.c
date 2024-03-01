/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:12:37 by sadoming          #+#    #+#             */
/*   Updated: 2024/03/01 18:42:58 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../include/minishell.h"

void	ft_newline_redisplay(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf_fd(1, "\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	start_signals(void)
{
	signal(SIGINT, ft_newline_redisplay);
	signal(SIGQUIT, SIG_IGN);
}
