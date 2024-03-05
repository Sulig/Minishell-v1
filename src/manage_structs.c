/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:47:15 by sadoming          #+#    #+#             */
/*   Updated: 2024/03/05 17:16:13 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*free_tshell(t_shell *tshell)
{
	if (!tshell)
		return (NULL);
	tshell->env = ft_auto_free_arr(tshell->env);
	if (tshell->tokens)
		free(tshell->tokens); //free all tokens
	free(tshell);
	return (NULL);
}

t_shell	*init_tshell(t_shell *tshell, char **env)
{
	tshell = ft_calloc(sizeof(t_shell), 1);
	if (!tshell)
		return (NULL);
	tshell->env = ft_strarrdup(env);
	if (!tshell->env)
		return (free_tshell(tshell));
	return (tshell);
}
