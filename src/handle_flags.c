/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykhan-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:54:10 by aykhan-i          #+#    #+#             */
/*   Updated: 2026/03/21 19:54:11 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_mode_flag(const char *arg, t_config *config)
{
	if (!ft_strncmp("--adaptive", arg, 11) && ft_strlen(arg) == 10)
		config->mode = MODE_ADAPTIVE;
	else if (!ft_strncmp("--simple", arg, 9) && ft_strlen(arg) == 8)
		config->mode = MODE_SIMPLE;
	else if (!ft_strncmp("--medium", arg, 9) && ft_strlen(arg) == 8)
		config->mode = MODE_MEDIUM;
	else if (!ft_strncmp("--complex", arg, 10) && ft_strlen(arg) == 9)
		config->mode = MODE_COMPLEX;
	else
		return (0);
	if (config->mode_set)
		return (0);
	config->mode_set = 1;
	return (1);
}

int	handle_flags(const char *arg, t_config *config)
{
	if (!ft_strncmp("--bench", arg, 8) && ft_strlen(arg) == 7)
		return (config->bench = 1, 1);
	return (handle_mode_flag(arg, config));
}
