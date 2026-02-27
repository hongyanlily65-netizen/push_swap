/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:07:52 by hohu              #+#    #+#             */
/*   Updated: 2026/02/22 14:13:39 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_list
{
	int	value;
	int	index;
	struct s_list	*next;
}	t_list;

void	ft_cleaner(char **res);
t_list	*parse_args_split(char **res);
t_list	*parse_args(int argc, char **argv);
long	atol(char *s);
void	error_free(t_list **stack);
int	ft_is_number(char *str);
int	ft_is_duplicated(t_list *stack, int nbr);
t_list	*parse_array(char **res, int start);
//stack
int	ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst);
t_list	*ft_lstnew(int *nbr);
int	append(t_list **lst, void *content);
# endif
