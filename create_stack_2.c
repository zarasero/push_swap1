/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:07:21 by zserobia          #+#    #+#             */
/*   Updated: 2024/07/23 13:38:52 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_stack(t_list **stack)
{
	t_list	*current;
	int		count;

	count = 0;
	current = *stack;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}

t_list	*ft_next_min_index(t_list **stack_a)
{
	t_list	*current;
	t_list	*min;
	int		found_min;

	min = NULL;
	found_min = 0;
	current = *stack_a;
	while (current)
	{
		if ((current->index == -1)
			&& (!found_min || current->value < min->value))
		{
			min = current;
			found_min = 1;
		}
		current = current->next;
	}
	return (min);
}

void	ft_create_index(t_list **stack_a)
{
	t_list	*min;
	int		index;

	index = 0;
	min = ft_next_min_index(stack_a);
	while (min)
	{
		min->index = index++;
		min = ft_next_min_index(stack_a);
	}
}

void	ft_create_stack(t_list **stack_a, int ac, char **av)
{
	char	**av1;
	t_list	*new_argum;
	int		i;

	i = 0;
	if (ac == 2)
		av1 = ft_split(av[1], ' ');
	else
	{
		av1 = av;
		i = 1;
	}
	while (av1[i])
	{
		new_argum = ft_tlist_create(ft_atoi(av1[i]));
		ft_tlist_add_back(stack_a, new_argum);
		i++;
	}
	ft_create_index(stack_a);
	if (ac == 2)
		ft_free(av1);
}
