/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:08 by ebansse           #+#    #+#             */
/*   Updated: 2025/02/05 13:32:30 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*smallest(t_node **stack)
{
	t_node *tmp;
	t_node	*small;

	tmp = *stack;
	small = tmp;
	while (tmp)
	{
		if (tmp->value < small->value)
			small = tmp;
		tmp = tmp->next;
	}
	return (small);
}

t_node	*bigest(t_node **stack)
{
	t_node *tmp;
	t_node	*big;

	tmp = *stack;
	big = tmp;
	while (tmp)
	{
		if (tmp->value > big->value)
			big = tmp;
		tmp = tmp->next;
	}
	return (big);
}

void	min_on_top(t_node **stack, t_node *node)
{
	int		median;
	int		i;
	t_node	*last;

	last = ft_last_node(*stack);
	i = node->index;
	median = (last->index + 1) / 2;
	if (node->index < median)
	{
		while (i > 0)
		{
			ra(stack);
			i--;
		}
	}
	else
		while (i <= last->index)
		{
			rra(stack);
			i++;
		}
}

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

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	t_node	*small;
	int		i;

	i = 0;
	while (i < 2)
	{
		small = smallest(stack_a);
		min_on_top(stack_a, small);
		pb(stack_a, stack_b);
		maj_index(*stack_a, *stack_b);
		print_stacks(*stack_a, *stack_b);
		i++;
	}
	sort_3(stack_a);
	maj_index(*stack_a, *stack_b);
	print_stacks(*stack_a, *stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	maj_index(*stack_a, *stack_b);
	print_stacks(*stack_a, *stack_b);
}
