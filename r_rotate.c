#include "push_swap.h"

void	r_rotate(t_node **stack)
{
	t_node *tail;
    t_node *second_last;

    if (!*stack || !(*stack)->next)
        return;

    tail = *stack;
    second_last = NULL;

    while (tail->next)
    {
        second_last = tail;
        tail = tail->next;
    }

    second_last->next = NULL;
    tail->next = *stack;
    (*stack)->prev = tail;
    *stack = tail;
    (*stack)->prev = NULL;
}

void	rra(t_node **stack_a)
{
	r_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	r_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	ft_printf("rrr\n");
}
