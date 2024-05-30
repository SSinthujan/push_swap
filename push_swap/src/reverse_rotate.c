/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 02:37:47 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/02/20 19:18:16 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!list || !(*list) || !(*list)->next)
		return ;
	current = *list;
	while ((*list)->next)
		*list = (*list)->next;
	tmp = *list;
	tmp->next = current;
	while (current->next != tmp)
		current = current->next;
	current->next = 0;
}

void	rra(t_stack **stack_a, int print)
{
	reverse_rotate(stack_a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_a, int print)
{
	reverse_rotate(stack_a);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrr\n");
}
