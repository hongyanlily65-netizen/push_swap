/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_indice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 22:53:26 by hohu              #+#    #+#             */
/*   Updated: 2026/03/14 22:48:53 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*i;
	t_stack	*j;

	if (!stack || !stack->next)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	i = stack;
	while (i->next != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((int)(((float)mistakes / (float)total_pairs) * 10000.0));
}
