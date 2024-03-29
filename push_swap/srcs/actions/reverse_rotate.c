/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:29:37 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/31 17:42:11 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **head)
{
	t_node	*first;
	t_node	*aux;
	t_node	*last;
	t_node	*new_end;

	if (ft_lst_size(*head) > 1)
	{
		first = *head;
		last = ft_lst_last(*head);
		new_end = last->prev;
		new_end->next = NULL;
		last->prev = NULL;
		if (first->next)
			aux = first;
		ft_lstadd_flinked(head, last);
	}
	else
		return ;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
