/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:45:41 by mesasaki          #+#    #+#             */
/*   Updated: 2025/04/29 19:29:25 by mesasaki         ###   ########.fr       */
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

int compare_n(int *arr, int n)
{
	int i, j;

	i = 0;
	while (i < n)  // 最後の1つは比較対象がないので n - 1 まで
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


// int compare_n(int *arr, int n)
// {
// 	int first;
// 	int next;
// 	int i;
// 	int c;

// 	i = 0;
// 	c = 1;
	
// 	first = arr[i];
// 	while (i < n)//引数分繰り返す
// 	{
// 		next = arr[c];
// 		while (c < n)
// 		{
// 			if (first == next)
// 				return (NOT_NUMBER);
// 			next = arr[c++];
// 		}
// 		first = arr[i++];
// 		c = i + 1;
// 	}
// 	return (NUMBER);
// }

int	compare_number(t_stack **stack)
{
	t_stack	*pointerA;
	t_stack	*pointerB;

	pointerA = *stack;
	while (pointerA != NULL)
	{
		pointerB = pointerA->next;
		while (pointerB != NULL)
		{
			if (pointerA->value == pointerB->value)
			{
				return (NOT_NUMBER);
			}
			pointerB = pointerB->next;
		}
		pointerA = pointerA->next;
	}
	return (NUMBER);
}

// int arguments_check(int argc, char **str)
// {
// 	int i;

// 	i = 0;
// 	while(i < argc)
// 	{
// 		if (is_number(str[i]) == NOT_NUMBER)
// 			return (NOT_NUMBER);
// 		if (over_int(str[i]) == NOT_NUMBER)
// 			return (NOT_NUMBER);
// 		if (compare_number() == NOT_NUMBER)
// 			return (NOT_NUMBER);
// 		i++;
// 	}
// 	return (NUMBER);
// }