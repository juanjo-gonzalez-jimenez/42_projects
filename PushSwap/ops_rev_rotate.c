/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:07:33 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/23 10:30:40 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	if (!data)
		return ;
	rev_rotate(&data->stack_a);
}

void	rrb(t_data *data)
{
	if (!data)
		return ;
	rev_rotate(&data->stack_b);
}

void	rrr(t_data *data)
{
	if (!data)
		return ;
	rev_rotate(&data->stack_a);
	rev_rotate(&data->stack_b);
}
