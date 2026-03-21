/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:07:52 by hohu              #+#    #+#             */
/*   Updated: 2026/03/21 20:07:30 by aykhan-i         ###   ########.fr       */
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

typedef struct s_bench
{
	int				disorder;
	char			*strat;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_bench;

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
	int				bench;
	int				mode_set;
}					t_config;

/* ---- init_bench.c ---- */
t_bench				init_bench(void);
void				print_bench(t_bench *bench);

/* ---- init_config.c ---- */
t_config			*init_config(void);

/* ---- main.c ---- */
int					input_check(int *argc, char **argv, t_config *config);
int					handle_flags(const char *arg, t_config *config);
int					parse_flags(int *argc, char **argv, t_config *config);

/* ---- parse.c ---- */
char				*get_str(char **argv);
int					check_args(int argc, char **argv);

/* ---- parse_utils.c ---- */
void				free_split(char **res);
long int			ft_atol(const char *nptr);
int					is_number(char *str);

/* ---- stack_utils.c ---- */
t_stack				*ft_stacklast(t_stack *lst);
int					ft_stacksize(t_stack *lst);
void				ft_stackclear(t_stack **lst);
void				ft_stackadd_back(t_stack **lst, t_stack *new_node);

/* ---- stack_init.c ---- */
t_stack				*ft_stacknew(int nbr);
t_stack				*stack_init(int argc, char **argv);

/* ---- index.c ---- */
t_stack				*find_min_ptr(t_stack *stack);
void				assign_index(t_stack *stack);

/* ---- instrucciones_swap.c ---- */
void				ft_swap(t_stack **stack);
void				swap_sa(t_stack **stackA, t_bench *bench);
void				swap_sb(t_stack **stackB, t_bench *bench);
void				swap_ss(t_stack **stackA, t_stack **stackB, t_bench *bench);

/* ---- instrucciones_push.c ---- */
void				push_pa(t_stack **stackA, t_stack **stackB, t_bench *bench);
void				push_pb(t_stack **stackA, t_stack **stackB, t_bench *bench);

/* ---- instrucciones_rotate.c ---- */
void				ft_rotate(t_stack **stack);
void				rotate_ra(t_stack **stackA, t_bench *bench);
void				rotate_rb(t_stack **stackB, t_bench *bench);
void				rotate_rr(t_stack **stackA, t_stack **stackB,
						t_bench *bench);

/* ---- instrucciones_reverse.c ---- */
void				ft_reverse(t_stack **stack);
void				reverse_rra(t_stack **stackA, t_bench *bench);
void				reverse_rrb(t_stack **stackB, t_bench *bench);
void				reverse_rrr(t_stack **stackA, t_stack **stackB,
						t_bench *bench);

/* ----Selection sort.c ---- */
int					is_stack_sorted(t_stack *stack);
void				selection_sort(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench);

/* ---- chunk_sort.c ---- */
int					get_blocks(int size);
void				push_back_to_a(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench);
void				chunk_sort(t_stack **stack_A, t_stack **stack_B,
						t_bench *bench);

/* ---- radix_sort.c ---- */
int					get_max_bits(t_stack *stack);
void				radix_sort(t_stack **stack_A, t_stack **stack_B,
						t_bench *bench);

/* ---- utils_sort.c ---- */
int					find_max_index(t_stack *stack);
int					find_position(t_stack *stack, int value);
int					find_min_pos(t_stack *stack);

/* ---- free.c ---- */
void				recursive_free(t_stack *head);
void				free_all(t_stack **a, t_stack **b, t_bench *bench,
						t_config *config);

/* ---- disorder_indice.c ---- */
int					compute_disorder(t_stack *stack);

#endif
