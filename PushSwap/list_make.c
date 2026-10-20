/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_make.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:19:31 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/20 20:05:43 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_add_node_back(t_node **lst, t_node *new)
{
	t_node	*node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	node = *lst;
	while (node->next != NULL)
		node = node->next;
	node->next = new;
	new->prev = node;
}

int	main(int argc, char **argv)
{
	t_node *head;
	t_node *current;
	t_node *last;
	t_node *temp;
	int i;

	if (argc < 2)
		return (0);
	head = NULL;
	i = 1;
	while (i < argc)
	{
		int value = ft_atoi(argv[i]);
		t_node *new_node = ft_create_node(value);
		ft_add_node_back(&head, new_node);
		i++;
	}
	last = head;
	while (last->next != NULL)
		last = last->next;
	last->next = head;
	head->prev = last;
	current = head;
	while (current)
	{
		printf("%d", current->value);
		printf("\n");
		current = current->next;
		if (current == head)
			break;
	}
	last->next = NULL;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	return (0);
}