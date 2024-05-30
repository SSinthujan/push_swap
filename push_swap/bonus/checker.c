/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:38:58 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/03/27 23:12:15 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_input(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(str, "pa\n"))
		push_a(stack_a, stack_b, 0);
	else if (!ft_strcmp(str, "pb\n"))
		push_b(stack_a, stack_b, 0);
	else if (!ft_strcmp(str, "sa\n"))
		swap_a(stack_a, 0);
	else if (!ft_strcmp(str, "sb\n"))
		swap_b(stack_b, 0);
	else if (!ft_strcmp(str, "ss\n"))
		swap_s(stack_a, stack_b, 0);
	else if (!ft_strcmp(str, "ra\n"))
		rotate_a(stack_a, 0);
	else if (!ft_strcmp(str, "rb\n"))
		rotate_b(stack_b, 0);
	else if (!ft_strcmp(str, "rr\n"))
		rotate_r(stack_a, stack_b, 0);
	else if (!ft_strcmp(str, "rra\n"))
		rra(stack_a, 0);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(stack_b, 0);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(stack_a, stack_b, 0);
	else
		return (error_exit(str, stack_a, stack_b), 1);
	return (0);
}

void	check_instruction(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (check_input(str, stack_a, stack_b))
		{
			get_next_line(-50);
			exit(1);
		}
		free(str);
		str = get_next_line(0);
	}
}

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
	if (check_stack_checker(stack_a))
		return (0);
	check_instruction(&stack_a, &stack_b);
	checker(stack_a, stack_b);
	return (0);
}
