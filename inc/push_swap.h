/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:07:52 by hohu              #+#    #+#             */
/*   Updated: 2026/03/04 20:39:40 by hohu             ###   ########.fr       */
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
	MODE_ADAPTIVE,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX,
}	t_strategy;
	
typedef struct s_config
{
	t_strategy mode;
}	t_config;
t_config	*init_config(void);
//main
int	input_check(int *argc, char **argv,t_config *config);
int	handle_flags(const char *arg, t_config *config);
int	parse_flags(int *argc, char **argv, t_config *config);
//parse
void	free_split(char **res);
int	check_args(int argc,  char **argv);
long int	ft_atol(const char *nptr);
char *get_str(char **argv);
int	is_number(char *str);
//stack utils
int	ft_stacksize(t_stack *lst);
void	ft_stackclear(t_stack **lst);
void	ft_stackadd_back(t_stack **lst, t_stack *new_node);
t_stack	*ft_stacknew(int nbr);
t_stack *stack_init(int argc, char **argv);
//index
t_stack *find_min_ptr(t_stack *stack);
void	assign_index(t_stack *stack);
# endif
