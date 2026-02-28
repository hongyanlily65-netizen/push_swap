/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:09:53 by hohu              #+#    #+#             */
/*   Updated: 2026/02/28 14:17:51 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
t_list *parse_args_split(char **res) 
{
	return (parse_array(res, 0));
}
t_list *parse_args(int argc, char **argv)
{
	(void)argc;
	return (parse_array(argv, 1));
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
		
void	error_free(t_list **stack)
{
	ft_lstclear(stack);
	write(2,"error\n", 6);
}
	
int	ft_is_number(char *str)
{
	if (!str)
		return (0);
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
int	ft_is_duplicated(t_list *stack,int nbr)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}
	
t_list	*parse_array(char **res, int start)
{
	t_list	*stack;
	long	nbr;
	int	i;
	t_list	*new_node;
	
	stack = NULL;
	i = start;
	while (res[i])
	{
		if (!(ft_is_number(res[i])))
			return (error_free(&stack), NULL);
		nbr = atol(res[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (error_free(&stack), NULL);
		if (ft_is_duplicated(stack, (int)nbr))
			return (error_free(&stack), NULL);
		new_node = ft_lstnew((int)nbr);
		if (!new_node)
			 return (error_free(&stack), NULL);  
		ft_lstadd_back(&stack, new_node);
		i++;
	}
	return (stack);
}

