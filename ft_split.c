/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:45:23 by hohu              #+#    #+#             */
/*   Updated: 2026/02/22 18:52:04 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(const char *s, int start, int len)
{
	char	*res;
	size_t	i;
	
	i = 0;
	res = (malloc(sizeof(char) * (len + 1)));
	if (!res)
		return (NULL);
	while  (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	i;
	size_t	memsize;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	memsize = nmemb * size;
	res = malloc(memsize);
	if (!res)
		return (NULL);
	i = 0;
	while (i < memsize)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}

void	ft_cleaner(char **res)
{
	int	i;
	
	if	(!res)
		return ;
	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

int	ft_add_word(char **res, const char *s, int start, int len)
{
	char	*word;
	
	word = ft_substr(s, start, len);
	if (!word)
	{
		ft_cleaner(res);
		return (0);
	}
	*res = word;
	return (1);
}
	
int	ft_fill(char **res, const char *s, char c)
{
	int	i;
	int	start;
	int len;
	
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		len = i - start;
		if (!ft_add_word(res, s, start, len))
			return (0);
		res++;
	}
	*res = NULL;
	return (1);
}

int	count_words(const char *s, char c)
{
	int	flag;
	int	i;
	int count;
	
	i = 0;
	count = 0;
	flag = 0;
	while (s[i])
	{
		if(s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		if(s[i] == c)
		{
			flag = 0;
		}
		i++;
	}
}
char	**ft_split(const char *s, char c)
{
	size_t	words;
	char	**res;
	words = count_words(s, c);
	res = ft_calloc(words + 1, sizeof(char *));
	if (!res)
		return NULL;
	if (!ft_fill(res,s,c))
		return (NULL);
	return (res);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**arr;
	int	i;
	if (argc != 2)
		return (0);
	str = argv[1];
	arr = ft_split(str, ' ');
	if (!arr)
		return (1);
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	return (0);
}
