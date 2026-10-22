/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:17:01 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/22 10:56:53 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(t_node **stack)
{
    if (!stack || !*stack)
        return ;
    *stack = (*stack)->next;
}

void    rev_rotate(t_node **stack)
{
    if (!stack || !*stack)
        return ;
    *stack = (*stack)->prev;
}

void    swap(t_node **stack)
{
    int  temp;
    if (!stack || !*stack)
        return ;
    temp = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = temp;
}

void    push(t_node **src_stack, t_node **dest_stack)
{
    t_node *src_head;
    if (!src_stack || !*src_stack || !dest_stack)
        return ;
    src_head = *src_stack;
    if ((*src_stack)->next == *src_stack)
        *src_stack = NULL;
    else{
        src_head->prev->next = src_head->next;
        src_head->next->prev = src_head->prev;
        *src_stack = src_head->next;
    }
    ft_add_node_back(dest_stack, src_head);
    *dest_stack = src_head;
}