/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkey_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:50:09 by ebansse           #+#    #+#             */
/*   Updated: 2025/02/10 16:35:43 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_cost(t_node *node, t_node *stack_a, t_node *stack_b)
{
	int	index_b;
	int	index_a;
	int	cost;

	index_b = -1;
	index_a = -1;
	cost = 0;
	while (stack_b)
	{
		if (node->value > stack_b->value)
			index_b = stack_a->index;
		stack_b = stack_b->next;
	}
	if (index_b == -1)
		cost += 2;	
	
}
