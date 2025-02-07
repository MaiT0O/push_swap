/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:39:19 by ebansse           #+#    #+#             */
/*   Updated: 2025/02/07 19:22:02 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int atoi_verif(const char *str)
{
    int i;
	int	sign;

    i = 0;
	sign = 0;
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
           str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		if (str[i] == '-' && str[i] == '+' && sign == 2)
			return (-1);
        i++;
	}
    if (str[i] < '0' || str[i] > '9')
        return (-1);
    return i;
}

long *ft_atoi(const char *str)
{
    int i;
    long res;
    int sign;
    long *num;

    i = atoi_verif(str);
    if (i == -1)
        return NULL;
    res = 0;
    sign = 1;
    if (str[i - 1] == '-')
        sign = -1;
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + (str[i] - '0');
        i++;
    }
    num = malloc(sizeof(long));
    if (!num)
        return NULL;
    *num = res * sign;
    return num;
}
