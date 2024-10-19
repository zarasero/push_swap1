/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:53:51 by zserobia          #+#    #+#             */
/*   Updated: 2024/07/22 19:23:30 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_b, stack_a) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}

/*int	ft_rotate_reverse(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*new_stack;

	if (ft_size_stack(stack) < 2)
		return (-1);
	first = *stack;
	last = ft_last_argum(stack);
	new_stack = first;
	while (new_stack->next != last)
		new_stack = new_stack->next;
	new_stack->next = NULL;
	last->next = *stack;
	*stack = last;
	return (0);
}*/

int	ft_rotate_reverse(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*new_stack;

	if (ft_size_stack(stack) < 2)
		return (-1);
	first = *stack;
	last = ft_last_argum(stack);
	new_stack = first;
	while (new_stack->next != last)
		new_stack = new_stack->next;
	new_stack->next = NULL;
	last->next = first;
	*stack = last;
	return (0);
}

int	ft_rra(t_list **stack_a)
{
	if (ft_rotate_reverse(stack_a) == -1)
		return (-1);
	write(1, "rra\n", 4);
	return (0);
}

int	ft_rrb(t_list **stack_b)
{
	if (ft_rotate_reverse(stack_b) == -1)
		return (-1);
	write(1, "rrb\n", 3);
	return (0);
}

int	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_rotate_reverse (stack_a) == -1)
		|| (ft_rotate_reverse (stack_b) == -1))
		return (-1);
	write(1, "rrr\n", 3);
	return (0);
}
