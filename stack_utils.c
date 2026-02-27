/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 20:32:04 by hohu              #+#    #+#             */
/*   Updated: 2026/02/25 20:01:58 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int ft_lstsize(t_list *lst)
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
void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	if	(!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free (*lst);
		*lst = tmp;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last;
	
	last = *lst;
	if (!lst || !new_node)
		return ;//
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
	
t_list	*ft_lstnew(int nbr)
{
	t_list	*node;
	
	node = malloc (sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = nbr;
	node->next = NULL;
	return (node);
}

	
	



		

	
