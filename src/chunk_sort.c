/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykhan-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:12:45 by aykhan-i          #+#    #+#             */
/*   Updated: 2026/03/16 23:07:55 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_blocks(int size)
{
	if (size <= 100)
		return (15);
	else
		return (50);
}

static void	rotate_to_max(t_stack **stack_b, int max_index, t_bench *bench)
{
	int	size;
	int	position;

	size = ft_stacksize(*stack_b);
	position = find_position(*stack_b, max_index);
	if (position <= size / 2)
	{
		while ((*stack_b)->index != max_index)
			rotate_rb(stack_b, bench);
	}
	else
	{
		while ((*stack_b)->index != max_index)
			reverse_rrb(stack_b, bench);
	}
	size--;
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	max_index;

	if (!stack_b || !*stack_b)
		return ;
	while (*stack_b)
	{
		if (!(*stack_b)->next)
		{
			push_pa(stack_a, stack_b, bench);
			break ;
		}
		max_index = find_max_index(*stack_b);
		rotate_to_max(stack_b, max_index, bench);
		push_pa(stack_a, stack_b, bench);
	}
}

void	chunk_sort(t_stack **stack_A, t_stack **stack_B, t_bench *bench)
{
	int	i;
	int	blocks;

	i = 0;
	bench->strat = ft_strdup("Chunk sort / 0(n * sqrt(n))");
	blocks = get_blocks(ft_stacksize(*stack_A));
	while (*stack_A)
	{
		if ((*stack_A)->index <= i)
		{
			push_pb(stack_A, stack_B, bench);
			rotate_rb(stack_B, bench);
		}
		else if ((*stack_A)->index <= i + blocks)
		{
			push_pb(stack_A, stack_B, bench);
			i++;
		}
		else
			rotate_ra(stack_A, bench);
	}
	push_back_to_a(stack_A, stack_B, bench);
}
