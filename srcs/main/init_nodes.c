/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:32:35 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/23 18:51:44 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void set_current_position(t_node *stack)
{
	int i;
	int center;

	i = 0;
	if(!stack)
		return ;
	center = ft_lst_size(stack) / 2;
	while (stack)
	{
		if (i <= center)
			stack->exceeds_center = false;
		else
			stack->exceeds_center = true;
		i++;
		stack = stack->next;
	}
}

static void set_target_node(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target;
	int		match;

	while (a)
	{
		current_b = b;
		match = INT_MAX;
		while (current_b)
		{
			if (a->value < current_b->value && 
			current_b->value < match)
			{
				match = current_b->value;
				target = current_b;
			}
			current_b->next;
		}
		if (match == INT_MAX)
			a->target = ft_find_smallest(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void set_price(t_node *a, t_node *b)
{
	
}


void ft_init_nodes(t_node *a, t_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
