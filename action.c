/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:48:54 by zserobia          #+#    #+#             */
/*   Updated: 2024/07/22 19:25:03 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	int		new_value;
	int		new_index;

	if (ft_size_stack(stack) < 2)
		return (-1);
	first = *stack;
	second = first->next;
	new_value = first->value;
	first->value = second->value;
	second->value = new_value;
	new_index = first->index;
	first->index = second->index;
	second->index = new_index;
	return (0);
}

int	ft_sa(t_list **stack_a)
{
	if (ft_swap(stack_a) == -1)
		return (-1);
	write(1, "sa\n", 3);
	return (0);
}

int	ft_sb(t_list **stack_b)
{
	if (ft_swap(stack_b) == -1)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

int	ft_ss(t_list **stack_a, t_list **stack_b)
{
	if ((ft_swap(stack_a) == -1) || (ft_swap(stack_b) == -1))
		return (-1);
	write(1, "ss\n", 3);
	return (0);
}

int	ft_push(t_list **stack_dest, t_list **stack_push)
{
	t_list	*first_push;
	t_list	*first_dest;
	t_list	*new_stack;

	first_push = *stack_push;
	if (first_push == NULL)
		return (-1);
	*stack_push = first_push->next;
	new_stack = first_push;
	first_dest = *stack_dest;
	if (first_dest == NULL)
	{
		*stack_dest = new_stack;
		new_stack->next = NULL;
	}
	else
	{
		new_stack->next = first_dest;
		*stack_dest = new_stack;
	}
	return (0);
}
