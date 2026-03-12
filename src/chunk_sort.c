/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykhan-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:12:45 by aykhan-i          #+#    #+#             */
/*   Updated: 2026/03/12 22:19:12 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_blocks(int size)
{
	// Elegir múltiplo base: 5 o 10
	if (size <= 100)
		return (5);
	else
		return (10);
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max_index;
	int	position;

	if (!stack_b)
		return ;
	while (*stack_b)
	{
		max_index = find_max_index(*stack_b);
		position = find_position(*stack_b, max_index);
		size = ft_stacksize(*stack_b);
		if (position <= (size / 2))
		{
			while ((*stack_b)->index != max_index)
			{
				rotate_rb(stack_b);
			}
		}
		else
		{
			while ((*stack_b)->index != max_index)
			{
				reverse_rrb(stack_b);
			}
		}
		push_pa(stack_a, stack_b);
	}
}

void	chunk_sort(t_stack **stack_A, t_stack **stack_B)
{
	int	i;
	int	blocks;

	i = 0;
	blocks = get_blocks(ft_stacksize(*stack_A));
	while (stack_A)
	{
		if ((*stack_A)->index <= i)
		{
			push_pb(stack_A, stack_B);
			rotate_rb(stack_B);
		}
		else if ((*stack_A)->index <= i + blocks)
		{
			push_pb(stack_A, stack_B);
			i++;
		}
		else
			rotate_ra(stack_A);
	}
	push_back_to_a(stack_A, stack_B);
}

