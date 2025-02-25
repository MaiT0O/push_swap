/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:27:36 by ebansse           #+#    #+#             */
/*   Updated: 2025/02/17 14:41:13 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_node *stack_a, t_node *stack_b)
{
	ft_printf("stack_a\t\tstack_b\n");
	ft_printf("-------\t\t-------\n");
	while(stack_a != NULL && stack_b != NULL)
	{
		ft_printf("[%d] %d\t\t[%d] %d\n", stack_a->index, stack_a->value,
			stack_b->index, stack_b->value);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	while (stack_a != NULL)
	{
		ft_printf("[%d] %d\n", stack_a->index, stack_a->value);
		stack_a = stack_a->next;
	}
	while (stack_b != NULL)
	{
		ft_printf("\t\t[%d] %d\n", stack_b->index, stack_b->value);
		stack_b = stack_b->next;
	}
	ft_printf("\n");
}

void	sort(t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	if (*stack_a == NULL)
		return ;

	else if (is_sorted(stack_a))
	{
		ft_printf("already sorted ;)");
		return ;
	}
	maj_index(stack_a, stack_b);
	maj_size(lib, *stack_a, *stack_b);
	/*print_stacks(*stack_a, *stack_b);*/
	if (lib->size_a == 2)
		sa(stack_a);
	else if (lib->size_a == 3)
		sort_3(stack_a);
	else if (lib->size_a == 4 || lib->size_a == 5)
		sort_5(stack_a, stack_b, lib);
	else if (lib->size_a > 5)
		sort_all(stack_a, stack_b, lib);	
}

int main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_lib	*lib;

	stack_a = NULL;
	stack_b = NULL;
	lib = malloc(sizeof(t_lib));
	if (argc == 2)
		stack_a = stack_chr(argv[1]);
	else if (argc > 2)
		stack_a = stack_int(argc, argv);
	if (!stack_a || !lib)
	{
		ft_printf("Error\n");
		free_all(&stack_a, &stack_b, lib);
		return (0);
	}
	sort(&stack_a, &stack_b, lib);
	ft_printf("\n");
	maj_index(&stack_a, &stack_b);
	/*print_stacks(stack_a, stack_b);*/
	free_all(&stack_a, &stack_b, lib);
	return (1);
}
