/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:56:43 by sadoming          #+#    #+#             */
/*   Updated: 2024/03/04 19:49:24 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../readline/readline.h"
# include "../readline/history.h"

# include "../libft/include/libft.h"
# include "colors.h"
# include "minishell_structs.h"

# include <fcntl.h>
# include <stdio.h>

void		print_minishell_welcome(char **env);
void		exit_minishell(t_minishell *tshell);
void		start_signals(void);

char		*ft_readline(void);

void		print_err_args(void);

/* TO TEST OR TESTING */
void		split_intotokens(char *command);

void		*free_tshell(t_minishell *tshell);
t_minishell	*init_tshell(t_minishell *tshell, char **env);

/* BUILTINS */
int			ft_echo(char *n, char *message);

/* UTILS FOR DEBBUG */
void		print_all_arrstr(char **arr);

#endif
