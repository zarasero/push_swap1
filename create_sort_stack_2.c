/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sort_stack_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:08:38 by zserobia          #+#    #+#             */
/*   Updated: 2024/07/23 13:40:28 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_distance(t_list **stack_a, int min_index)
{
	t_list	*current;
	int		distance;

	current = *stack_a;
	distance = 0;
	while (current)
	{
		if (current->index == min_index)
			return (distance);
		distance++;
		current = current->next;
	}
	return (-1);
}

void	ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_size_stack(stack_a);
	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		ft_sort_stack_3(stack_a);
	else if (size == 4)
		ft_sort_stack_4(stack_a, stack_b);
	else if (size == 5)
		ft_sort_stack_5(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
}

int	ft_check_sort(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return (1);
		current = current->next;
	}
	return (0);
}
