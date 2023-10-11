/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:29:29 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/11 16:43:13 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **stack_a, t_node **stack_b, char flag)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	if (flag == 'a')
	{
		if (head_b != NULL)
			ft_lstadd_flinked(stack_a, head_b);
		else if (!stack_b)
			exit(1);
	}
	if (flag == 'b')
	{
		if (head_a != NULL)
			ft_lstadd_flinked(stack_b, head_a);
		else if (!stack_a)
			exit(1);
	}
}

void	pa(t_node **a, t_node **b, int checker)
{
	char c;

	c = 'a';
	push(a, b, c);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, int checker)
{
	char c;

	c = 'b';
	push(a, b, c);
	if (!checker)
		write(1, "pb\n", 3);
}
