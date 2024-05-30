/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:39:24 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/02/20 19:17:56 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **list, t_stack **list2)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!list || !(*list) || !list2)
		return ;
	if (!(*list2))
	{
		tmp = *list;
		*list = (*list)->next;
		*list2 = tmp;
		tmp->next = 0;
		return ;
	}
	tmp = *list;
	*list = (*list)->next;
	tmp2 = *list2;
	*list2 = tmp;
	tmp->next = tmp2;
}

void	push_a(t_stack **stack_a, t_stack **stack_b, int print)
{
	push(stack_b, stack_a);
	if (print)
		ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b, int print)
{
	push(stack_a, stack_b);
	if (print)
		ft_printf("pb\n");
}
