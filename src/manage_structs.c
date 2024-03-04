/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:47:15 by sadoming          #+#    #+#             */
/*   Updated: 2024/03/04 19:49:26 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*free_tshell(t_minishell *tshell)
{
	if (!tshell)
		return (NULL);
	tshell->env = ft_auto_free_arr(tshell->env);
	if (tshell->tokens)
		free(tshell->tokens);
	free(tshell);
	return (NULL);
}

t_minishell	*init_tshell(t_minishell *tshell, char **env)
{
	tshell = ft_calloc(sizeof(t_minishell), 1);
	if (!tshell)
		return (NULL);
	tshell->env = ft_strarrdup(env);
	if (!tshell->env)
		return (free_tshell(tshell));
	tshell->tokens = ft_calloc(sizeof(t_token), 1);
	if (!tshell->tokens)
		return (free_tshell(tshell));
	return (tshell);
}
