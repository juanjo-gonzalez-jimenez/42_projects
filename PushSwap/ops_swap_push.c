/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 09:51:09 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/23 10:30:26 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	if (!data)
		return ;
	swap(&data->stack_a);
}

void	sb(t_data *data)
{
	if (!data)
		return ;
	swap(&data->stack_b);
}

void	ss(t_data *data)
{
	if (!data)
		return ;
	swap(&data->stack_a);
	swap(&data->stack_b);
}

void	pa(t_data *data)
{
	if (!data)
		return ;
	push(&data->stack_b, &data->stack_a);
}

void	pb(t_data *data)
{
	if (!data)
		return ;
	push(&data->stack_a, &data->stack_b);
}
