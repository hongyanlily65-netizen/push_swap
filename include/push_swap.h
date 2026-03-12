/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:07:52 by hohu              #+#    #+#             */
/*   Updated: 2026/03/11 22:49:57 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;
typedef enum e_strategy
{
	MODE_ADAPTIVE,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX,
}					t_strategy;

typedef struct s_config
{
	t_strategy		mode;
}					t_config;
t_config			*init_config(void);

// main
int					input_check(int *argc, char **argv, t_config *config);
int					handle_flags(const char *arg, t_config *config);
int					parse_flags(int *argc, char **argv, t_config *config);

// parse
void				free_split(char **res);
int					check_args(int argc, char **argv);
long int			ft_atol(const char *nptr);
char				*get_str(char **argv);
int					is_number(char *str);

// stack utils
t_stack				*ft_stacklast(t_stack *lst)
int					ft_stacksize(t_stack *lst);
void				ft_stackclear(t_stack **lst);
void				ft_stackadd_back(t_stack **lst, t_stack *new_node);
t_stack				*ft_stacknew(int nbr);
t_stack				*stack_init(int argc, char **argv);

// index
t_stack				*find_min_ptr(t_stack *stack);
void				assign_index(t_stack *stack);

// Instruciones
void				ft_swap(t_stack **stack);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ft_rotate(t_stack **stack);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				ft_reverse(t_stack **stack);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// sort
void				bubble_sort(t_stack **stack);
void				radix_sort(t_stack **stack_A, t_stack **stack_B);
void				chunk_sort(t_stack **stack_A, t_stack **stack_B);

// utils sort
int					find_min_pos(t_stack *stack);
int					find_max_index(t_stack *stack);
int					find_position(t_stack *stack, int value);
int					is_stack_sorted(t_stack **stack);
int					get_max_bits(t_stack *stack);
int					get_blocks(int size);
void				push_back_to_a(t_stack **stack_a, t_stack **stack_b);

#endif
