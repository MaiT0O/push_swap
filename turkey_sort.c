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

int	is_smallest(t_node *node, t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value < node->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_biggest(t_node *node, t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value > node->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	index_insert_b(t_node *target, t_node *stack)
{
    t_node  *current;
    int     index;
    int     best_index;
    int     best_diff;

    if (!stack || !target)
        return (0);
    current = stack;
    index = 0;
    best_index = 0;
    best_diff = INT_MAX;
    while (current)
    {
        if (current->value <= target->value)
            return (index);
        if (current->value - target->value < best_diff)
        {
            best_diff = current->value - target->value;
            best_index = index;
        }
        current = current->next;
        index++;
    }
    return (best_index + 1);
}

t_node	*closest_higher_in_a(t_node **stack_a, t_node **stack_b)
{
    int		target;
    int		min_diff;
    int		diff;
    t_node	*closest;
    t_node	*tmp;

    if (!(*stack_b))
    {
        ft_printf("error: stack_a, stack_b, or the first element of stack_b is NULL\n");
        return (NULL);
    }

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

int	node_cost(t_node *node, t_node *stack_b, t_lib *lib)
{
    if (!node || !stack_b || !lib)
    {
		ft_printf("error: node, stack_b, or lib is NULL\n");
        return (-1);
    }
	lib->index_b = index_insert_b(node, stack_b);
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

void	move_node_to_top(t_node **stack, int index, t_lib *lib)
{
    int half_size;

    if (!stack || !lib)
    {
        ft_printf("error: stack, node, or lib is NULL\n");
        return;
    }

    half_size = get_stack_size(*stack) / 2;
    if (index <= half_size)
    {
        while (index > 0)
        {
            ra(stack);
            index--;
        }
    }
    else
    {
        while (index < lib->size_a)
        {
            rra(stack);
            index++;
        }
    }
}

void	double_r_rotate(t_node *node, t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	while (node->index < lib->size_a && lib->index_b < lib->size_b)
	{
		rrr(stack_a, stack_b);
		node->index++;
		lib->index_b++;
	}
	if (node->index == lib->size_a)
	{
		while (lib->index_b < lib->size_b)
		{
			rrb(stack_b);
			lib->index_b++;
		}
	}
	else if (lib->index_b == lib->size_b)
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
		rr(stack_a, stack_b);
		lib->index_b--;
		node->index--;
	}
	if (lib->index_b == 0)
	{
		while (node->index > 0)
		{
			ra(stack_a);
			node->index--;
		}
	}
	else if (node->index == 0)
	{
		while (lib->index_b > 0)
		{
			rb(stack_b);
			lib->index_b--;
		}
	}
}

void	insert(t_node *node, t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	if (!node || !stack_a || !stack_b || !lib)
	{
		ft_printf("error: node, stack_a, stack_b, or lib is NULL\n");
		return ;
	}
	ft_printf("node index : %d / index_b : %d / median_a : %d / median_b : %d\n", node->index, lib->index_b, lib->median_a, lib->median_b);
	if (node->index <= lib->median_a && lib->index_b <= lib->median_b && node->index > 0 && lib->index_b > 0)
		double_rotate(node, stack_a, stack_b, lib);
	else if (node->index > lib->median_a && lib->index_b > lib->median_b)
		double_r_rotate(node, stack_a, stack_b, lib);
	else
	{
		move_node_to_top(stack_a, node->index, lib);
		move_node_to_top(stack_b, lib->index_b, lib);
	}
	pb(stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
}

void	sort_all(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	t_node	*tmp;
	t_node	*target;

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
		lib->index_b = index_insert_b(target, *stack_b);
		ft_printf("best node : %d / target index : %d\n", target->value, target->index);
		tmp = tmp->next;
		insert(target, stack_a, stack_b, lib);
		lib->size_a--;
		lib->size_b++;
		maj_index(stack_a, stack_b);
		print_stacks(*stack_a, *stack_b);
		ft_printf("Next tmp: %p, size_a: %d\n", (void*)tmp, lib->size_a);
	}
	sort_3(stack_a);
	tmp = *stack_b;
	while (tmp && lib->size_b > 0)
	{
		maj_index(stack_a, stack_b);
		target = closest_higher_in_a(stack_a, stack_b);
		ft_printf("closest higher in a : %d\n", target->value);
		tmp = tmp->next;
		move_node_to_top(stack_a, target->index, lib);
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
