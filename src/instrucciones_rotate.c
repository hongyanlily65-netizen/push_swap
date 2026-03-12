/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrucciones_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykhan-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 22:43:01 by aykhan-i          #+#    #+#             */
/*   Updated: 2026/03/11 22:51:30 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	((t_stack *)ft_stacklast(*stack))->next = tmp;
	tmp->next = NULL;
}

void	rotate_ra(t_stack **stackA)
{
	ft_rotate(stackA);
	write(1, "ra\n", 3);
}

void	rotate_rb(t_stack **stackB)
{
	ft_rotate(stackB);
	write(1, "rb\n", 3);
}

void	rotate_rr(t_stack **stackA, t_stack **stackB)
{
	ft_rotate(stackA);
	ft_rotate(stackB);
	write(1, "rr\n", 3);
}
