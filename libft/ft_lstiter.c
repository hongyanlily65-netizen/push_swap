/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:35:38 by hohu              #+#    #+#             */
/*   Updated: 2026/03/17 17:32:49 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
/*
void	f(void *node)
{
	int	*n;

	n = (int *)node;
	*n = (*n) * 2;
}

static void	del(void *content)
{
	free(content);
}

void	print_list(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		printf("%d->", *(int *)temp->content);
		temp = temp->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	int	arr[] = {1, 2, 3};
	int	i;
	int	*p;
	t_list	*lst = NULL;

	i = 0;
	while (i < (int)(sizeof(arr) / sizeof(arr[0])))
	{
		p = malloc(sizeof(int));
		if (!p)
		{
			ft_lstclear(&lst,del);
			return(1);
		}
		*p = arr[i];

		t_list *node = ft_lstnew(p);
		if(!node)
		{
			free(p);
			ft_lstclear(&lst, del);
			return(1);
		}
		ft_lstadd_back(&lst, node);
		i++;
	}
	print_list(lst);
	ft_lstiter(lst,f);
	print_list(lst);
	ft_lstclear(&lst,del);
	return(0);
}*/
