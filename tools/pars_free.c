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

int	not_seen(t_node *stack, int value)
{
    t_node	*tmp;

    tmp = stack;
    while (tmp)
    {
        if (tmp->value == value)
            return (0);
        tmp = tmp->next;
    }
    return (1);
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
