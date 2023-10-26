/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:56:17 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/26 15:54:32 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_lil_sort(t_node **stack)
{
	int		first;
	int		second;
	int		third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && first < third)
		sa(stack);
	else if (first > second && first > third && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
}

// void ft_BIG_sort(t_node **a, t_node **b)
// {
// 	while (ft_lst_size(*a) > 3)
// 	{
// 		ft_init_nodes(*a, *b);
// 		ft_finish_rotation(a, ft_find_biggest(*a), 'a');
// 		pb(b, a);
// 	}
// 	ft_lil_sort(a);
// }

void ft_sort(t_node **a, t_node **b)
{
	int 	len_a;

	len_a = ft_lst_size(*a);
	if (len_a-- > 3 && !ft_lst_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !ft_lst_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !ft_lst_sorted(*a))
	{
		ft_init_nodes(*a, *b);
		ft_move_nodes(a, b);
	}
	ft_lil_sort(a);
	ft_print_stack(*a);
	ft_print_stack(*b);
}