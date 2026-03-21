/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:57:51 by hohu              #+#    #+#             */
/*   Updated: 2026/01/06 19:57:59 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	cc;
	size_t			i;

	src = (unsigned char *)s;
	cc = (unsigned char )c;
	i = 0;
	while (i < n)
	{
		if (src[i] == cc)
		{
			return ((void *)(&src[i]));
		}
		i++;
	}
	return (0);
}
