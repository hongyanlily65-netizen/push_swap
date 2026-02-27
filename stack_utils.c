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
	while (*lst);
	{
		tmp = *lst->next;
		free (*lst);
		*lst = tmp;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;
	
	last = *lst;
	if (!lst|| !new)
		
		
	while (last->next)
		last = last->next;
	last->next = new;
	new->next = NULL;

	
t_list	*ft_lstnew(int *nbr)
{
	t_list	*node;
	
	node = malloc (sizeof(t_list));
	if (!node)
		return (NULL);
	node->valor = nbr;
	node->next = NULL;
	return (new_node);
}


int	append(t_list **lst, void *content)
{
	t_list	*new;

	if (!lst || !content)
		return (0);
 	new = lstnew(content);
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	ft_lstadd_back(lst, new)
	return (0);
}
		
	
	



		

	
