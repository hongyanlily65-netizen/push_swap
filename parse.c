/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:09:53 by hohu              #+#    #+#             */
/*   Updated: 2026/02/24 21:50:51 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_cleaner(char **res)
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
long	atol(char *s)
{
	int	i;
	char	sign;
	long	res;	
	
	i = 0;
	sign = 1;
	res = 0;
	if (!res)
		return (0);
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res*10 + (s[i] - 48);
		i++;
	}
	return (res * sign);
			
		
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
	if (!stack || !nbr)
		return (1);//1 means the argument is true, when it is true it frees the stack
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

	i = start;
	while (res[i])
	{
		if (!(ft_is_number(res[i])))
			return (error_free(&stack), NULL);
		nbr = atol(res[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (error_free(&stack), NULL);
		if (ft_is_duplicated(stack, nbr))
			return (error_free(&stack), NULL);	
		if (!append(&stack, nbr))
			return (error_free(&stack), NULL);
		i++;
	}
	return (stack);


