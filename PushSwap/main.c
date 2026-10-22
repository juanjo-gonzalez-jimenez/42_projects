/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:17:19 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/22 11:39:29 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(char *label, t_node *head)
{
	t_node	*current;

	printf("%s: ", label);
	if (!head)
	{
		printf("(empty)\n");
		return ;
	}
	current = head;
	while (1)
	{
		printf("%d", current->value);
		current = current->next;
		if (current == head)
			break ;
		printf(" ");
	}
	printf("\n");
}

void	print_stack_rev(char *label, t_node *head)
{
	t_node	*start;
	t_node	*current;

	printf("%s rev: ", label);
	if (!head)
	{
		printf("(empty)\n");
		return ;
	}
	start = head->prev;
	current = start;
	while (1)
	{
		printf("%d", current->value);
		current = current->prev;
		if (current == start)
			break ;
		printf(" ");
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_node *head_a;
	t_node *head_b;
	int i;

	if (argc < 2)
		return (0);
	head_a = NULL;
	head_b = NULL;
	i = 1;
	while (i < argc)
	{
		int value = ft_atoi(argv[i]);
		t_node *new_node = ft_create_node(value);
		if (!new_node)
		{
			free_list(&head_a);
			return (1);
		}
		ft_add_node_back(&head_a, new_node);
		i++;
	}
	swap(&head_a);
	print_stack("a", head_a);
	print_stack("b", head_b);
	swap(&head_a);
	print_stack("a", head_a);
	print_stack("b", head_b);
	free_list(&head_a);
	return (0);
}