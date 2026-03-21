/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrucciones_reverse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykhan-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:58:29 by aykhan-i          #+#    #+#             */
/*   Updated: 2026/03/14 22:50:05 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = ft_stacklast(*stack);
	second_last = *stack;
	while (second_last->next->next != NULL)
	{
		second_last = second_last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	reverse_rra(t_stack **stackA, t_bench *bench)
{
	ft_reverse(stackA);
	write(1, "rra\n", 4);
	bench->rra++;
}

void	reverse_rrb(t_stack **stackB, t_bench *bench)
{
	ft_reverse(stackB);
	write(1, "rrb\n", 4);
	bench->rrb++;
}

void	reverse_rrr(t_stack **stackA, t_stack **stackB, t_bench *bench)
{
	ft_reverse(stackA);
	ft_reverse(stackB);
	write(1, "rrr\n", 4);
	bench->rrr++;
}
