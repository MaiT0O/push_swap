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

int				ft_count_word(char *str);
char			**ft_splitt(char *s);

void			ft_stack_add_back(t_node **lst, t_node *new);
t_node			*ft_last_node(t_node *node);
t_node			*ft_new_node(int value);

t_node			*stack_chr(char *str);
t_node			*stack_int(int argc, char **argv);

#endif