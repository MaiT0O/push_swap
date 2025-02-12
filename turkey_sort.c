/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkey_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:50:09 by ebansse           #+#    #+#             */
/*   Updated: 2025/02/12 18:29:10 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_insert_b(t_node *node, t_node *stack_b)
{
	t_node	*tmp;
	int		index_b;

	index_b = -1;
	tmp = stack_b;
	while (tmp)
	{
		if (node->value > tmp->value)
			index_b = tmp->index;
		tmp = tmp->next;
	}
	if (index_b == -1)
		index_b = get_stack_size(stack_b);
	return (index_b);
}

int	cost_case(t_node *node, t_lib *lib)
{
	int	cost;

	cost = 0;
	if (lib->index_b == lib->size_b)
	{
		if (node->index <= lib->median_a)
			cost = node->index + 1;
		else
			cost = lib->median_a + 1;
	}
	return (cost);
}

int	node_cost(t_node *node, t_node *stack_a, t_node *stack_b, t_lib *lib)
{
	int	cost;

	lib->index_b = index_insert_b(node, stack_b);
	if ((cost = cost_case(node, lib)) != 0)
		return (cost);
	else if (node->index <= lib->median_a && lib->index_b <= lib->median_b)
	{
		if (node->index > lib->index_b)
			cost = node->index;
		else
			cost = lib->index_b;
	}
	else if (node->index > lib->median_a && lib->index_b > lib->median_b)
	{
		if (node->index < lib->index_b)
			cost = lib->size_a - node->index;
		else
			cost = lib->size_b - lib->index_b;
	}
	else if (node->index <= lib->median_a && lib->index_b > lib->median_b)
		cost = node->index + (lib->size_b - lib->index_b);
	else if (node->index > lib->median_a && lib->index_b <= lib->median_b)
		cost = lib->index_b + (lib->size_a - node->index);
	return (cost);
}

void	insert(t_node *node, t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	int	index_min;
	int	index_max;

	if (lib->index_b < node->index)
		index_min = lib->index_b;
	else
		index_min = node->index;

	if (lib->index_b <= lib->median_b && node->index <= lib->median_a)
	{
		while (index_min > 0)
		{
			rr(stack_a, stack_a);
			index_min--;
		}
	}
	else if (lib->index_b > lib->median_b && node->index > lib->median_a)
	{
		while (index_min > 0)
		{
			rrr(stack_a, stack_a);
			index_min--;
		}
	}
}

void	sort_all(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	t_node	*tmp;
	t_node	*target;
	int		cost;
	int		cost2;

	tmp = *stack_a;
	cost = 0;
	while (tmp)
	{
		cost2 = node_cost(tmp, *stack_a, *stack_b, lib);
		if (cost2 < cost || cost == 0)
		{
			target = tmp;
			cost = cost2;
		}
		tmp = tmp->next;
	}
	lib->index_b = index_insert_b(target, *stack_b);
	

	
}
