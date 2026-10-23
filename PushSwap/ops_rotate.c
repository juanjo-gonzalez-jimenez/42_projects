/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:07:20 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/23 10:30:32 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	if (!data)
		return ;
	rotate(&data->stack_a);
}

void	rb(t_data *data)
{
	if (!data)
		return ;
	rotate(&data->stack_b);
}

void	rr(t_data *data)
{
	if (!data)
		return ;
	rotate(&data->stack_a);
	rotate(&data->stack_b);
}
