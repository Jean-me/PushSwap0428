/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:42:25 by mesasaki          #+#    #+#             */
/*   Updated: 2025/04/28 19:45:56 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*top_b;

	if (!*b)
		return ;
	top_b = *b;
	*b = top_b->next;
	top_b->next = *a;
	*a = top_b;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*top_a;

	if (!*a)
		return ;
	top_a = *a;
	*a = top_a->next;
	top_a->next = *b;
	*b = top_a;
	ft_printf("pb\n");
}
