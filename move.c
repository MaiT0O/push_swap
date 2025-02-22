#include "push_swap.h"

void	move_node_to_top_a(t_node **stack_a, int index, t_lib *lib)
{
    if (!stack_a || !lib)
    {
        ft_printf("error: stack_a or lib is NULL\n");
        return;
    }
    else if (index <= lib->median_a)
    {
        while (index > 0)
        {
            ra(stack_a);
            index--;
        }
    }
    else if (index > lib->median_a)
    {
        while (index < lib->size_a)
        {
            rra(stack_a);
            index++;
        }
    }
}

void	move_node_to_top_b(t_node **stack_b, int index, t_lib *lib)
{
    if (!stack_b || !lib)
    {
        ft_printf("error: stack_b or lib is NULL\n");
        return;
    }
    else if (index <= lib->median_b)
    {
        while (index > 0)
        {
            rb(stack_b);
            index--;
        }
    }
    else if (index > lib->median_b)
    {
        while (index < lib->size_b)
        {
            rrb(stack_b);
            index++;
        }
    }
}

void	double_r_rotate(t_node *node, t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	while (node->index < lib->size_a && lib->index_b < lib->size_b)
	{
		rrr(stack_a, stack_b);
		node->index++;
		lib->index_b++;
	}
	if (node->index == lib->size_a)
	{
		while (lib->index_b < lib->size_b)
		{
			rrb(stack_b);
			lib->index_b++;
		}
	}
	else if (lib->index_b == lib->size_b)
	{
		while (node->index < lib->size_a)
		{
			rra(stack_a);
			node->index++;
		}
	}
}

void	double_rotate(t_node *node, t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	while (lib->index_b > 0 && node->index > 0)
	{
		rr(stack_a, stack_b);
		lib->index_b--;
		node->index--;
	}
	if (lib->index_b == 0)
	{
		while (node->index > 0)
		{
			ra(stack_a);
			node->index--;
		}
	}
	else if (node->index == 0)
	{
		while (lib->index_b > 0)
		{
			rb(stack_b);
			lib->index_b--;
		}
	}
}

void	insert(t_node *node, t_node **stack_a, t_node **stack_b, t_lib *lib)
{
	if (!node || !stack_a || !stack_b || !lib)
	{
		ft_printf("error: node, stack_a, stack_b, or lib is NULL\n");
		return ;
	}
	ft_printf("node index : %d / index_b : %d / median_a : %d / median_b : %d\n", node->index, lib->index_b, lib->median_a, lib->median_b);
	if (node->index <= lib->median_a && lib->index_b <= lib->median_b && node->index > 0 && lib->index_b > 0)
		double_rotate(node, stack_a, stack_b, lib);
	else if (node->index > lib->median_a && lib->index_b > lib->median_b)
		double_r_rotate(node, stack_a, stack_b, lib);
	else
	{
		move_node_to_top_a(stack_a, node->index, lib);
		move_node_to_top_b(stack_b, lib->index_b, lib);
	}
	pb(stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
}
