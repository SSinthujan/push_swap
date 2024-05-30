/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:02:23 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/03/27 22:20:01 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../src/push_swap.h"

int		checker(t_stack *stack_a, t_stack *stack_b);
int		check_stack_checker(t_stack *stack_a);
int		ft_strcmp(char *s1, char *s2);
void	error_exit(char *str, t_stack **a, t_stack **b);

#endif