/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:16:35 by zserobia          #+#    #+#             */
/*   Updated: 2024/07/15 18:01:40 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct my_list
{
	int				value;
	int				index;
	struct my_list	*next;
}	t_list;

void	ft_free( char **str);
void	ft_next_main(t_list **stack_a, t_list **stack_b, int ac, char **av);
void	free_stack(t_list **stack);
void	ft_create_stack(t_list **stack_a, int ac, char **av);
void	ft_create_index(t_list **stack_a);
void	ft_tlist_add_back(t_list **stack_a, t_list *new_argum);
void	ft_sort_stack(t_list **stack_a, t_list **stack_b);
void	ft_sort_stack_5(t_list **stack_a, t_list **stack_b);
void	ft_sort_stack_4(t_list **stack_a, t_list **stack_b);
void	ft_sort_stack_3(t_list **stack_a);
void	ft_sort_3_next(t_list **stack_a, t_list *new, int min_index);
void	ft_radix_sort(t_list **stack_a, t_list **stack_b);
int		ft_count_max_bit(t_list **stack_a);
int		ft_check_argum(int ac, char **av);
int		ft_check_argum_1(int ac, char **av1, int i);
int		ft_swap(t_list **stack);
int		ft_sa(t_list **stack_a);
int		ft_sb(t_list **stack_b);
int		ft_ss(t_list **stack_a, t_list **stack_b);
int		ft_push(t_list **stack_dest, t_list **stack_push);
int		ft_pa(t_list **stack_a, t_list **stack_b);
int		ft_pb(t_list **stack_b, t_list **stack_a);
int		ft_rotate(t_list **stack);
int		ft_ra(t_list **stack_a);
int		ft_rb(t_list **stack_b);
int		ft_rr(t_list **stack_a, t_list **stack_b);
int		ft_rotate_reverse(t_list **stack);
int		ft_rra(t_list **stack_a);
int		ft_rrb(t_list **stack_b);
int		ft_rrr(t_list **stack_a, t_list **stack_b);
int		ft_check_digit(char *av);
int		ft_size_stack(t_list **stack);
int		ft_count_argum(t_list **stack);
int		ft_check_sort(t_list **stack);
int		ft_find_distance(t_list **stack_a, int min_index);
int		ft_new_min_index(t_list **stack_a, int min_index);
int		ft_isdigit(int a);
long	ft_atoi(const char *str);
int		main(int ac, char **av);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
t_list	*ft_tlist_create(int value);
t_list	*ft_last_argum(t_list **stack);
t_list	*ft_next_min_index(t_list **stack_a);
#endif
