/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:27:36 by ebansse           #+#    #+#             */
/*   Updated: 2025/01/22 16:04:14 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_node *stack_a, t_node *stack_b)
{
	ft_printf("stack_a\t\tstack_b\n");
	ft_printf("-------\t\t-------\n");
	while (stack_a != NULL && stack_b != NULL)
	{
		ft_printf("%d\t\t%d\n", stack_a->value, stack_b->value);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	while (stack_a != NULL)
	{
		ft_printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	while (stack_b != NULL)
	{
		ft_printf("\t\t%d\n", stack_b->value);
		stack_b = stack_b->next;
	}
	ft_printf("\n");
}

int main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		stack_a = stack_chr(argv[1]);
	else if (argc > 2)
		stack_a = stack_int(argc, argv);
	print_stacks(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	ft_printf("\n");
	print_stacks(stack_a, stack_b);
	return (0);
}
