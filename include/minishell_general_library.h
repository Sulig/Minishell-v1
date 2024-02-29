/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_general_library.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:26:45 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/29 19:07:44 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_GENERAL_LIBRARY_H
# define MINISHELL_GENERAL_LIBRARY_H

# include "../readline/readline.h"
# include "../readline/history.h"
# include "../libft/include/libft.h"
# include "print_errors.h"
# include "colors.h"
# include <fcntl.h>

// # include <readline/readline.h>
// # include <readline/history.h>

void	print_minishell_welcome(char **env);
void	exit_minishell(void);
void	start_signals(void);

char	*ft_readline(void);

/* UTILS FOR DEBBUG */
void	print_all_arrstr(char **arr);

#endif
