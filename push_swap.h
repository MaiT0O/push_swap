/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:27:39 by ebansse           #+#    #+#             */
/*   Updated: 2025/02/17 13:40:49 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct Node {
    int		value;
	int		index;
	struct Node *next;
	struct Node *prev;
}			t_node;

typedef struct Lib {
	int	median_a;
	int	median_b;
	int	size_a;
	int	size_b;
	int	index_b;
}			t_lib;

/*split.c*/
int		ft_count_word(char *str);
char	**ft_splitt(char *s);

/*lst_utils.c*/
t_node	*stack_chr(char *str);
t_node	*stack_int(int argc, char **argv);

/*utils.c*/
int		get_stack_size(t_node *stack);
void	maj_size(t_lib *lib, t_node *stack_a, t_node *stack_b);
void	maj_index(t_node **stack_a, t_node **stack_b);
int		is_sorted(t_node **node);

/*move.c*/
void	move_node_to_top_a(t_node **stack_a, int index, t_lib *lib);
void	move_node_to_top_b(t_node **stack_b, int index, t_lib *lib);
void	double_rotate(t_node *node, t_node **stack_a, t_node **stack_b, t_lib *lib);
void	double_r_rotate(t_node *node, t_node **stack_a, t_node **stack_b, t_lib *lib);
void	insert(t_node *node, t_node **stack_a, t_node **stack_b, t_lib *lib);

/*utils2.c*/
int		is_smallest(t_node *node, t_node *stack);
int		closest_lower(t_node *target, t_node *stack, t_lib *lib);
int		closest_higher(t_node *target, t_node *stack);
t_node	*smallest(t_node **stack);
t_node	*bigest(t_node **stack);

/*pars_free.c*/
int		not_seen(t_node *stack, int value);
void	free_stack(t_node **stack);
void	free_split(char **split);
void	free_lib(t_lib *lib);
void	free_all(t_node **stack_a, t_node **stack_b, t_lib *lib);

/*cost.c*/
int		calculate_cost(t_node *node, t_lib *lib);

void	print_stacks(t_node *stack_a, t_node *stack_b);

void	sort_5(t_node **stack_a, t_node **stack_b, t_lib *lib);
void	sort_3(t_node **stack);
void	sort_all(t_node **stack_a, t_node **stack_b, t_lib *lib);

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