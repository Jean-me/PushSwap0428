/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whisper_of_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 23:04:00 by mesasaki          #+#    #+#             */
/*   Updated: 2025/04/27 23:04:01 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	add_node(t_stack **top, unsigned int value)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (*top == NULL)
		*top = new_node;
	else
	{
		last = *top;
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
}

int	find_min_id(int *arr, bool *mask, int num)
{
	int	i;
	int	min_v;
	int	min_id;

	min_v = INT_MAX;
	min_id = -1;
	i = 0;
	while (i < num)
	{
		if (!mask[i] && arr[i] < min_v)
		{
			min_v = arr[i];
			min_id = i;
		}
		i++;
	}
	return (min_id);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	get_max_bits(t_stack *stack)
{
	unsigned int	max;
	int				bits;
	int				count_bits;

	max = 0;
	bits = 0;
	count_bits = -1;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	bit_index;
	int	bit;
	int	size;

	i = 0;
	bit_index = 0;
	bit = get_max_bits(*a);
	size = stack_size(*a);
	while (bit_index < bit)
	{
		i = 0;
		while (i < size)
		{
			if (!(((*a)->value >> bit_index) & (unsigned int)1))
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (*b)
			pa(a, b);
		bit_index++;
	}
}
