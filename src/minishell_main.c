/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:44:50 by sadoming          #+#    #+#             */
/*   Updated: 2024/03/04 19:49:31 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell(char **env, t_minishell *tshell)
{
	char	*line;

	(void) env;
	while (4)
	{
		start_signals();
		line = ft_readline();
		if (!line)
			exit_minishell(tshell);
		//tokenize \\> error handler case " ' 
		split_intotokens(line);
		free(line);
		//parser \\> error handler case ...
		//expand, split (echo " case "), quote removal
		//Redirect \\> error on filedescriptors
		//execute \\> error execution
		//exit status or contiue in loop
		rl_on_new_line();
	}
}

int	main(int argc, char **args, char **env)
{
	t_minishell	*t_minishell;

	t_minishell = NULL;
	if (argc != 1 || (ft_arr_strlen(args) > 2))
		print_err_args();
	print_minishell_welcome(env);
	t_minishell = init_tshell(t_minishell, env);
	minishell(env, t_minishell);
	t_minishell = free_tshell(t_minishell);
	return (0);
}
