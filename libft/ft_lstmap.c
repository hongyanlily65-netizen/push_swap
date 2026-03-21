/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:42:13 by hohu              #+#    #+#             */
/*   Updated: 2026/03/17 17:33:09 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*new_content;
	t_list	*new_node;
	t_list	*new_list;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
void	*f(void *node)
{
	int	*n;

	n = (int *)node;
	*n = (*n) * 2;
	return (n);
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
	t_list	*lst = NULL;

	i = 0;
	while (i < (int)(sizeof(arr) / sizeof(arr[0])))
	{
		int *p = malloc(sizeof(int));
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
	t_list	*new_lst;

	new_lst=ft_lstmap(lst, f, del);
	print_list(new_lst);
	ft_lstclear(&new_lst,del);
	return(0);
}*/
