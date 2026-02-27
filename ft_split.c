/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:22:58 by hohu              #+#    #+#             */
/*   Updated: 2026/01/18 21:23:06 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

static void	ft_fill(char **res, char const *s, char c)
{
	int		j;
	int		k;
	int		len;

	j = 0;
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
				return ;
			res++;
		}
		s += k;
	}
	*res = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		num_s;
	char	**res;

	if (!s)
		return (NULL);
	num_s = ft_counter(s, c);
	res = (char **)malloc((num_s + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	ft_fill(res, s, c);
	return (res);
}
/*
int	main(int argc, char *argv[])
{
	char *str = argv[1];

	char **res = ft_split(str, ' ');
	
	for(int i = 0; res[i] != NULL ; i++)
	{
		printf("%s\n", res[i]);
		free(res[i]);
	}
	free(res);


	return (0);
}*/
