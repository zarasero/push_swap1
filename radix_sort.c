/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:27:47 by zserobia          #+#    #+#             */
/*   Updated: 2024/07/23 12:22:10 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_max_bit(t_list **stack_a)
{
	t_list	*new;
	int		max;
	int		count_bit;

	if (*stack_a == NULL)
		return (0);
	new = *stack_a;
	max = new->index;
	count_bit = 0;
	while (new)
	{
		if (new->index > max)
			max = new->index;
		new = new->next;
	}
	while ((max >> count_bit) != 0)
		count_bit++;
	return (count_bit);
}

/*void	ft_radix_sort_2(t_list **stack_a, t_list **stack_b, int count, int size)
{
	t_list	*new;
	int		count_bit;
	int		size_stack;

	new = *stack_a;
	count_bit = 0;
	while (count_bit < count)
	{
		size_stack = 0;
		while (size_stack < size)
		{
			if (((new->index >> count_bit) & 1) == 1)
			{
				//printf("Rotating: %d\n", new->index);
				ft_ra(stack_a);
			}
			else
			{
				ft_pb(stack_a, stack_b);
				//printf("hh");
			}
			size_stack++;
		}
		while (ft_size_stack(stack_b) > 0)
			ft_pa(stack_a, stack_b);
		count_bit++;
	}
}

void	ft_radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		count_bit;
	int		size_stack;

	count_bit = ft_count_max_bit(stack_a);
	printf("count bit %d\n", count_bit);
	size_stack = ft_size_stack(stack_a);
	//printf("rad\n");
	ft_radix_sort_2(stack_a, stack_b, count_bit, size_stack);
	//printf("gg");
}*/

/*void	ft_radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*new;
	int		count_bit;
	int		size_stack;
	int		count;
	int		size;

	count_bit = ft_count_max_bit(stack_a);
	//printf("count\n");
	size_stack = ft_size_stack(stack_a);
	count = 0;
	while (count < count_bit)
	{
		//printf("count11\n");
		size = 0;
		
		while (size < size_stack)
		{
			//printf("count12\n");
			new = *stack_a;
			if (((new->index >> count) & 1) == 1)
			{
				printf("index %d\n", new->index);
				ft_ra(stack_a);
			}
			else
			{
				//printf("l\n");
				ft_pb(stack_a, stack_b);
			}
			size++;
			//printf("size %d\n", size);
		}
		while (ft_size_stack(stack_b) > 0)
			ft_pa(stack_a, stack_b);
		count++;
	}
}*/

void	ft_radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		count_bit;
	int		size_stack;
	int		count;
	int		size;

	count_bit = ft_count_max_bit(stack_a);
	size_stack = ft_size_stack(stack_a);
	count = 0;
	while (count < count_bit)
	{
		size = 0;
		while (size < size_stack)
		{
			if ((((*stack_a)->index >> count) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
			size++;
		}
		while (ft_size_stack(stack_b) > 0)
			ft_pa(stack_a, stack_b);
		count++;
	}
}
