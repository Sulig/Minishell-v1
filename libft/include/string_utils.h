/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:47:20 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/22 16:57:12 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

/* STRING UTILS */
char	*ft_strdup(const char *s1);
char	*ft_strcpyl(const char *s1, size_t len);
char	**ft_strarrdup(char **to_copy);

char	*ft_strcut(char *str, char cut, char mode, char inc);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char*s, unsigned int start, size_t len);

char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strjoin_s(const char *s1, const char *s2);
char	*ft_strjoin_free_fst(char *s1, const char *s2);
char	*ft_strjoin_free_sec(const char *s1, char *s2);

char	*ft_strinter(const char *str, const char *inter, size_t pos);

char	**ft_split(const char *s, char c);

#endif
