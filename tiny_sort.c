/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:08 by ebansse           #+#    #+#             */
/*   Updated: 2025/02/17 13:43:44 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_node **stack)
{
	t_node	*tmp;
	tmp = *stack;

    if (tmp->value > tmp->next->value && tmp->next->value <
		tmp->next->next->value && tmp->value < tmp->next->next->value) // (2 1 3) -> swap
        sa(stack);
    else if (tmp->value > tmp->next->value && tmp->next->value >
		tmp->next->next->value) // (3 2 1) -> swap + reverse rotate
    {
        sa(stack);
        rra(stack);
    }
    else if (tmp->value > tmp->next->value && tmp->next->value <
		tmp->next->next->value && tmp->value > tmp->next->next->value) // (3 1 2) -> rotate
        ra(stack);
    else if (tmp->value < tmp->next->value && tmp->next->value >
		tmp->next->next->value && tmp->value < tmp->next->next->value) // (1 3 2) -> swap + rotate
    {
        sa(stack);
        ra(stack);
    }
    else if (tmp->value < tmp->next->value && tmp->next->value >
		tmp->next->next->value && tmp->value > tmp->next->next->value) // (2 3 1) -> reverse rotate
        rra(stack);
}

void	sort_5(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	t_node	*small;
	int		i;
	int		push;

	i = 0;
	push = lib->size_a - 3;
	while (i < push)
	{
		small = smallest(stack_a);
		move_node_on_top_a(stack_a, small->index, lib);
		pb(stack_a, stack_b);
		maj_index(stack_a, stack_b);
		maj_size(lib, *stack_a, *stack_b);
		print_stacks(*stack_a, *stack_b);
		i++;
	}
	sort_3(stack_a);
	maj_index(stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
	i = 0;
	while (i < push)
	{
		pa(stack_a, stack_b);
		i++;
	}
	maj_index(stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
}
