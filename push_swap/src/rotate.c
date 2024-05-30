/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:51:32 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/02/20 19:19:18 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **list)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	tmp = *list;
	current = (*list)->next;
	*list = current;
	while (current->next)
		current = current->next;
	current->next = tmp;
	tmp->next = 0;
}

void	rotate_a(t_stack **stack_a, int print)
{
	rotate(stack_a);
	if (print)
		ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_a, int print)
{
	rotate(stack_a);
	if (print)
		ft_printf("rb\n");
}

void	rotate_r(t_stack **stack_a, t_stack **stack_b, int print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		ft_printf("rr\n");
}
