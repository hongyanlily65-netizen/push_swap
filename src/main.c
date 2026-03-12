/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:32:30 by hohu              #+#    #+#             */
/*   Updated: 2026/02/28 14:17:46 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_check(int *argc, char **argv,t_config *config)
{
	if(!parse_flags(argc, argv, config))
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

int	handle_flags(const char *arg, t_config *config)
{
	if (!ft_strncmp("--adaptive", arg, 11) && ft_strlen(arg) == 10)
		return (config->mode = MODE_ADAPTIVE, 1);
	else if (!ft_strncmp("--simple", arg, 9) && ft_strlen(arg) == 8)
		return (config->mode = MODE_SIMPLE, 1);
	else if (!ft_strncmp("--medium", arg, 9) && ft_strlen(arg) == 8)
		return (config->mode = MODE_MEDIUM, 1);
	else if (!ft_strncmp("--complex", arg, 10) && ft_strlen(arg) == 9)
		return (config->mode = MODE_COMPLEX, 1);
	else
		return (0);
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
			if(!handle_flags(argv[i], config))
				return (0);
			argv[i] = "";
			*argc -= 1;
		}
		i++;
	}
	return (1);
}

static void	sort(t_stack **a, t_stack **b, t_config *config)
{
	int	disorder;
	
	disorder = compute_disorder(*a);
	if (config ->mode ==MODE_ADAPTIVE)
	{
		if(disorder < 2000)
			 bubble_sort(a);
		else if(
			(disorder >= 2000 && disorder <= 5000) || ft_stacksize(*a) < 150)
			chunk_sort(a, b);
		else
			radix_sort(a,b);
	}
	else if (config->mode == MODE_SIMPLE)
		selection_sort(a,b);
	else if (config->mode ==MODE_MEDIUM)
		chunk_sort(a,b);
	else if (config->mode ==MODE_COMPLEX)
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_config	*config;
	
	config = init_config();
	if(!input_check(&argc, argv, config))
		return (1);
	a = stack_init(argc, argv);
	b = NULL;
	sort (&a, &b, config);
	if (!a)
		return (1);
	free_all(a, b, config);
	return (0);
}			
