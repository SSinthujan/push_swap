/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:31:52 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/03/27 22:12:29 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_el(long i)
{
	t_stack	*el;

	el = malloc(sizeof(t_stack));
	if (!el)
		return (0);
	el->i = (int)i;
	el->next = 0;
	return (el);
}

t_stack	*ft_add_back(t_stack **list, t_stack *to_add)
{
	t_stack	*current;

	if (!list || !(*list))
	{
		*list = to_add;
		return (*list);
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = to_add;
	return (*list);
}

int	check_stack(t_stack *stack_a)
{
	if (!check_double(stack_a) || !check_sorted(stack_a))
	{
		ft_clear_stack(&stack_a);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	i = 1;
	stack_a = 0;
	stack_b = 0;
	while (i < ac)
	{
		if (!check_char(av[i]) || ft_atol(av[i]) > INT_MAX)
		{
			ft_clear_stack(&stack_a);
			return (1);
		}
		ft_add_back(&stack_a, ft_new_el(ft_atol(av[i])));
		i++;
	}
	if (check_stack(stack_a))
		return (0);
	sort_numbers(&stack_a, &stack_b);
	return (0);
}
