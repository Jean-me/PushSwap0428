/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_or_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:42:25 by mesasaki          #+#    #+#             */
/*   Updated: 2025/04/28 18:39:15 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	sort_two(t_stack **stack)
{
	int	f;
	int	s;

	f = (*stack)->value;
	s = (*stack)->next->value;
	if (f > s)
		sa(stack);
}

void	sort_three(t_stack **stack)
{
	int	min_index;
	int	f;
	int	s;
	int	t;

	min_index = find_min_index(*stack);
	f = (*stack)->value;
	s = (*stack)->next->value;
	t = (*stack)->next->next->value;
	if (min_index == 1 && t < f)
		ra(stack);
	else if (min_index == 2 && f < s)
		rra(stack);
	else if (min_index == 0 && t < s)
	{
		sa(stack);
		ra(stack);
	}
	else if (min_index == 1 && t > s)
		sa(stack);
	else if (min_index == 2 && f > s)
	{
		sa(stack);
		rra(stack);
	}
}

int	find_min_index(t_stack *stack)
{
	unsigned int	min_value;
	int				min_index;
	int				current_index;

	min_value = stack->value;
	min_index = 0;
	current_index = 0;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_index = current_index;
		}
		stack = stack->next;
		current_index++;
	}
	return (min_index);
}
