/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:03:28 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/03/10 04:03:44 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int		max;

	current_b = *stack_b;
	ft_index_mediane(current_b);
	while (current_b)
	{
		current_a = *stack_a;
		max = ft_limits_stack(*stack_a, 1);
		if (current_b->i > max)
			current_b->target = ft_limits_stack(*stack_a, 0);
		else
		{
			while (current_a)
			{
				if (current_a->i > current_b->i && max > current_a->i)
					max = current_a->i;
				current_a = current_a->next;
			}
			current_b->target = max;
		}
		current_b = current_b->next;
	}
}

void	find_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int		cost;
	int		cost_a;
	int		cost_b;

	cost = 0;
	current_b = *stack_b;
	ft_index_mediane(*stack_a);
	while (current_b)
	{
		current_a = *stack_a;
		cost_b = current_b->index;
		cost_a = current_b->target;
		while (current_a && (current_a->i != cost_a))
			current_a = current_a->next;
		cost_a = current_a->index;
		if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
			cost = maximizer(ft_absolute(cost_a), ft_absolute(cost_b));
		else
			cost = ft_absolute(cost_a) + ft_absolute(cost_b);
		current_b->cost = cost;
		current_b = current_b->next;
	}
}

int	find_cheapest(t_stack **stack_b)
{
	t_stack	*current_b;
	int		cheapest_cost;
	int		cheapest;

	current_b = *stack_b;
	cheapest = current_b->i;
	cheapest_cost = current_b->cost;
	while (current_b)
	{
		if (cheapest_cost > current_b->cost)
		{
			cheapest_cost = current_b->cost;
			cheapest = current_b->i;
		}
		current_b = current_b->next;
	}
	return (cheapest);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b, int cheapest)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_b = get_cheapest(*stack_b, cheapest);
	current_a = get_target(*stack_a, current_b);
	if ((current_a->index > 0 && current_b->index > 0) || (current_a->index < 0
			&& current_b->index < 0))
	{
		if (current_a->mediane == 0)
			sort_big_mediane(stack_a, stack_b, current_a->index,
				current_b->index);
		else
			sort_big_nmediane(stack_a, stack_b, current_a->index,
				current_b->index);
	}
	else
		sort_big_normal(current_a, current_b, stack_a, stack_b);
}

void	sort_numbers(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_list_size(*stack_a) == 2)
		swap_a(stack_a, 1);
	else if (ft_list_size(*stack_a) == 3)
		sort_three(stack_a);
	else
	{
		while (ft_list_size(*stack_a) > 3)
			push_b(stack_a, stack_b, 1);
		sort_three(stack_a);
		while (*stack_b)
		{
			find_target(stack_a, stack_b);
			find_cost(stack_a, stack_b);
			sort_big(stack_a, stack_b, find_cheapest(stack_b));
			push_a(stack_a, stack_b, 1);
		}
	}
	last_sort(stack_a);
	ft_clear_stack(stack_a);
}
