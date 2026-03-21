/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:15:59 by hohu              #+#    #+#             */
/*   Updated: 2026/01/18 21:19:39 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(long nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*res;

	nb = n;
	len = count_len(nb);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		res[len - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
/*
int	main(void)
{
	int	i = -908;
	printf("%s",ft_itoa(i));
	return (0);
}*/
