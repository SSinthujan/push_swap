/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:43:12 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/02/20 19:18:27 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **list)
{
	t_stack	*current;

	if (!list || !(*list) || !(*list)->next)
		return ;
	current = (*list)->next;
	(*list)->next = current->next;
	current->next = *list;
	*list = current;
}

void	swap_a(t_stack **stack_a, int print)
{
	swap(stack_a);
	if (print)
		ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b, int print)
{
	swap(stack_b);
	if (print)
		ft_printf("sb\n");
}

void	swap_s(t_stack **stack_a, t_stack **stack_b, int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		ft_printf("ss\n");
}
