/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrucciones_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykhan-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 21:24:30 by aykhan-i          #+#    #+#             */
/*   Updated: 2026/03/14 22:50:31 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return ;
}

void	swap_sa(t_stack **stackA, t_bench *bench)
{
	ft_swap(stackA);
	write(1, "sa\n", 3);
	bench->sa++;
}

void	swap_sb(t_stack **stackB, t_bench *bench)
{
	ft_swap(stackB);
	write(1, "sb\n", 3);
	bench->sb++;
}

void	swap_ss(t_stack **stackA, t_stack **stackB, t_bench *bench)
{
	ft_swap(stackA);
	ft_swap(stackB);
	write(1, "ss\n", 3);
	bench->ss++;
}
