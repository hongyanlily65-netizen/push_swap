/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaipidi <bsaipidi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:00:20 by bsaipidi          #+#    #+#             */
/*   Updated: 2026/03/17 17:36:40 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// library used for malloc, free
# include <stdlib.h>
// library used for size_t, NULL
# include <stddef.h>
// library used for INT_MIN,INT_MAX
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
// library used for O_RDONLY
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}					t_list;
// functions of the ctype.h library

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

// functions of the string.h library

size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strdup(const char *s);

// no estoy seguro de esta, hay que comprovar

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

// ya normal
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

// functions of the stdlib.h library

int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);

// From here starts second part, addtitional functions

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*strmapi(char const *s, char (*f)(unsigned int, char));

// needs to be checked fcntl.h
// void	ft_striteri(char *s, void (*f)(unsigned int, *char));

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// linked list functions

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
