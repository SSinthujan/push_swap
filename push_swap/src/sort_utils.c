/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 06:04:49 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/03/13 03:53:43 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_limits_stack(t_stack *stack_a, int i)
{
	int	max;
	int	min;

	max = stack_a->i;
	min = stack_a->i;
	while (stack_a)
	{
		if (max < stack_a->i)
			max = stack_a->i;
		if (min > stack_a->i)
			min = stack_a->i;
		stack_a = stack_a->next;
	}
	if (i == 0)
		return (min);
	else
		return (max);
}

int	ft_absolute(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}

int	maximizer(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	last_sort(t_stack **stack_a)
{
	t_stack	*current_a;
	int		min;

	current_a = *stack_a;
	min = ft_limits_stack(*stack_a, 0);
	while ((*stack_a)->i != min)
	{
		ft_index_mediane(*stack_a);
		while (current_a && current_a->i != min)
			current_a = current_a->next;
		if (current_a->mediane == 0)
			rotate_a(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}
