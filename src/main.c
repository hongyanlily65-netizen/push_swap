/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:32:30 by hohu              #+#    #+#             */
/*   Updated: 2026/03/16 23:13:26 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_check(int *argc, char **argv, t_config *config)
{
	if (!parse_flags(argc, argv, config))
	{
		write(2, "Error parsing input\n", 20);
		return (0);
	}
	if (!check_args(*argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	parse_flags(int *argc, char **argv, t_config *config)
{
	int	i;
	int	ac;

	i = 1;
	ac = *argc;
	while (i < ac)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!handle_flags(argv[i], config))
				return (0);
			argv[i] = "";
			*argc -= 1;
		}
		i++;
	}
	return (1);
}

static void	sort(t_stack **a, t_stack **b, t_config *config, t_bench *bench)
{
	int	disorder;

	disorder = compute_disorder(*a);
	bench->disorder = disorder;
	if (disorder == 0)
	{
		bench->strat = ft_strdup("NONE");
		return ;
	}
	if (config->mode == MODE_ADAPTIVE)
	{
		if (disorder < 2000)
			selection_sort(a, b, bench);
		else if (ft_stacksize(*a) <= 500 && disorder < 5000)
			chunk_sort(a, b, bench);
		else
			radix_sort(a, b, bench);
	}
	else if (config->mode == MODE_SIMPLE)
		selection_sort(a, b, bench);
	else if (config->mode == MODE_MEDIUM)
		chunk_sort(a, b, bench);
	else if (config->mode == MODE_COMPLEX)
		radix_sort(a, b, bench);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_config	*config;
	t_bench		bench;

	config = init_config();
	bench = init_bench();
	if (!input_check(&argc, argv, config))
		return (1);
	a = stack_init(argc, argv);
	b = NULL;
	sort(&a, &b, config, &bench);
	if (config->bench)
		print_bench(&bench);
	free_all(&a, &b, &bench, config);
	return (0);
}
