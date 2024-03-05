/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:56:43 by sadoming          #+#    #+#             */
/*   Updated: 2024/03/05 17:13:42 by sadoming         ###   ########.fr       */
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

void	print_minishell_welcome(char **env);
void	exit_minishell(t_shell *tshell);
void	start_signals(void);

char	*ft_readline(void);

void	print_err_args(void);

/* TO TEST OR TESTING */
t_shell	*split_intotokens(char *command, t_shell *tshell);

void	*free_tshell(t_shell *tshell);
t_shell	*init_tshell(t_shell *tshell, char **env);

/* BUILTINS */
int		ft_echo(char *n, char *message);

/* UTILS FOR DEBBUG */
void	print_all_arrstr(char **arr);

#endif
