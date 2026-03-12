/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykhan-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:20:58 by aykhan-i          #+#    #+#             */
/*   Updated: 2026/03/11 22:52:21 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *stack)
{
	int	min_pos;
	int	position;
	int	i;

	if (!stack)
		return (-1);
	i = 0;
	position = 0;
	min_pos = stack->index;
	while (stack)
	{
		if (stack->index < min_pos)
		{
			min_pos = stack->index;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

int	find_max_index(t_stack *stack)
{
	int	max_index;

	if (!stack)
		return (-1);
	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
		}
		stack = stack->next;
	}
	return (max_index);
}

int	find_position(t_stack *stack, int value)
{
	int		position;
	t_stack	*tmp;
	position = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index == value)
			return (position);
		tmp = tmp->next;
		position++;
	}
	return (-1);
}
