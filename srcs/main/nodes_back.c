/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:41:18 by aaespino          #+#    #+#             */
/*   Updated: 2023/11/06 12:59:51 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	set_target_back(t_node *a, t_node *b)
{
	t_node	*target;
	t_node	*current_b;
	long	best_index;

	current_b = b;
	best_index = LONG_MAX;
	while (a)
	{
		while (current_b)
		{
			if (best_index > current_b->value
				&& current_b->value > a->value)
			{
				best_index = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_index == LONG_MAX)
			a->target = ft_find_smallest(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	ft_init_back(t_node *a, t_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_back(b, a);
}

void	ft_move_back(t_node **a, t_node **b)
{
	finish_rotation(a, (*b)->target, 'a');
	pa(b, a);
}
