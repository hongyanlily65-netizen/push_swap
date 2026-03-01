/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:09:53 by hohu              #+#    #+#             */
/*   Updated: 2026/02/28 15:33:16 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char *get_str(char **argv)
{	
	int	i;
	
	i = 1;
	while (argv[i][0])
		i++;
	return (argv[i]);
}
		

void	free_split(char **res)
{
	int	i;
	
	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}
}
long int	atol(const char *nptr)
{
	int	i;
	char	sign;
	long int	res;	
	
	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res*10 + (nptr[i] - 48);
		i++;
	}
	return (res * sign);
}			
		
int	is_number(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

static int  ft_is_duplicated_before(long nbr, char **arg, int end)
{
    int j;

    j = 0;
    while (j < end)
    {
        if (arg[j][0] != '\0' && ft_atol(arg[j]) == nbr)
            return (1);
        j++;
    }
    return (0);
}
	
int	check_args(int argc,  char **argv)
{
	long	nbr;
	int	i;
	char	**arg;
	
	if (argc == 2)
		arg = ft_split(get_input_str(argv), " ");
	else
		arg = argv + 1;
	if (!arg)
		return (0); 
	i = 0;
	while (arg[i])
	{
		if (arg[i][0] != '\0') 
		{
			if (!is_num(arg[i]))
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
		}
		i++;
	}
	if (argc == 2)
		free_split(arg);
	return (1);
}

