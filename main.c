#include "push_swap.h"

void	s(t_node **stack_a)
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

void	ss(t_node **stack_a, t_node **stack_b)
{
	s(stack_a);
	s(stack_b);
}

void	p(t_node **stack_a, t_node **stack_b)
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

void	r(t_node **stack)
{
	t_node	*last;
	int		tmp_value;

	if (!*stack || !(*stack)->next)
		return ;

	last = ft_last_node(*stack);
	tmp_value = (*stack)->value;
	(*stack)->value = last->value;
	while ((*stack)->next != NULL)
	{
		(*stack)->next->value = tmp_value;
		*stack = (*stack)->next;
		tmp_value = (*stack)->value;
	}
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
	ft_printf("\n");
	r(&stack_a);
	print_stack(stack_a);
	return (0);
}
