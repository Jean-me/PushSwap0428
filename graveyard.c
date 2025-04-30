/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graveyard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:12:46 by mesasaki          #+#    #+#             */
/*   Updated: 2025/04/30 16:46:37 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	bury_array(int *array, unsigned int *id_arr)
{
	if (array)
		free (array);
	if (id_arr)
		free (id_arr);
}

void	bury_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free (tmp);
	}
}

void	bury_all(int *array, unsigned int *id_arr,
			t_stack *stack_a, t_stack *stack_b)
{
	bury_array(array, id_arr);
	bury_stack(stack_a);
	bury_stack(stack_b);
}
