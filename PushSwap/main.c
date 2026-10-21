/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:17:19 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/21 18:17:43 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node *head;
	int i;

	if (argc < 2)
		return (0);
	head = NULL;
	i = 1;
	while (i < argc)
	{
		int value = ft_atoi(argv[i]);
		t_node *new_node = ft_create_node(value);
		if (!new_node)
		{
			free_list(&head);
			return (1);
		}
		ft_add_node_back(&head, new_node);
		i++;
	}
	print_list(head);
	free_list(&head);
	return (0);
}