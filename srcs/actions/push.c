/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:29:29 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/19 16:13:04 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **stack_a, t_node **stack_b)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	if (head_b != NULL)
		ft_lstadd_flinked(stack_a, head_b);
	else if (!stack_b)
		exit(1);
}

void	pa(t_node **a, t_node **b, int checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, int checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
