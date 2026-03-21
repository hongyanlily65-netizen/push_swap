/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:31:47 by hohu              #+#    #+#             */
/*   Updated: 2026/01/18 21:31:52 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
t_list	*new_node(void *value)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content =  value;
	new->next = NULL;

	return (new);
}

void	print_list(t_list *stack)
{
	t_list *temp;

	temp = stack;
	while (temp)
	{
		printf("%s ->", (char *)temp->content);
		temp = temp->next;
	}
	printf(" NULL\n");
}
int	main()
{
	t_list *head;
	t_list	*new;
	char *str = "123";
	head = new_node(str);
	print_list(head);
	new = new_node("567");

	ft_lstadd_front(&head, new);

	print_list(head);
	
	return (0);
}*/
