/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:08:23 by zserobia          #+#    #+#             */
/*   Updated: 2024/07/22 19:49:26 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	else
		return (0);
}

void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*next_node;

	if (stack && *stack)
	{
		current = *stack;
		while (current)
		{
			next_node = current->next;
			free(current);
			current = next_node;
		}
		*stack = NULL;
	}
}

void	ft_next_main(t_list **stack_a, t_list **stack_b, int ac, char **av)
{
	*stack_a = NULL;
	*stack_b = NULL;
	ft_create_stack(stack_a, ac, av);
	if (ft_size_stack(stack_a) <= 1 || !ft_check_sort(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		free(stack_a);
		free(stack_b);
		return ;
	}
	ft_sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac < 2)
		return (0);
	if (!ft_check_argum(ac, av))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_a || !stack_b)
	{
		if (stack_a)
			free(stack_a);
		if (stack_b)
			free(stack_b);
		return (0);
	}
	ft_next_main(stack_a, stack_b, ac, av);
	return (0);
}
