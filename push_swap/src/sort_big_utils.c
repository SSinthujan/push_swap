/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:27:28 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/03/10 01:08:39 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_mediane(t_stack **stack_a, t_stack **stack_b, int index_a,
		int index_b)
{
	while (index_a != 0 && index_b != 0)
	{
		rotate_r(stack_a, stack_b, 1);
		index_a--;
		index_b--;
	}
	if (index_a != 0)
	{
		while (index_a != 0)
		{
			rotate_a(stack_a, 1);
			index_a--;
		}
	}
	else
	{
		while (index_b != 0)
		{
			rotate_b(stack_b, 1);
			index_b--;
		}
	}
}

void	sort_big_nmediane(t_stack **stack_a, t_stack **stack_b, int index_a,
		int index_b)
{
	while (index_a != 0 && index_b != 0)
	{
		rrr(stack_a, stack_b, 1);
		index_a++;
		index_b++;
	}
	if (index_a != 0)
	{
		while (index_a != 0)
		{
			rra(stack_a, 1);
			index_a++;
		}
	}
	else
	{
		while (index_b != 0)
		{
			rrb(stack_b, 1);
			index_b++;
		}
	}
}

t_stack	*get_cheapest(t_stack *stack_b, int cheapest)
{
	t_stack	*current_b;

	current_b = stack_b;
	while (current_b && current_b->i != cheapest)
		current_b = current_b->next;
	return (current_b);
}

t_stack	*get_target(t_stack *stack_a, t_stack *current_b)
{
	t_stack	*current_a;

	current_a = stack_a;
	while (current_a && current_a->i != current_b->target)
		current_a = current_a->next;
	return (current_a);
}

void	sort_big_normal(t_stack *current_a, t_stack *current_b,
		t_stack **stack_a, t_stack **stack_b)
{
	if (current_a->mediane == 0)
		while (current_a->index-- != 0)
			rotate_a(stack_a, 1);
	else
		while (current_a->index++ != 0)
			rra(stack_a, 1);
	if (current_b->mediane == 0)
		while (current_b->index-- != 0)
			rotate_b(stack_b, 1);
	else
		while (current_b->index++ != 0)
			rrb(stack_b, 1);
}
