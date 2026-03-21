/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:41:39 by hohu              #+#    #+#             */
/*   Updated: 2026/03/17 17:33:33 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*head;
	int		counter;

	head = lst;
	counter = 0;
	while (head)
	{
		head = head->next;
		counter++;
	}
	return (counter);
}

void	ft_printnodes(t_list *head)
{
	while (head)
	{
		printf("%s", (char *)head->content);
		head = head->next;
	}
}

int	main(void)
{
	t_list	*head;

	head = NULL;
	ft_lstadd_front(&head, ft_lstnew("uno"));
	ft_lstadd_front(&head, ft_lstnew("dos"));
	ft_printnodes(head);
	printf("%i", ft_lstsize(head));
}
