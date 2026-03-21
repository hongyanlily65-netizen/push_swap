/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:30:42 by hohu              #+#    #+#             */
/*   Updated: 2026/03/14 22:49:14 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*find_min_ptr(t_stack *stack)
{
	int		min;
	t_stack	*min_ptr;

	min_ptr = NULL;
	min = INT_MAX;
	while (stack)
	{
		if (stack->value < min && stack->index == -1)
		{
			min_ptr = stack;
			min = stack->value;
		}
		stack = stack->next;
	}
	return (min_ptr);
}

void	assign_index(t_stack *stack)
{
	int		size;
	int		i;
	t_stack	*node;

	size = ft_stacksize(stack);
	i = 0;
	while (i < size)
	{
		node = find_min_ptr(stack);
		if (!node)
			break ;
		node->index = i;
		i++;
	}
}
