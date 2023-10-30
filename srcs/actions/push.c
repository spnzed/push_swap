/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:29:29 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/30 19:05:33 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **stack_a, t_node **stack_b)
{
	t_node	*head_a;

	if (!*stack_a)
		return ;
	head_a = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	if ((*stack_b)->is_end)
	{
		head_a->prev = NULL;
		head_a->next = NULL;
		*stack_b = head_a;
	}
	else
	{
		ft_lstadd_flinked(stack_b, head_a);
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
