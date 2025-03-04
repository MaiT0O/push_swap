/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:33:56 by ebansse           #+#    #+#             */
/*   Updated: 2025/03/04 12:47:15 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	not_seen(t_node *stack, int value)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_node	*smallest(t_node **stack)
{
	t_node	*tmp;
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
	t_node	*tmp;
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

int	closest_lower(t_node *target, t_node *stack)
{
	t_node	*current;
	int		best_index;
	int		best_diff;

	if (!stack || !target)
		return (0);
	current = stack;
	best_index = 0;
	best_diff = INT_MAX;
	while (current)
	{
		if (target->value - current->value < best_diff
			&& target->value - current->value > 0)
		{
			best_diff = target->value - current->value;
			best_index = current->index;
		}
		current = current->next;
	}
	return (best_index);
}
