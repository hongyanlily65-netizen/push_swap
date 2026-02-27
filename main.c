/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:32:30 by hohu              #+#    #+#             */
/*   Updated: 2026/02/24 18:39:20 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**res;
	
	a = NULL;
	b = NULL;
	res = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		res = ft_split(argv[1], ' ');
		if (!res)
			return(1);
		a = parse_args_split(res);
	}
	else
		a = parse_args(argc, argv)
	if(!a)
	{
		ft_cleaner(res);
		return (1);
	}
	return (0);
}
/*		
	if len_stack(a) < 10//implement bubble sort
	else if len_stack(a) < 300//implement chunk sort
	{
		assign_index(a);
		range_sort(a, b);//everything is in b now, rotate b and push the biggest_node to list a until nothing in b.
		while (b)
		{
			finish_rotation(&b, find_biggest(b),'b');//rb/rrb the first biggest_node is on the top
			pa(a, b);//push the biggest_node to a
		}
	}
	else
	{
	
	return (0);
}
*/			
