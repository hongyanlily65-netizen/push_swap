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
# include <unistd.h>
# include <limits.h>
# include <libft.h>

typedef struct s_list
{
	int	value;
	int	index;
	struct s_list	*next;
}	t_list;
//parse
void	free_split(char **res);
t_list	*parse_args_split(char **res);
t_list	*parse_args(int argc, char **argv);
long int	atol(const char *nptr);
void	error_free(t_list **stack);
int	ft_is_number(char *str);
int	ft_is_duplicated(t_list *stack, int nbr);
t_list	*parse_array(char **res, int start);
//stack utils
int	ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
t_list	*ft_lstnew(int nbr);
char	**ft_split(char const *s, char c);

# endif
