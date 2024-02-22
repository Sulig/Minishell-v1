/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_welcome.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:57:47 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/22 20:03:57 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell_general_library.h"

void	print_minishell_welcome(char **env)
{
	char	*logname;

	logname = ft_search_str(env, "LOGNAME");
	logname = logname + ft_cnttoch_in(logname, '=');
	logname = "~~";
	if (logname)
	{
		//Add change color if 0+1 == 232 to 240
		ft_printf("\033[38;5;%im\t", logname[0] + logname[1]);
		ft_printf("~ Gretings %s ~\n", logname);
	}
}
