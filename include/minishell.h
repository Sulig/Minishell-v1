/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:56:43 by sadoming          #+#    #+#             */
/*   Updated: 2024/03/01 16:00:09 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../readline/readline.h"
# include "../readline/history.h"

# include "../libft/include/libft.h"
# include "colors.h"

# include <fcntl.h>
# include <stdio.h>

void	print_minishell_welcome(char **env);
void	exit_minishell(void);
void	start_signals(void);

char	*ft_readline(void);

void	print_err_args(void);

/* FNT TO/IN TEST*/
void	split_intotokens(char *command);

/* UTILS FOR DEBBUG */
void	print_all_arrstr(char **arr);

#endif
