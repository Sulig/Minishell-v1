/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:27:16 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/13 14:07:48 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* MEMORY */
void	*ft_auto_free_arr(char **arr);
void	*ft_free_arr(size_t size, char **words);
void	*ft_free_str(char *str);
void	*ft_calloc(size_t count, size_t size);

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);

/* READ */
char	*get_next_line(int fd);

/* PRINT && WRITE */
int		ft_putchar(char ch);
int		ft_putnbr(int nbr);
int		ft_putstr(char *str);
int		ft_putunsig(size_t nbr, char cast);
int		ft_printf(char const *str, ...);

int		ft_putchar_fd(char ch, int fd);
int		ft_putnbr_fd(int nbr, int fd);
int		ft_putstr_fd(char *str, int fd);
int		ft_putunsig_fd(size_t nbr, char cast, int fd);
int		ft_printf_fd(int fd, char const *str, ...);

/* LENGHT */
size_t	ft_arr_strlen(char **s);
size_t	ft_strlen(const char *s);
size_t	ft_strllen(const char *s);
size_t	ft_cnttoch_in(const char *str, char c);
size_t	ft_cnttoch_out(const char *str, char c);
size_t	ft_numlen(size_t n, int base);

/* CONVERSIONS */
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
size_t	ft_atos(const char *str);
char	*ft_itoa(int n);
char	*ft_itoa_unsig(size_t n, char *base);
char	*ft_unsig_tobase(size_t num, char base);

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_toupper_all(char *str);
char	*ft_tolower_all(char *str);
char	*ft_strcapitalize(char *str);

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

/* SEARCHERS */
int		my_strcmp(const char *str, const char *cmp);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/* LIST UTILS */
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
#endif
