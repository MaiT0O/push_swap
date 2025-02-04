/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:08 by ebansse           #+#    #+#             */
/*   Updated: 2025/02/04 18:30:45 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **node)
{
	t_node	*tmp;

	tmp = *node;
	while ((tmp) && (tmp)->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

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
		if (tmp->prev)
			tmp->index = tmp->prev->index + 1;
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
		if (tmp->prev)
			tmp->index = tmp->prev->index + 1;
		tmp = tmp->next;
	}
	return (big);
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
		ft_printf("first node = [%d] %d\n", (*stack_a)->index, (*stack_a)->value);
		pb(stack_a, stack_b);
		i++;
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);		
}

void	min_on_top(t_node **stack, t_node *node)
{
	int		median;
	int		i;
	t_node	*last;
	
	last = ft_last_node(*stack);
	i = last->index;
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

void	sort(t_node **stack_a, t_node **stack_b)
{
	int	stack_size;

	if (is_sorted(stack_a))
	{
		ft_printf("already sorted ;)");
		return ;
	}
	stack_size = get_stack_size(*stack_a);
	if (stack_size == 2)
		sa(stack_a);
	else if (stack_size == 3)
		sort_3(stack_a);
	else if (stack_size == 5)
	{
		sort_5(stack_a, stack_b);
	}
}