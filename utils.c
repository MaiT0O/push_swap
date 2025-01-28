/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:27:32 by ebansse           #+#    #+#             */
/*   Updated: 2025/01/22 12:27:33 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_word(char *str)
{
	int i = 0;
	int wc = 0;
	
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	return (wc);
}

char	**ft_splitt(char *str)
{
	int i;
	int j;
	int k;
	int wc;
	
	k = 0;
	wc = ft_count_word(str);
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}

int	stack_size(t_node *stack)
{
	int size;
	size = 0;
	while (stack) {
		size++;
		stack = stack->next;
	}
	return size;
}
