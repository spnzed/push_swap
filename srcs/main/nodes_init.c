/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:32:35 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/24 18:46:39 by aaespino         ###   ########.fr       */
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
			stack->exceeds_center = true;
		else
			stack->exceeds_center = false;
		i++;
		stack = stack->next;
	}
}

static void set_target_node(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target;
	long	match_index;

	while (a)
	{
		match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (a->value > current_b->value && 
			current_b->value > match_index)
			{
				match_index = current_b->value;
				target = current_b;
			}
			current_b->next;
		}
		if (match_index == LONG_MIN)
			a->target = ft_find_biggest(b);
		else
			a->target = target;
		a = a->next;
	}
}

// static void set_price(t_node *a, t_node *b)
// {
// 	int len_a;
// 	int len_b;

// 	len_a = ft_lst_size(a);
// 	len_b = ft_lst_size(b);
// 	while (a)
// 	{
// 		a->push_price = a->index;
// 		if (a->exceeds_center == false)
// 			a->push_price = len_a - (a->index);
// 		if (a->exceeds_center == true)
// 			a->push_price += a->target->index;
// 		a = a->next;
// 	}
// }

static void	set_cheapest(t_node *stack)
{
	long	cheapest_value;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	while (stack)
	{
		cheapest_value = LONG_MIN;
		if (stack->push_price > cheapest_value)
		{
			cheapest_value = stack->push_price;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void ft_init_nodes(t_node *a, t_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
//	set_price(a, b);
	set_cheapest(a);
}
