/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:23:54 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/22 10:55:15 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/*Function Prototypes*/
t_node				*ft_create_node(int value);
void				ft_add_node_back(t_node **lst, t_node *new);
void				print_list(t_node *head);
void				free_list(t_node **head);
void				rotate(t_node **stack);
void				rev_rotate(t_node **stack);
void				swap(t_node **stack);
void				push(t_node **src_stack, t_node **dest_stack);
#endif
