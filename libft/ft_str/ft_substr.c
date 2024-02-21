/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:52:22 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/21 16:35:03 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	cnt;
	size_t	ln;
	char	*sub;

	ln = ft_strllen(s);
	if (start > ln)
		start = ln;
	if (len >= ft_strllen(s + start))
		len = ft_strllen(s) - start;
	sub = malloc(len + 1);
	if (sub == 0)
		return (0);
	cnt = 0;
	while (cnt < len && s[start])
	{
		sub[cnt] = s[start];
		start++;
		cnt++;
	}
	sub[cnt] = '\0';
	return (sub);
}
