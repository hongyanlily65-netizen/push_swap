/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:30:35 by hohu              #+#    #+#             */
/*   Updated: 2026/03/17 17:32:30 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void	del(void *content)
{
	free(content);
}
/*
int	main(void)
{
	t_list	*node;
	char	*s;

	s = ft_strdup("hello");
	node = ft_lstnew(s);

	printf("before: %s\n", (char*)node->content);

	ft_lstdelone(node, del);

	node = NULL;

	printf("after: node= %p\n", (void *)node);
	return (0);
}*/
