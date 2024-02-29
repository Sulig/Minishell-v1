/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:45:37 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/29 19:07:16 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minishell_general_library.h"

void	exit_minishell(void)
{
	ft_printf("exit\n");
	clear_history();
	exit(0);
}

char	*ft_readline(void)
{
	char	*line;
	char	*prompt;

	prompt = "minishell$ ";
	line = readline(prompt);
	if (!line)
		exit_minishell();
	if (*line)
		add_history(line);
	return (line);
}
