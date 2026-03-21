/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:22:58 by hohu              #+#    #+#             */
/*   Updated: 2026/02/28 13:05:14 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(char const *s, char c)
{
	int	i;
	int	counter;
	int	flag;

	i = 0;
	counter = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			counter++;
		}
		else if (s[i] == c)
		{
			flag = 0;
		}
		i++;
	}
	return (counter);
}

static void	ft_cleaner(char **res)
{
	int	i;

	if (!res)
		return ;
	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static int	ft_add_word(char **res, char const *s, int start, int len)
{
	char	*word;

	word = ft_substr(s, (unsigned int)start, (size_t)len);
	if (!word)
	{
		ft_cleaner(res);
		return (0);
	}
	res[0] = word;
	return (1);
}

int	ft_fill(char **res, char const *s, char c)
{
	int		k;
	int		len;

	while (*s)
	{
		while (*s == c)
			s++;
		k = 0;
		while (s[k] && s[k] != c)
			k++;
		if (k > 0)
		{
			len = k;
			if (!ft_add_word(res, s, 0, len))
				return (0);
			res++;
		}
		s += k;
	}
	*res = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		num_s;
	char	**res;

	if (!s)
		return (NULL);
	num_s = ft_counter(s, c);
	res = (char **)calloc((size_t)(num_s + 1), sizeof(char *));
	if (res == NULL)
		return (NULL);
	if (!ft_fill(res, s, c))
		return (NULL);
	return (res);
}
