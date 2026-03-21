/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:07:03 by hohu              #+#    #+#             */
/*   Updated: 2026/01/06 20:07:07 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*res;
	size_t		i;
	size_t		memsize;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	memsize = nmemb * size;
	if (nmemb != 0 && memsize / nmemb != size)
		return (NULL);
	res = malloc(memsize);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < memsize)
	{
		res[i] = '\0';
		i++;
	}
	return ((void *)res);
}
