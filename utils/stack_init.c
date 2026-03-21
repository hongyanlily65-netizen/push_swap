/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykhan-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 23:20:24 by aykhan-i          #+#    #+#             */
/*   Updated: 2026/03/16 23:09:41 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int nbr)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = nbr;
	node->index = -1;
	node->next = NULL;
	return (node);
}

static int	fill_stack(t_stack **stack, char **arg, int argc)
{
	t_stack	*new_node;
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i][0] != '\0')
		{
			new_node = ft_stacknew(ft_atoi(arg[i]));
			if (!new_node)
			{
				if (argc == 2)
					free_split(arg);
				return (0);
			}
			ft_stackadd_back(stack, new_node);
		}
		i++;
	}
	return (1);
}

t_stack	*stack_init(int argc, char **argv)
{
	t_stack	*stack;
	char	**arg;

	stack = NULL;
	if (argc == 2)
		arg = ft_split(get_str(argv), ' ');
	else
		arg = argv + 1;
	if (!fill_stack(&stack, arg, argc))
		return (NULL);
	assign_index(stack);
	if (argc == 2)
		free_split(arg);
	return (stack);
}
