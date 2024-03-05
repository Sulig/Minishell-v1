/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:45:41 by sadoming          #+#    #+#             */
/*   Updated: 2024/03/05 17:36:20 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

enum	e_toktype scan_toktype(char c)
{
	if (c == ' ')
		return (TNULL);
	else if (c == '$')
		return (ENV);
	else if (c == '-')
		return (OPTION);
	else if (c == '"')
		return (D_QUOTE);
	else if (c == 39)
		return (U_QUOTE);
	else if (c == '|')
		return (PIPE);
	else if (c == '<')
		return (REDIR_IN);
	else if (c == '>')
		return (REDIR_OUT);
	else
		return (ARGS);
}

/*
t_token	create_token()
*/

t_shell	*split_intotokens(char *command, t_shell *tshell)
{
	enum e_toktype	toktype;
	t_token	*tokens;
	t_token	*tmp;
	size_t	i;

	i = 0;
	tokens = NULL;
	tmp = NULL;
	if (!ft_strllen(command))
		return (NULL);
	while (!tokens && command[i])
	{
		toktype = scan_toktype(command[i]);
		if (toktype != TNULL)
			ft_printf("detected a token, type of token = %d\n", toktype);
			//tokens = create_token(tokens, comand, i);
		i++;
	}
	tshell->tokens = tokens;
	return (tshell);
}
