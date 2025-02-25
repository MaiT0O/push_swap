#include "../push_swap.h"

t_node	*smallest(t_node **stack)
{
	t_node *tmp;
	t_node	*small;

	tmp = *stack;
	small = tmp;
	while (tmp)
	{
		if (tmp->value < small->value)
			small = tmp;
		tmp = tmp->next;
	}
	return (small);
}

t_node	*bigest(t_node **stack)
{
	t_node *tmp;
	t_node	*big;

	tmp = *stack;
	big = tmp;
	while (tmp)
	{
		if (tmp->value > big->value)
			big = tmp;
		tmp = tmp->next;
	}
	return (big);
}

int	is_smallest(t_node *node, t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value < node->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	closest_lower(t_node *target, t_node *stack, t_lib *lib)
{
    t_node  *current;
    int     best_index;
    int     best_diff;

    if (!stack || !target)
        return (0);
    current = stack;
    best_index = 0;
    best_diff = INT_MAX;
    while (current)
    {
        if (target->value - current->value < best_diff && target->value - current->value > 0)
        {
            best_diff = target->value - current->value;
            best_index = current->index;
        }
        current = current->next;
    }
	if (best_index == 0)
		return (lib->size_b);
	return (best_index);
}

int	closest_higher(t_node *target, t_node *stack)
{
	t_node  *current;
	int     best_index;
	int     best_diff;

	if (!stack || !target)
		return (0);
	current = stack;
	best_index = 0;
	best_diff = INT_MAX;
	while (current)
	{
		if (current->value - target->value > 0 && current->value - target->value < best_diff)
		{
			best_diff = current->value - target->value;
			best_index = current->index;
		}
		current = current->next;
	}
	return (best_index);
}
