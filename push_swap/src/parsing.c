/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:37:29 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/03/10 18:46:44 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stack_a)
{
	t_stack	*current;

	if (!stack_a)
		return (write(2, "Error\n", 6), 0);
	current = stack_a;
	while (current && current->next)
	{
		if (current->i > current->next->i)
			return (1);
		current = current->next;
	}
	return (0);
}

int	check_double(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*compare;

	if (!stack_a)
	{
		return (write(2, "Error\n", 6), 0);
	}
	current = stack_a;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->i == compare->i)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			compare = compare->next;
		}
		current = current->next;
	}
	return (1);
}

int	check_char(char *str)
{
	int	i;

	if (!str || !(*str))
		return (write(2, "Error\n", 6), 0);
	i = 0;
	if (str[i] != '+' && str[i] != '-' && !(str[i] >= '0' && str[i] <= '9'))
		return (write(2, "Error\n", 6), 0);
	if ((str[i] == '-' || str[i] == '+') && !str[i + 1])
		return (write(2, "Error\n", 6), 0);
	i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	return (1);
}
