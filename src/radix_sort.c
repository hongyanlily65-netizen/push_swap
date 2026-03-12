/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykhan-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:21:09 by aykhan-i          #+#    #+#             */
/*   Updated: 2026/03/11 22:52:03 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *stack)
{
	int		nbr_max;
	int		bits_max;
	t_stack	*tmp;

	if (!stack || !stack->index)
		return (0);
	tmp = stack;
	nbr_max = tmp->index;
	while (tmp)
	{
		if (tmp->index > nbr_max)
			// Mira si el index del nodo actual es mayor que el máximo encontrado hasta ahora
			nbr_max = tmp->index; // Si el índice actual es mayor,
				entonces ese pasa a ser el nuevo máximo.
		tmp = tmp->next;          // Avanza al siguiente elemento de la lista.
	}
	bits_max = 0;
	while ((nbr_max >> bits_max) != '\0')
	{
		bits_max++;
	}
	return (bits_max);
}

void	radix_sort(t_stack **stack_A, t_stack **stack_B)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = ft_stacksize(*stack_A);
	max_bits = get_max_bits(*stack_A);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_A)->index >> i) & 1) == 1)
				rotate_ra(stack_A);
			else
				push_pb(stack_A, stack_B);
			j++;
		}
		while (*stack_B)
			push_pa(stack_A, stack_B);
		i++;
	}
}
