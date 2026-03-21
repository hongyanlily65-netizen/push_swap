/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykhan-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:10:18 by aykhan-i          #+#    #+#             */
/*   Updated: 2026/03/20 12:00:00 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (-1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	bring_min_to_top(t_stack **stack_a, t_bench *bench)
{
	int	size;
	int	min_pos;

	size = ft_stacksize(*stack_a);
	min_pos = find_min_pos(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			rotate_ra(stack_a, bench);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			reverse_rra(stack_a, bench);
			min_pos++;
		}
	}
}

void	selection_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	size;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	bench->strat = ft_strdup("Selection sort / O(n^2)");
	size = ft_stacksize(*stack_a);
	while (size > 0 && is_stack_sorted(*stack_a) != 0)
	{
		bring_min_to_top(stack_a, bench);
		push_pb(stack_a, stack_b, bench);
		size--;
	}
	while (*stack_b)
		push_pa(stack_a, stack_b, bench);
}
