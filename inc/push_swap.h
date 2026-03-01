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

typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack	*next;
}	t_stack;
typedef enum e_strategy
{
	MODE_ADAPTIVE;
	MODR_SIMPLE;
	MODE_MEDIUM;
	MODE_COMPLEX;
}	t_strategy;
	
typedef struct s_config
{
	t_strategy strat;
}	t_config;
//parse
void	free_split(char **res);
t_stack	*parse_args_split(char **res);
t_stack	*parse_args(int argc, char **argv);
long int	atol(const char *nptr);
void	error_free(t_stack **stack);
int	ft_is_number(char *str);
int	ft_is_duplicated(t_stack *stack, int nbr);
t_stack	*parse_array(char **res, int start);
//stack utils
int	ft_stacksize(t_stack *lst);
void	ft_stackclear(t_stack **lst);
void	ft_stackadd_back(t_stack **lst, t_stack *new_node);
t_stack	*ft_stacknew(int nbr);
char	**ft_split(char const *s, char c);

# endif
