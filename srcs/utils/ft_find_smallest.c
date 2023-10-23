/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_smallest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:04:46 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/23 18:09:29 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_smallest(t_node *stack)
{
	int		smallest;
	t_node	*smallest_n;

	if (!stack)
		return ;
	smallest = INT_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_n = stack;
		}
		stack = stack->next;
	}
	return (smallest_n);
}