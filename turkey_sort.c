/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkey_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:50:09 by ebansse           #+#    #+#             */
/*   Updated: 2025/03/04 12:58:33 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(t_node *node, t_lib *lib)
{
	if (node->index <= lib->median_a && lib->index_b <= lib->median_b)
	{
		if (node->index > lib->index_b)
			return (node->index + 1);
		else
			return (lib->index_b + 1);
	}
	else if (node->index > lib->median_a && lib->index_b > lib->median_b)
	{
		if (lib->size_a - node->index > lib->size_b - lib->index_b)
			return ((lib->size_a - node->index) + 1);
		else
			return ((lib->size_b - lib->index_b) + 1);
	}
	else if (node->index <= lib->median_a && lib->index_b > lib->median_b)
		return ((node->index + (lib->size_b - lib->index_b)) + 1);
	else if (node->index > lib->median_a && lib->index_b <= lib->median_b)
		return ((lib->index_b + (lib->size_a - node->index)) + 1);
	ft_printf("Error\n");
	return (-1);
}

int	node_cost_finish(t_node *node, t_node *stack_b, t_lib *lib)
{
	if (!node || !stack_b || !lib)
	{
		ft_printf("Error\n");
		return (-1);
	}
	lib->index_b = closest_lower(node, stack_b);
	if (node->value < smallest(&stack_b)->value)
	{
		if (node->index <= lib->median_a)
			return (node->index + 2);
		else
			return ((lib->size_a - node->index) + 2);
	}
	return (calculate_cost(node, lib));
}

t_node	*best_node(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	t_node	*tmp;
	t_node	*target;
	int		cost;
	int		cost2;

	tmp = *stack_a;
	cost = INT_MAX;
	while (tmp)
	{
		cost2 = node_cost_finish(tmp, *stack_b, lib);
		if (cost2 < cost)
		{
			target = tmp;
			cost = cost2;
		}
		tmp = tmp->next;
	}
	return (target);
}

void	sort_b(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	t_node	*target;

	while (*stack_a)
	{
		target = best_node(stack_a, stack_b, lib);
		lib->index_b = closest_lower(target, *stack_b);
		insert(target, stack_a, stack_b, lib);
		maj_size(lib, *stack_a, *stack_b);
		maj_index(stack_a, stack_b);
	}
}

void	sort_all(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (is_sorted(stack_b))
		sb(stack_b);
	maj_size(lib, *stack_a, *stack_b);
	maj_index(stack_a, stack_b);
	sort_b(stack_a, stack_b, lib);
	move_node_to_top_b(stack_b, bigest(stack_b)->index, lib);
	maj_index(stack_a, stack_b);
	while (lib->size_b > 0)
	{
		pa(stack_a, stack_b);
		lib->size_b--;
	}
}
