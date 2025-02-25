/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:35:37 by ebansse           #+#    #+#             */
/*   Updated: 2025/02/04 15:35:38 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	r_rotate(t_node **stack)
{
	t_node *tail;
    t_node *second_last;

    if (!*stack || !(*stack)->next)
        return;

    tail = *stack;
    second_last = NULL;

    while (tail->next)
    {
        second_last = tail;
        tail = tail->next;
    }

    second_last->next = NULL;
    tail->next = *stack;
    *stack = tail;
    (*stack)->prev = NULL;
}

void	rra(t_node **stack_a)
{
	r_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	r_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	ft_printf("rrr\n");
}
