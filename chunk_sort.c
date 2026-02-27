/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:57:56 by hohu              #+#    #+#             */
/*   Updated: 2026/02/25 20:00:36 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	assign_index(t_list *stack)
{
	int	size;
	int	smallest;
	int i;
	t_list *smallest_ptr;
	t_list *ptr;
	
	size = lstsize(stack);
	i = 0;
	while (i < size)
	{
		smallest = INT_MAX;
		ptr = stack;
		smallest_ptr = NULL;
		while (ptr)
		{
			if (ptr->value < smallest && ptr->index == -1)
			{
				smallest = ptr->value;
				smallest_ptr = ptr;
			}
			ptr = ptr->next;
		}
		if (smallest_ptr)
			smallest_ptr->index = i;
		i++;
	}
}
int	get_range(int	size)
{
	if (size < 100)
		return (30);
    else 
		return (50);
}
int	above_median(t_list *stack)

void	finish_rotation(t_list **stack, t_list *biggest_node, char stack_name)
{
	while (*stack != biggest_node)
	{
		if (above_median)
		{	
			if(stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack);
			else 
				rrb(stack);
		}
	}
}
				
t_list	*find_biggest(t_list *stack)
{
	int	biggest;
	t_list	biggest_node;
	
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->value > biggest)
			biggest_node = stack;
		stack = stack-> next;
	}
	return (biggest_node);
}
	
void	range_sort(t_list **a, t_list **b)
{	
	
	int	i;
	int j;
	int	range;

	j = 1;
	range = get_range(ft_lstsize(*a));
// count how many loops 
	while (*a)
	{
		i = 0;
		if ((*a)->index <= i)
		{
			pb(b, a);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(b, a);
			i++;
		}
		else
			ra(a);
		
	}
}
			
		
			
