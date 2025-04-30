/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:58:07 by mesasaki          #+#    #+#             */
/*   Updated: 2025/04/30 16:46:05 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# define NUMBER 0
# define NOT_NUMBER 1
# include <unistd.h>

typedef struct s_stack
{
	unsigned int	value;
	int				is_ranked;
	struct s_stack	*next;
}				t_stack;

void			add_node(t_stack **top, unsigned int value);
void			print_stack(t_stack *top);
int				find_min_id(int *arr, bool *mask, int num);
int				find_min_index(t_stack *stack);
int				stack_size(t_stack *stack);
void			swap(t_stack **stack);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			rotate(t_stack **stack);
void			ra(t_stack **a);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			reverse_rotate(t_stack **stack);
void			rra(t_stack **a);
void			sort_two(t_stack **stack);
void			sort_three(t_stack **stack);
void			move_min_to_top(t_stack **a, int min_index);
int				get_max_bits(t_stack *stack);
void			radix_sort(t_stack **a, t_stack **b);
unsigned int	*value2id(int *arr, unsigned int *id_arr, int num);
int				space_or_not(char c);
int				ft_atoi(const char *string);
int				*add_number_to_arr(int *arr, int value, int count);
int				over_int(char *str);
int				ft_isdigit(int c);
int				is_number(char *str);
int				compare_n(int *arr, int n);
void			bury_array(int *array, unsigned int *id_arr);
void			bury_stack(t_stack *stack);
void			bury_all(int *array, unsigned int *id_arr,
					t_stack *stack_a, t_stack *stack_b);
#endif