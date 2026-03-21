/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:18:14 by hohu              #+#    #+#             */
/*   Updated: 2026/01/06 16:18:20 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dsize;
	size_t	i;
	size_t	ssize;
	size_t	cpsize;
	size_t	j;

	ssize = ft_strlen(src);
	dsize = ft_strlen(dst);
	if (size == 0)
		return (ssize);
	if (dsize >= size)
		return (size + ssize);
	i = dsize;
	j = 0;
	cpsize = size - dsize - 1;
	while (cpsize > 0 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
		cpsize--;
	}
	dst[i] = '\0';
	return (dsize + ssize);
}
