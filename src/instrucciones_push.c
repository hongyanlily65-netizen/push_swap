/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrucciones_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykhan-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 21:45:26 by aykhan-i          #+#    #+#             */
/*   Updated: 2026/03/14 22:49:52 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_pa(t_stack **stackA, t_stack **stackB, t_bench *bench)
{
	t_stack	*tmp;

	if (!stackA || !stackB)
		return ;
	tmp = *stackB;
	*stackB = (*stackB)->next;
	tmp->next = *stackA;
	*stackA = tmp;
	write(1, "pa\n", 3);
	bench->pa++;
}

void	push_pb(t_stack **stackA, t_stack **stackB, t_bench *bench)
{
	t_stack	*tmp;

	if (!stackA || !stackB)
		return ;
	tmp = *stackA;
	*stackA = (*stackA)->next;
	tmp->next = *stackB;
	*stackB = tmp;
	write(1, "pb\n", 3);
	bench->pb++;
}
