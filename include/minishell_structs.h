/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:15:16 by sadoming          #+#    #+#             */
/*   Updated: 2024/03/04 19:49:34 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

# include "minishell.h"

enum	e_toktype
{
	ARGS,
	ENV,
	OPTION,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_DEL,
	REDIR_APP,
	TNULL
};

typedef struct s_token
{
	enum e_toktype	toktype;
	char			*comand;
	char			**options;
	char			*args;
	struct s_token	*next;
}					t_token;

typedef struct s_minishell
{
	char		**env;
	t_token		*tokens;
	size_t		sizeof_tok;
}				t_minishell;

#endif
