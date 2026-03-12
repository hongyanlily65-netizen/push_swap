/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykhan-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:10:18 by aykhan-i          #+#    #+#             */
/*   Updated: 2026/03/12 20:34:57 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	bubble_sort(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	while (!is_stack_sorted(*stack))
	{
		tmp = *stack;
		while (tmp->next)
		{
			if (tmp->value > tmp->next->value)
				swap_sa(stack);
			else
				tmp = tmp->next;
		}
	}
}
