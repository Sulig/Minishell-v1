/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:45:37 by sadoming          #+#    #+#             */
/*   Updated: 2024/03/01 17:50:25 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minishell.h"

void	exit_minishell(void)
{
	ft_printf_fd(2, "minishell$: exit\n");
	rl_clear_history();
	exit(0);
}

char	*ft_readline(void)
{
	char	*line;
	char	*prompt;

	prompt = "minishell$: ";
	line = readline(prompt);
	if (!line && rl_line_buffer)
		exit_minishell();
	if (ft_strllen(line))
		add_history(line);
	return (line);
}
