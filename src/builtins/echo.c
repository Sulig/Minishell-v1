/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:43:35 by sadoming          #+#    #+#             */
/*   Updated: 2024/03/01 19:20:19 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_echo(char *n, char *message)
{
	int	tmp;
	int	ret;
	int	save;

	ret = 0;
	tmp = 0;
	save = 1;
	if (ft_strllen(n))
	{
		if (!my_strcmp(n, "-n"))
			tmp = ft_printf("%s", n);
		else
			save = 0;
	}
	if (ft_strllen(message))
		ret = ft_printf("%s", message);
	if (save)
		save = ft_printf("\n");
	if (save == -1 || tmp == -1 || ret == -1)
		return (1);
	return (0);
}
