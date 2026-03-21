/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:09:53 by hohu              #+#    #+#             */
/*   Updated: 2026/03/14 23:17:20 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	*get_str(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] && argv[i][0] != '\0')
		i++;
	return (argv[i]);
}

static int	ft_is_duplicated_before(long nbr, char **arg, int end)
{
	int	j;

	j = 0;
	while (j < end)
	{
		if (arg[j][0] != '\0' && ft_atol(arg[j]) == nbr)
			return (1);
		j++;
	}
	return (0);
}

static int	validate_arg(char **arg, int i, int argc)
{
	long	nbr;

	if (!is_number(arg[i]))
	{
		if (argc == 2)
			free_split(arg);
		return (0);
	}
	nbr = ft_atol(arg[i]);
	if (nbr > INT_MAX || nbr < INT_MIN || ft_is_duplicated_before(nbr, arg, i))
	{
		if (argc == 2)
			free_split(arg);
		return (0);
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int		i;
	char	**arg;

	if (argc == 2)
		arg = ft_split(get_str(argv), ' ');
	else
		arg = argv + 1;
	if (!arg)
		return (0);
	i = 0;
	while (arg[i])
	{
		if (arg[i][0] != '\0' && !validate_arg(arg, i, argc))
			return (0);
		i++;
	}
	if (argc == 2)
		free_split(arg);
	return (1);
}
