/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:23:22 by ebansse           #+#    #+#             */
/*   Updated: 2025/03/04 12:26:16 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (stack && *stack)
	{
		while (*stack)
		{
			tmp = (*stack)->next;
			free(*stack);
			*stack = tmp;
		}
	}
}

void	free_split(char **split)
{
	int	i;

	if (split)
	{
		i = 0;
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

void	free_lib(t_lib *lib)
{
	if (lib)
		free(lib);
}

void	free_all(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free_lib(lib);
}
