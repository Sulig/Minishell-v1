/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_cast_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:55:07 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/13 13:50:15 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putchar_fd(char ch, int fd)
{
	int	ret;

	ret = write(fd, &ch, 1);
	return (ret);
}

int	ft_putstr_fd(char *str, int fd)
{
	int		ret;
	int		cnt;

	ret = 0;
	cnt = -1;
	if (str == NULL)
		return (write(fd, "(null)", 6));
	while (str[++cnt])
	{
		if (write(fd, &str[cnt], 1) == -1)
			return (-1);
		ret++;
	}
	return (ret);
}

int	ft_putnbr_fd(int nbr, int fd)
{
	char	*str;
	int		ret;

	str = ft_itoa(nbr);
	ret = ft_putstr_fd(str, fd);
	free(str);
	return (ret);
}

int	ft_putunsig_fd(size_t nbr, char cast, int fd)
{
	char	*str;
	int		ret;
	int		save;

	save = 0;
	if (cast == 'p')
		save = ft_putstr_fd("0x", fd);
	if (save == -1)
		return (save);
	str = ft_unsig_tobase(nbr, cast);
	ret = ft_putstr_fd(str, fd);
	free(str);
	if (ret == -1)
		return (ret);
	return (ret + save);
}
