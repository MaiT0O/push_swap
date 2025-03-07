/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:54:40 by ebansse           #+#    #+#             */
/*   Updated: 2025/03/04 12:46:07 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_stack_size(t_node *stack)
{
	t_node	*tmp;
	int		size;

	if (!stack)
		return (0);
	tmp = stack;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	update_index(t_node **stack)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
}

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

void	maj_size(t_lib *lib, t_node *stack_a, t_node *stack_b)
{
	lib->size_a = get_stack_size(stack_a);
	lib->size_b = get_stack_size(stack_b);
	lib->median_a = (lib->size_a - 1) / 2;
	lib->median_b = (lib->size_b - 1) / 2;
}

void	maj_index(t_node **stack_a, t_node **stack_b)
{
	update_index(stack_a);
	update_index(stack_b);
}
