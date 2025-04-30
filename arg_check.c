/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:45:41 by mesasaki          #+#    #+#             */
/*   Updated: 2025/04/30 15:16:21 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (NOT_NUMBER);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (NOT_NUMBER);
		str++;
	}
	return (NUMBER);
}

int	over_int(char *str)
{
	int				minus;
	unsigned long	result;

	result = 0;
	minus = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = 10 * result + (*str - '0');
		if ((unsigned long)INT_MAX < result && minus == 0)
			return (NOT_NUMBER);
		if ((unsigned long)INT_MAX + 1 < result && minus == -1)
			return (NOT_NUMBER);
		str++;
	}
	return (NUMBER);
}

int	compare_n(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (NOT_NUMBER);
			j++;
		}
		i++;
	}
	return (NUMBER);
}
