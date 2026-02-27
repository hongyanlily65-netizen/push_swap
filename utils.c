/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 19:39:16 by hohu              #+#    #+#             */
/*   Updated: 2026/02/27 19:41:39 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	substr_len;
	char	*res;
	size_t	i;

	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	substr_len = slen - start;
	if (substr_len > len)
		substr_len = len;
	res = malloc(substr_len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < substr_len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	int		len_s;
	int		i;

	len_s = ft_strlen(s);
	res = malloc(len_s + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
