/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrucciones_reverse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykhan-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:58:29 by aykhan-i          #+#    #+#             */
/*   Updated: 2026/03/11 22:51:04 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	*stack = tmp;
	while ((*stack)->next->next != NULL)
	{
		*stack = ((t_stack *)ft_lstlast(*stack))->next;
	}
	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp;
	(*stack)->next = NULL;
	*stack = tmp;
}

void	reverse_rra(t_stack **stackA)
{
	ft_reverse(stackA);
	write(1, "rra\n", 4);
}

void	reverse_rrb(t_stack **stackB)
{
	ft_reverse(stackB);
	write(1, "rrb\n", 4);
}

void	reverse_rrr(t_stack **stackA, t_stack **stackB)
{
	ft_reverse(stackA);
	ft_reverse(stackB);
	write(1, "rrr\n", 4);
}
