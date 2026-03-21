/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:32:47 by hohu              #+#    #+#             */
/*   Updated: 2026/01/18 21:32:51 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (lst == NULL)
		return (NULL);
	last = lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}
/*
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tail;

	tail = *lst;
	while (tail->next)
		tail = tail->next;
	tail->next = new;
	new->next = NULL;
}


t_list	*new_node(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;

	return (new);
}

void	print_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("%s->", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf(" NULL\n");
}

int	main(int argc, char *argv[])
{
	t_list	*head;
	t_list	*tail;
	t_list	*last;
	int			i;
	i = 1;
	head = NULL;
	tail = NULL;
	while (argv[i] != NULL)
	{
		if (head == NULL)
			head = new_node(argv[i]);
		else
		{
			tail = new_node(argv[i]);
			ft_lstadd_back(&head, tail);
		}
		i++;
	}
	print_list(head);
	last = ft_lstlast(head);
	print_list(ft_lstlast(head));		
	return (0);
}
*/
