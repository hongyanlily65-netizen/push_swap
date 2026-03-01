/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 20:32:04 by hohu              #+#    #+#             */
/*   Updated: 2026/02/28 14:18:00 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int ft_stacksize(t_stack *lst)
{
	int	i;
	
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
void	ft_stackclear(t_stack **lst)
{
	t_stack	*tmp;
	if	(!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free (*lst);
		*lst = tmp;
	}
}

void	ft_stackadd_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*last;
	
	last = *lst;
	if (!lst || !new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	} 
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->next = NULL;
}
	
t_stack	*ft_stacknew(int nbr)
{
	t_stack	*node;
	
	node = malloc (sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = nbr;
	node->next = NULL;
	return (node);
}


t_stack	*stack_init(int argc, char **argv)
{
	t_stack	*stack;
	char	**arg;
	int	*i;
	t_stack	*new_node;
	
	stack = NULL;
	if (argc == 2)
		arg = ft_split(get_str(argv)," ");
	else
		arg = argv + 1;
	i = 1;
	while (arg[i])
	{
		if (arg[i][0] != '\0')
		{
			new_node = ft_stacknew(ft_atoi(arg[i]);
			if (!new_node)
				return (NULL);
			ft_stackadd_back(&stack,new_node);
		}
		i++;
	}
	assgin_index(stack);
	if (argc == 2)
		free_split(arg);
	return (stack);
}
		
	



		

	
