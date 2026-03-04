/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:13:36 by hohu              #+#    #+#             */
/*   Updated: 2026/03/04 22:14:05 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_config	*init_config(void)
{
	t_config	*config;

	config = (t_config *)malloc(sizeof(t_config *));
	return (config);
}
