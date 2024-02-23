/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_welcome.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:57:47 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/23 16:01:58 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell_general_library.h"

void	print_minishell_welcome(char **env)
{
	char	*logname;
	size_t	color;

	logname = ft_search_str(env, "LOGNAME");
	logname = logname + ft_cnttoch_in(logname, '=');
	if (!logname)
		logname = "(null)";
	color = logname[0] + logname[1];
	if (color >= 232 && color <= 240)
		color = logname[0];
	ft_printf("\033[38;5;%um\t", color);
	ft_printf("~ Gretings %s ~\n", logname);
}
