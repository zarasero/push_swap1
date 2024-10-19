/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:48:26 by zserobia          #+#    #+#             */
/*   Updated: 2024/07/15 17:44:49 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_argum(t_list **stack)
{
	t_list	*new_stack;
	int		count;

	count = 0;
	if (*stack == NULL)
		return (0);
	new_stack = *stack;
	while (new_stack)
	{
		new_stack = new_stack->next;
		count++;
	}
	return (count);
}

t_list	*ft_last_argum(t_list **stack)
{
	t_list	*new_stack;

	if (*stack == NULL)
		return (NULL);
	new_stack = *stack;
	while (new_stack->next != NULL)
		new_stack = new_stack->next;
	return (new_stack);
}

t_list	*ft_tlist_create(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->index = -1;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_tlist_add_back(t_list **stack_a, t_list *new_argum)
{
	t_list	*new;

	if (*stack_a)
	{
		new = *stack_a;
		while (new->next != NULL)
			new = new->next;
		new->next = new_argum;
		new_argum->next = NULL;
	}
	else
	{
		*stack_a = new_argum;
		new_argum->next = NULL;
	}
}
