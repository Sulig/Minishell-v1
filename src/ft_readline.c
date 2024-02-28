/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:45:37 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/28 19:57:18 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <readline/readline.h>
# include <readline/history.h>
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
