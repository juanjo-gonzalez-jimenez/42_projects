/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:17:01 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/21 18:41:35 by juan-jos         ###   ########.fr       */
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
    if (!*src_stack)
        return ;
    src_head = *src_stack;
}