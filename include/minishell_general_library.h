/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_general_library.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:26:45 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/27 19:54:35 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_GENERAL_LIBRARY_H
# define MINISHELL_GENERAL_LIBRARY_H

# include "../libft/include/libft.h"
# include "print_errors.h"
# include "colors.h"
# include <fcntl.h>

# include <readline/readline.h>
# include <readline/history.h>

void	print_minishell_welcome(char **env);

/* UTILS FOR DEBBUG */
void	print_all_arrstr(char **arr);

#endif
