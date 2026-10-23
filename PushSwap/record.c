/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 13:24:24 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/23 15:33:15 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_data(t_data *data)
{
	if (!data)
		return (0);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->capacity = 1024;
	data->n_ops = 0;
	data->ops = malloc(sizeof(t_op)*data->capacity);
	if (!data->ops)
		return (0);
	return (1);
}

int	record(t_data *data, t_op op)
{
	t_op	*new_ops;

	if (data->n_ops == data->capacity)
	{
		new_ops = malloc(sizeof(t_op) * (data->capacity * 2));
		if (!new_ops)
			return (0);
		ft_memcpy(new_ops, data->ops, data->capacity * sizeof(t_op));
		free(data->ops);
		data->ops = new_ops;
		data->capacity = data->capacity * 2;
	}
    data->ops[data->n_ops] = op;
    data->n_ops++;
	return (1);
}
