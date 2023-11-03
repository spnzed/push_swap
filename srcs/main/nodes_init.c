/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:32:35 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/31 15:33:41 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_node *stack)
{
	int	i;
	int	center;

	i = 0;
	if (!stack)
		return ;
	center = ft_lst_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= center)
			stack->exceeds_center = true;
		else
			stack->exceeds_center = false;
		stack = stack->next;
		i++;
	}
}

void	set_target_node(t_node *a, t_node *b, char which)
{
	t_node	*target;
	t_node	*current_b;
	long	best_index;

	current_b = b;
	if (which == 'a')
		best_index = LONG_MIN;
	else
		best_index = LONG_MAX;
	while (a)
	{
		while (current_b)
		{
			if (best_index < current_b->value &&
				current_b->value < a->value && which == 'a')
			{
				best_index = current_b->value;
				target = current_b;
			}
			else if (best_index > current_b->value &&
				current_b->value > a->value && which == 'b')
			{
				best_index = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_index == LONG_MIN && which == 'a')
			a->target = ft_find_biggest(b);
		else if (best_index == LONG_MAX && which == 'b')
			a->target = ft_find_smallest(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void set_price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lst_size(a);
	len_b = ft_lst_size(b);
	while (a)
	{
		a->price = a->index;
		if (a->exceeds_center == false)
			a->price = len_a - (a->index);
		if (a->target->exceeds_center == true)
			a->price += a->target->index;
		else
			a->price += len_b - (a->target->index);
		a = a->next;
	}
}

static void set_cheapest(t_node *stack)
{
	t_node 	*cheapest_node;
	long	cheapest_price;

	cheapest_price = LONG_MAX;
	while (stack)
	{
		if (stack->price < cheapest_price)
		{
			cheapest_price = stack->price;
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
	set_target_node(a, b, 'a');
	set_price(a, b);
	set_cheapest(a);
}

void ft_init_back(t_node *a, t_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(b, a, 'b');
}
