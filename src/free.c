/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 22:46:13 by hohu              #+#    #+#             */
/*   Updated: 2026/03/12 22:47:19 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	recursive_free(t_stack *head)
{
	t_stack	*tmp;

	if (head == NULL)
		return ;
	if (head->next == head)
	{
		free(head);
		return ;
	}
	tmp = head->next;
	head->next = head->next->next;
	free(tmp);
	recursive_free(head);
}

void	free_all(t_stack *a, t_stack *b, t_config *config)
{
	recursive_free(a);
	recursive_free(b);
	free(config);
}
