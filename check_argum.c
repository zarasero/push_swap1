/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:12:22 by zserobia          #+#    #+#             */
/*   Updated: 2024/07/23 11:47:15 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free( char **str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

int	ft_check_double(int tmp, char **av1, int i)
{
	while (av1[++i])
	{
		if (ft_atoi(av1[i]) == tmp)
		{
			return (0);
		}
	}
	return (1);
}

int	ft_check_digit(char *av)
{
	int	i;

	i = 0;
	if (av[0] == '-')
		i++;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_argum_1(int ac, char **av1, int i)
{
	long	tmp;

	while (av1[i])
	{
		tmp = ft_atoi(av1[i]);
		if (!ft_check_digit(av1[i]) || !ft_check_double(tmp, av1, i)
			|| (tmp < INT_MIN || tmp > INT_MAX) || !av1[i][0])
		{
			if (ac == 2)
				ft_free(av1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_argum(int ac, char **av)
{
	char	**av1;
	int		i;

	i = 0;
	if (ac == 2)
		av1 = ft_split(av[1], ' ');
	else
	{
		av1 = av;
		i = 1;
	}
	if (!ft_check_argum_1(ac, av1, i))
		return (0);
	if (ac == 2)
		ft_free(av1);
	return (1);
}
