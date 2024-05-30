/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 02:50:59 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/03/27 22:17:30 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	error_exit(char *str, t_stack **a, t_stack **b)
{
	ft_clear_stack(a);
	ft_clear_stack(b);
	free(str);
	write(2, "Error\n", 6);
}

int	checker(t_stack *stack_a, t_stack *stack_b)
{
	if ((check_sorted(stack_a) == 0) && !stack_b)
		return (ft_clear_stack(&stack_a), ft_clear_stack(&stack_b),
			ft_printf("OK\n"), 1);
	else
		return (ft_clear_stack(&stack_a), ft_clear_stack(&stack_b),
			ft_printf("KO\n"), 0);
}

int	check_stack_checker(t_stack *stack_a)
{
	if (!check_double(stack_a))
	{
		ft_clear_stack(&stack_a);
		return (1);
	}
	return (0);
}