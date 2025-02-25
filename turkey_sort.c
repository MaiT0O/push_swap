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

int	node_cost_finish(t_node *node, t_node *stack_b, t_lib *lib)
{
    if (!node || !stack_b || !lib)
    {
        ft_printf("Error\n");
        return (-1);
    }
    lib->index_b = closest_lower(node, stack_b, lib);
    if (is_smallest(node, stack_b))
    {
        if (node->index <= lib->median_a)
            return (node->index + 2);
        else
            return ((lib->size_a - node->index) + 2);
    }
    return (calculate_cost(node, lib));
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
        /*ft_printf("Calculating cost for node [%d]\n", tmp->value);*/
        cost2 = node_cost_finish(tmp, *stack_b, lib);
        /*ft_printf("noeud [%d] / cout : %d / index insert : %d\n\n", tmp->value, cost2, lib->index_b);*/
        if (cost2 < cost)
        {
            target = tmp;
            cost = cost2;
        }
        tmp = tmp->next;
    }
	/*ft_printf("best node : %d / target index : %d\n", target->value, target->index);*/
    return (target);
}

void	sort_b(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	t_node	*tmp;
	t_node	*target;

	tmp = *stack_a;
	while (tmp && lib->size_a > 3)
	{
		target = best_node(stack_a, stack_b, lib);
		tmp = tmp->next;
		insert(target, stack_a, stack_b, lib);
		maj_size(lib, *stack_a, *stack_b);
		maj_index(stack_a, stack_b);
		/*print_stacks(*stack_a, *stack_b);*/
	}
}

void	sort_a(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	t_node *tmp;
	int		index;

	tmp = *stack_b;
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
}

void	sort_all(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (is_sorted(stack_b))
		sb(stack_b);
	maj_size(lib, *stack_a, *stack_b);
	maj_index(stack_a, stack_b);
	/*print_stacks(*stack_a, *stack_b);*/
	sort_b(stack_a, stack_b, lib);
	sort_3(stack_a);
	move_node_to_top_b(stack_b, bigest(stack_b)->index, lib);
	maj_index(stack_a, stack_b);
	sort_a(stack_a, stack_b, lib);
	maj_index(stack_a, stack_b);
	move_node_to_top_a(stack_a, smallest(stack_a)->index, lib);
}
