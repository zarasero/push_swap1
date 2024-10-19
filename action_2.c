/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:44:24 by zserobia          #+#    #+#             */
/*   Updated: 2024/07/17 12:44:27 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_a, stack_b) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (ft_size_stack(stack) < 2)
		return (-1);
	first = *stack;
	last = ft_last_argum(stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return (0);
}

int	ft_ra(t_list **stack_a)
{
	if (ft_rotate(stack_a) == -1)
		return (-1);
	write(1, "ra\n", 3);
	return (0);
}

int	ft_rb(t_list **stack_b)
{
	if (ft_rotate(stack_b) == -1)
		return (-1);
	write(1, "rb\n", 3);
	return (0);
}

int	ft_rr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_rotate(stack_a) == -1) || (ft_rotate(stack_b) == -1))
		return (-1);
	write(1, "rr\n", 3);
	return (0);
}
