/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:27:39 by ebansse           #+#    #+#             */
/*   Updated: 2025/02/04 18:24:34 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct Node {
    int		value;
	int		index;
	struct Node *next;
	struct Node *prev;
}			t_node;

int				ft_count_word(char *str);
char			**ft_splitt(char *s);

void			ft_stack_add_back(t_node **lst, t_node *new);
t_node			*ft_last_node(t_node *node);
t_node			*ft_new_node(int value);

t_node			*stack_chr(char *str);
t_node			*stack_int(int argc, char **argv);

int				is_sorted(t_node **node);
int				get_stack_size(t_node *stack);
void			sort(t_node **stack);
void	min_on_top(t_node **stack, t_node *node);

void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

#endif