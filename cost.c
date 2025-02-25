#include "push_swap.h"

int	calculate_cost(t_node *node, t_lib *lib)
{
    if (node->index <= lib->median_a && lib->index_b <= lib->median_b)
    {
        if (node->index > lib->index_b)
            return (node->index + 1);
        else
            return (lib->index_b + 1);
    }
    else if (node->index > lib->median_a && lib->index_b > lib->median_b)
    {
        if (lib->size_a - node->index > lib->size_b - lib->index_b)
            return ((lib->size_a - node->index) + 1);
        else
            return ((lib->size_b - lib->index_b) + 1);
    }
    else if (node->index <= lib->median_a && lib->index_b > lib->median_b)
        return ((node->index + (lib->size_b - lib->index_b)) + 1);
    else if (node->index > lib->median_a && lib->index_b <= lib->median_b)
        return ((lib->index_b + (lib->size_a - node->index)) + 1);
    ft_printf("Error\n");
    return (-1);
}
