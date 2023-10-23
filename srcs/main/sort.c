/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:56:17 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/23 17:31:58 by aaespino         ###   ########.fr       */
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

void ft_BIG_sort(t_node **stack)
{
	
}

void ft_sort(t_node **a, t_node **b)
{
	t_node 	smallest;
	int 	len_b;

	len_b = ft_lst_size(b);
	while (len_b-- < 3)
		pb(a, b);
	while (*a)
	{
		ft_init_nodes(a, b);
		ft_move_nodes();
	}
}