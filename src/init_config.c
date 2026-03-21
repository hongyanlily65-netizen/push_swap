/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:13:36 by hohu              #+#    #+#             */
/*   Updated: 2026/03/14 22:49:40 by aykhan-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_config	*init_config(void)
{
	t_config	*config;

	config = (t_config *)malloc(sizeof(t_config));
	if (!config)
		return (NULL);
	config->mode = MODE_ADAPTIVE;
	config->mode_set = 0;
	return (config);
}
