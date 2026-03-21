/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:26:41 by hohu              #+#    #+#             */
/*   Updated: 2026/01/18 17:26:48 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	max_len;
	char	*res;
	size_t	i;

	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	max_len = slen - start;
	if (max_len > len)
		max_len = len;
	res = malloc(max_len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < max_len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
