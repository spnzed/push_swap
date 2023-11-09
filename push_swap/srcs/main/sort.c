/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:56:17 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/31 17:41:59 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reorder(t_node **stack)
{
	t_node	*smallest;

	smallest = ft_find_smallest(*stack);
	while ((*stack)->value != smallest->value)
	{
		if (smallest->exceeds_center == true)
			ra(stack);
		else
			rra(stack);
	}
}

void	ft_lil_sort(t_node **stack)
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

void	ft_sort(t_node **a, t_node **b)
{
	int	len_a;

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
	while (*b)
	{
		ft_init_back(*a, *b);
		ft_move_back(a, b);
	}
	set_current_position(*a);
	ft_reorder(a);
}
