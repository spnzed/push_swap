/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:19:00 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/31 15:33:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool ft_lst_sorted(t_node *stack)
{
	if (!stack)
		return (false);
	while (stack->next)
	{
		if (stack->next->value < stack->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}
