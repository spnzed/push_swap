/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:46:42 by aaespino          #+#    #+#             */
/*   Updated: 2023/11/06 12:46:23 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rrr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

static t_node	*ft_return_cheapest(t_node *stack)
{
	t_node	*cheapest;

	if (!stack)
		return (NULL);
	cheapest = NULL;
	while (stack)
	{
		if (stack->cheapest == true)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	finish_rotation(t_node **stack, t_node *top, char which)
{
	int	val;

	val = top->value;
	while ((*stack)->value != val)
	{
		if (which == 'a')
		{
			if (top->exceeds_center == true)
				ra(stack);
			else
				rra(stack);
			if ((*stack)->value == val)
				break ;
		}
		else if (which == 'b')
		{
			if (top->exceeds_center == true)
				rb(stack);
			else
				rrb(stack);
			if ((*stack)->value == val)
				break ;
		}
	}
}

void	ft_move_nodes(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = ft_return_cheapest(*a);
	if (cheapest->exceeds_center == true
		&& cheapest->target->exceeds_center == true)
		rotate_both(a, b, cheapest);
	else if (cheapest->exceeds_center == false
		&& cheapest->target->exceeds_center == false)
		reverse_rotate_both(a, b, cheapest);
	finish_rotation(a, cheapest, 'a');
	finish_rotation(b, cheapest->target, 'b');
	pb(b, a);
}
