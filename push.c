#include "push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
