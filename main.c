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

void	swap(t_node **stack_a)
{
	t_node	*tmp;
	int		tmp_value;

	if (!*stack_a || !(*stack_a)->next)
		return ;

	tmp = ft_last_node(*stack_a);
	tmp_value = tmp->prev->value;
	tmp->prev->value = tmp->value;
	tmp->value = tmp_value;
}

void	push(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (!*stack_b)
		return ;

	tmp = ft_last_node(*stack_b);
	ft_stack_add_back(stack_a, ft_new_node(tmp->value));
	if (tmp->prev)
		tmp->prev->next = NULL;
	free(tmp);
}


void	rotate(t_node **stack)
{
    t_node *prev = NULL;
    t_node *tail = *stack;

    if (!stack || !(*stack) || !(*stack)->next)
        return;

    while (tail->next)
    {
        prev = tail;
        tail = tail->next;
    }
    prev->next = NULL;
    tail->next = *stack;
    *stack = tail;
}

void	reverse_rotate(t_node **stack)
{
	t_node	*tail;
	t_node	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = ft_last_node(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	print_stacks(t_node *stack_a, t_node *stack_b)
{
	ft_printf("stack_a			stack_b\n");
	ft_printf("-------			-------\n");
	while (stack_a != NULL && stack_b != NULL)
	{
		ft_printf("node_a[%d] : %d\tnode_b[%d] : %d\n", stack_a->index, stack_a->value, stack_b->index, stack_b->value);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
}

void	print_stack(t_node *stack)
{
	/*t_node	*tmp;
	tmp = ft_last_node(stack);*/
	
	while (stack != NULL)
	{
		ft_printf("node[%d] : %d\n", stack->index, stack->value);
		stack = stack->next;
	}
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
	print_stack(stack_a);
	swap(&stack_a);
	ft_printf("\n");
	print_stack(stack_a);
	return (0);
}
