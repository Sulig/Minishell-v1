/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:44:50 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/21 20:02:47 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell_general_library.h"

void	ft_print_chararr(char **arr)
{
	size_t	i;

	i = 0;
	if (!ft_arr_strlen(arr))
		ft_printf_fd(1, "Null array\n");
	else
	{
		while (arr[i])
		{
			ft_printf_fd(1, "Pos |%u|: %s\n", i, arr[i]);
			i++;
		}
	}
}

int	main(int argc, char **args, char **env)
{
	char	*logname;

	if (argc != 1 || (ft_arr_strlen(args) > 2))
		print_err_args();
	ft_printf_fd(1, "Introducing Minishell\n\n");
	ft_printf_fd(1, "Args:\n");
	ft_print_chararr(args);
	ft_printf_fd(1, "\nEnviroment:\n");
	ft_print_chararr(env);
	logname = ft_substr(env[25], 8, ft_strllen(env[25]));
	ft_printf_fd(1, "\n\t~ Greetings \033[38;5;%im %s ~\n", logname[0], logname);
	if (logname)
		free(logname);
	return (0);
}
