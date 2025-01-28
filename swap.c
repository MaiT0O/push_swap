#include "push_swap.h"

void	swap(t_node **stack)
{
	int		tmp_value;

	if (!*stack || !(*stack)->next)
		return ;

	tmp_value = (*stack)->next->value;
	(*stack)->next->value = (*stack)->value;
	(*stack)->value = tmp_value;
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
