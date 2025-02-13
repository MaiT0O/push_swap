/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkey_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:50:09 by ebansse           #+#    #+#             */
/*   Updated: 2025/02/13 16:33:01 by ebansse          ###   ########.fr       */
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

t_node *best_node(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	t_node *tmp;
	t_node *target;
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
	}
	return (target);
}

void	double_r_rotate(t_node *node, t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	while (node->index < lib->size_a && lib->index_b < lib->size_b)
	{
		rrr(stack_a, stack_a);
		node->index++;
		lib->index_b++;
	}
	if (node->index >= lib->size_a && lib->index_b < lib->size_b)
	{
		while (lib->index_b < lib->size_b)
		{
			rrb(stack_b);
			lib->index_b++;
		}
	}
	else if (node->index < lib->size_a && lib->index_b >= lib->size_b)
	{
		while (node->index < lib->size_a)
		{
			rra(stack_a);
			node->index++;
		}
	}
}

void	double_rotate(t_node *node, t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	while (lib->index_b > 0 && node->index > 0)
	{
		rr(stack_a, stack_a);
		lib->index_b--;
		node->index--;
	}
	if (lib->index_b > 0 && node->index <= 0)
	{
		while (lib->index_b > 0)
		{
			rb(stack_b);
			lib->index_b--;
		}
	}
	else if (lib->index_b <= 0 && node->index > 0)
	{
		while (node->index > 0)
		{
			ra(stack_a);
			node->index--;
		}
	}
}

void	insert(t_node *node, t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	if (node->index <= lib->median_a && lib->index_b <= lib->median_b)
		double_rotate(node, stack_a, stack_b, lib);
	else if (node->index > lib->median_a && lib->index_b > lib->median_b)
		double_r_rotate(node, stack_a, stack_b, lib);
}

t_node	*closest_higher_in_a(t_node **stack_a, t_node **stack_b) 
{
    int		target;
    int		min_diff;
	int		diff;
    t_node	*closest;
	t_node	*tmp;

	target = (*stack_b)->value;
	min_diff = INT_MAX;
	closest = NULL;
	tmp = *stack_a;
    while (tmp)
	{
        if (tmp->value > target)
		{
            diff = tmp->value - target;
            if (diff < min_diff)
			{
                min_diff = diff;
                closest = tmp;
            }
        }
        tmp = tmp->next;
    }
    return (closest);
}

void	sort_all(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	t_node	*tmp;
	t_node	*target;

	tmp = *stack_a;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (!is_sorted(stack_b))
		sb(stack_b);
	lib->median_b = (get_stack_size(stack_b) - 1) / 2;
	while (tmp && lib->size_a > 3)
	{
		target = best_node(stack_a, stack_b, lib);
		insert(target, stack_a, stack_b, lib);
		lib->size_a--;
		lib->size_b++;
		maj_index(stack_a, stack_b);
		tmp = tmp->next;
	}
	sort_3(stack_a);
	tmp = *stack_b;
	while (tmp)
	{
		target = closest_higher_in_a(stack_a, stack_b);
		while (target->index < lib->size_a)
		{
			rra(stack_a);
			target->index++;
		}
		pa(stack_a, stack_a);
		maj_index(stack_a, stack_b);
		tmp = tmp->next;
	}
}
