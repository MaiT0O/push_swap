/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:27:29 by ebansse           #+#    #+#             */
/*   Updated: 2025/02/10 15:12:09 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_last_node(t_node *node)
{
	while (node && node->next)
	{
		node = node->next;
	}
	return (node);
}

void	ft_stack_add_back(t_node **lst, t_node *new)
{
    t_node	*last;

    if (!new)
        return ;
    if (!*lst)
    {
        *lst = new;
		new->index = 0;
		new->prev = NULL;
		new->next = NULL;
        return ;
    }
    last = ft_last_node(*lst);
    last->next = new;
    new->prev = last;
}

t_node	*ft_new_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_node	*stack_chr(char *str)
{
	t_node	*stack;
	char	**argv;
	int		i;
	int		wc;

	stack = NULL;
	i = 0;
	wc = ft_count_word(str);
	argv = ft_splitt(str);
	while (i < wc)
	{
		if (ft_atoi_custom(argv[i]) < INT_MIN || ft_atoi_custom(argv[i]) > INT_MAX
			 || ft_atoi_custom(argv[i]) == LONG_MIN)
		{
			ft_printf("Error\n");
			return (NULL);
		}
		else
		{
			ft_stack_add_back(&stack, ft_new_node(ft_atoi_custom(argv[i])));
			i++;
		}
	}
	return (stack);
}

t_node	*stack_int(int argc, char **argv)
{
	t_node	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_atoi_custom(argv[i]) < INT_MIN || ft_atoi_custom(argv[i]) > INT_MAX
			 || ft_atoi_custom(argv[i]) == LONG_MIN)
		{
			ft_printf("Error\n");
			return (NULL);
		}
		else
		{
			ft_stack_add_back(&stack, ft_new_node(ft_atoi_custom(argv[i])));
			i++;
		}
	}
	return (stack);
}
