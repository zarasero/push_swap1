/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sort_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:33:48 by zserobia          #+#    #+#             */
/*   Updated: 2024/07/23 13:04:06 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_new_min_index(t_list **stack_a, int min_index)
{
	t_list	*new;
	int		new_min_index;

	new = *stack_a;
	new_min_index = new->index;
	while (new->next != NULL)
	{
		new = new->next;
		if (new->index < new_min_index && new->index > min_index)
			new_min_index = new->index;
	}
	return (new_min_index);
}

void	ft_sort_3_next(t_list **stack_a, t_list *new, int min_index)
{
	if (new->next->index == min_index)
		ft_ra(stack_a);
	else
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
}

void	ft_sort_stack_3(t_list **stack_a)
{
	t_list	*new;
	int		min_index;
	int		min_index_next;

	min_index = ft_new_min_index(stack_a, -1);
	min_index_next = ft_new_min_index(stack_a, min_index);
	if (!ft_check_sort(stack_a))
		return ;
	new = *stack_a;
	if (new->index == min_index && new->next->index != min_index_next)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (new->index == min_index_next)
	{
		if (new->next->index == min_index)
			ft_sa(stack_a);
		else
			ft_rra(stack_a);
	}
	else
	{
		ft_sort_3_next(stack_a, new, min_index);
	}
}

void	ft_sort_stack_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = ft_find_distance(stack_a, ft_new_min_index(stack_a, -1));
	if (distance == 1)
		ft_sa(stack_a);
	else if (distance == 2)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (distance == 3)
		ft_rra(stack_a);
	if (!ft_check_sort(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_stack_3(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_stack_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = ft_find_distance(stack_a, ft_new_min_index(stack_a, -1));
	if (distance == 1)
		ft_sa(stack_a);
	else if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (distance == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (distance > 3)
		ft_rra(stack_a);
	if (!ft_check_sort(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_stack_4(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
