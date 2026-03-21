/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 22:46:13 by hohu              #+#    #+#             */
/*   Updated: 2026/03/14 22:49:03 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	recursive_free(t_stack *head)
{
	t_stack	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	free_all(t_stack **a, t_stack **b, t_bench *bench, t_config *config)
{
	ft_stackclear(a);
	ft_stackclear(b);
	free(bench->strat);
	free(config);
}
