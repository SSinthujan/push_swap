/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:37:33 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/03/10 19:00:15 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!str || !(*str))
		return (0);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			return (write(2, "Error\n", 6), INT_MAX + 1L);
		i++;
	}
	return (result * sign);
}

int	ft_list_size(t_stack *list)
{
	int		count;
	t_stack	*current;

	if (!list)
		return (0);
	current = list;
	count = 0;
	while (current)
	{
		++count;
		current = current->next;
	}
	return (count);
}

void	ft_index_mediane(t_stack *stack_a)
{
	int	i;
	int	size;
	int	index;

	i = 0;
	index = 0;
	if (!stack_a)
		return ;
	size = ft_list_size(stack_a);
	while (stack_a)
	{
		if (i >= size / 2)
		{
			stack_a->mediane = 1;
			stack_a->index = index++ - size;
		}
		else
		{
			stack_a->mediane = 0;
			stack_a->index = index++;
		}
		i++;
		stack_a = stack_a->next;
	}
}

void	ft_clear_stack(t_stack **list)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!list)
		return ;
	current = *list;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*list = 0;
}

int	print_stack(t_stack *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list)
	{
		ft_printf("node [%d]: value: [%d]\n", i, list->i);
		list = list->next;
		i++;
	}
	return (1);
}
