/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 03:22:55 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/03/27 23:12:26 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>

typedef struct stack
{
	int				i;
	struct stack	*next;
	int				mediane;
	int				index;
	int				target;
	int				cost;
}					t_stack;

int					ft_list_size(t_stack *list);
int					print_stack(t_stack *list);
void				ft_clear_stack(t_stack **list);
long				ft_atol(char *str);
void				ft_index_mediane(t_stack *stack_a);
int					check_char(char *str);
int					check_double(t_stack *stack_a);
int					check_sorted(t_stack *stack_a);
void				swap_a(t_stack **stack_a, int print);
void				swap_b(t_stack **stack_a, int print);
void				swap_s(t_stack **stack_a, t_stack **stack_b, int print);
void				rotate_a(t_stack **stack_a, int print);
void				rotate_b(t_stack **stack_a, int print);
void				rotate_r(t_stack **stack_a, t_stack **stack_b, int print);
void				rra(t_stack **stack_a, int print);
void				rrb(t_stack **stack_a, int print);
void				rrr(t_stack **stack_a, t_stack **stack_b, int print);
void				push_a(t_stack **stack_a, t_stack **stack_b, int print);
void				push_b(t_stack **stack_a, t_stack **stack_b, int print);
void				sort_three(t_stack **stack_a);
void				sort_numbers(t_stack **stack_a, t_stack **stack_b);
void				sort_big_mediane(t_stack **stack_a, t_stack **stack_b,
						int index_a, int index_b);
void				sort_big_nmediane(t_stack **stack_a, t_stack **stack_b,
						int index_a, int index_b);
t_stack				*get_cheapest(t_stack *stack_b, int cheapest);
t_stack				*get_target(t_stack *stack_a, t_stack *current_b);
void				sort_big_normal(t_stack *current_a, t_stack *current_b,
						t_stack **stack_a, t_stack **stack_b);
int					ft_limits_stack(t_stack *stack_a, int i);
int					ft_absolute(int i);
void				find_target(t_stack **stack_a, t_stack **stack_b);
int					maximizer(int a, int b);
void				find_cost(t_stack **stack_a, t_stack **stack_b);
void				last_sort(t_stack **stack_a);

#endif