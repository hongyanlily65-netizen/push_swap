/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 20:32:04 by hohu              #+#    #+#             */
/*   Updated: 2026/03/17 17:28:59 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *lst)
{
	t_stack	*last;

	if (lst == NULL)
		return (NULL);
	last = lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

int	ft_stacksize(t_stack *lst)
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

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
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
