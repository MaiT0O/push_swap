/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkey_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:50:09 by ebansse           #+#    #+#             */
/*   Updated: 2025/02/18 16:50:55 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_cost(t_node *node, t_node *stack_b, t_lib *lib)
{
    if (!node || !stack_b || !lib)
    {
		ft_printf("error: node, stack_b, or lib is NULL\n");
        return (-1);
    }
	lib->index_b = closest_higher(node, stack_b);
	if (is_smallest(node, stack_b))
	{
		if (node->index <= lib->median_a)
			return (node->index + 2);
		else
			return ((lib->size_a - node->index) + 2);
	}
    ft_printf("index_insert_b returned: %d\n", lib->index_b);

    ft_printf("node->index: %d, lib->size_b : %d, lib->median_a: %d, lib->median_b: %d\n", node->index, lib->size_b, lib->median_a, lib->median_b);

    if (node->index <= lib->median_a && lib->index_b <= lib->median_b)
    {
        ft_printf("Condition: node->index <= lib->median_a && lib->index_b <= lib->median_b\n");
        if (node->index > lib->index_b)
            return (node->index + 1);
        else
            return (lib->index_b + 1);
    }
    else if (node->index > lib->median_a && lib->index_b > lib->median_b)
    {
        ft_printf("Condition: node->index > lib->median_a && lib->index_b > lib->median_b\n");
        if (node->index < lib->index_b)
            return ((lib->size_a - node->index) + 1);
        else
            return ((lib->size_b - lib->index_b) + 1);
    }
    else if (node->index <= lib->median_a && lib->index_b > lib->median_b)
    {
        ft_printf("Condition: node->index <= lib->median_a && lib->index_b > lib->median_b\n");
        return ((node->index + (lib->size_b - lib->index_b)) + 1);
    }
    else if (node->index > lib->median_a && lib->index_b <= lib->median_b)
    {
        ft_printf("Condition: node->index > lib->median_a && lib->index_b <= lib->median_b\n");
        return ((lib->index_b + (lib->size_a - node->index)) + 1);
    }
	ft_printf("error: no condition met\n");
    return (-1);
}

t_node *best_node(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
    t_node *tmp;
    t_node *target;
    int		cost;
    int		cost2;

    tmp = *stack_a;
    cost = INT_MAX;
    while (tmp)
    {
        ft_printf("Calculating cost for node [%d]\n", tmp->value);
        cost2 = node_cost(tmp, *stack_b, lib);
        ft_printf("noeud [%d] / cout : %d / index insert : %d\n\n", tmp->value, cost2, lib->index_b);
        if (cost2 < cost)
        {
            target = tmp;
            cost = cost2;
        }
        tmp = tmp->next;
    }
    return (target);
}

void	sort_all(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	t_node	*tmp;
	t_node	*target;
	int		index;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	maj_index(stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
	if (is_sorted(stack_b))
		sb(stack_b);
	maj_size(lib, *stack_a, *stack_b);
	maj_index(stack_a, stack_b);
	tmp = *stack_a;
	while (tmp && lib->size_a > 3)
	{
		ft_printf("size_a : %d\n", lib->size_a);
		target = best_node(stack_a, stack_b, lib);
		lib->index_b = closest_higher(target, *stack_b);
		ft_printf("best node : %d / target index : %d\n", target->value, target->index);
		tmp = tmp->next;
		insert(target, stack_a, stack_b, lib);
		maj_size(lib, *stack_a, *stack_b);
		maj_index(stack_a, stack_b);
		move_node_to_top_b(stack_b, bigest(stack_b)->index, lib);
		maj_index(stack_a, stack_b);
		print_stacks(*stack_a, *stack_b);
		ft_printf("Next tmp: %p, size_a: %d\n", (void*)tmp, lib->size_a);
	}
	sort_3(stack_a);
	tmp = *stack_b;
	while (tmp && lib->size_b > 0)
	{
		maj_index(stack_a, stack_b);
		index = closest_higher(tmp, *stack_a);
		ft_printf("closest higher in a : %d\n", target->value);
		tmp = tmp->next;
		move_node_to_top_a(stack_a, index, lib);
		pa(stack_a, stack_b);
		lib->size_a++;
		lib->size_b--;
		maj_index(stack_a, stack_b);
		print_stacks(*stack_a, *stack_b);
	}
	while (!is_sorted(stack_a))
		ra(stack_a);
}/*
		while (target->index < lib->size_a)
		{
			rra(stack_a);
			target->index++;
		}
		pa(stack_a, stack_b);
		maj_index(stack_a, stack_b);
		tmp = tmp->next;
	}
}*/

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
        if (node->index < lib->index_b)
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
    if (is_smallest(node, stack_b))
    {
        if (node->index <= lib->median_a)
            return (node->index + 2);
        else
            return ((lib->size_a - node->index) + 2);
    }
    return (calculate_cost(node, lib));
}

void	sort_all_finish(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	t_node	*tmp;
	t_node	*target;
	int		index;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (is_sorted(stack_b))
		sb(stack_b);
	maj_size(lib, *stack_a, *stack_b);
	maj_index(stack_a, stack_b);
	tmp = *stack_a;
	while (tmp && lib->size_a > 3)
	{
		target = best_node(stack_a, stack_b, lib);
		tmp = tmp->next;
		insert(target, stack_a, stack_b, lib);
		maj_size(lib, *stack_a, *stack_b);
		maj_index(stack_a, stack_b);
	}
	sort_3(stack_a);
	tmp = *stack_b;
	move_node_to_top_b(stack_b, bigest(stack_b)->index, lib);
	maj_index(stack_a, stack_b);
	while (tmp && lib->size_b > 0)
	{
		index = closest_higher(tmp, *stack_a);
		tmp = tmp->next;
		move_node_to_top_a(stack_a, index, lib);
		pa(stack_a, stack_b);
		lib->size_a++;
		lib->size_b--;
		maj_index(stack_a, stack_b);
	}
	move_node_to_top_a(stack_a, smallest(stack_a)->index, lib);
}
