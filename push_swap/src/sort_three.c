/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:36:28 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/03/13 03:52:59 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->i;
	b = ((*stack_a)->next)->i;
	c = ((*stack_a)->next->next)->i;
	if (!stack_a)
		return ;
	if (a > b && a > c && b < c)
		rotate_a(stack_a, 1);
	if (a < b && b > c && c < a)
		rra(stack_a, 1);
	if (a > b && a < c && c > b)
		swap_a(stack_a, 1);
	if (a > b && a > c && b > c)
	{
		rotate_a(stack_a, 1);
		swap_a(stack_a, 1);
	}
	else if (a < b && a < c && b > c)
	{
		rra(stack_a, 1);
		swap_a(stack_a, 1);
	}
}
