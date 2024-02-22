/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:16:34 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/22 17:00:14 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LENGHT_H
# define LENGHT_H

# include <stdlib.h>

/* LENGHT */
size_t	ft_arr_strlen(char **s);
size_t	ft_strlen(const char *s);
size_t	ft_strllen(const char *s);
size_t	ft_cnttoch_in(const char *str, char c);
size_t	ft_cnttoch_out(const char *str, char c);
size_t	ft_numlen(size_t n, int base);

#endif
