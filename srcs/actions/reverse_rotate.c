/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:29:37 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/13 18:04:30 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **head)
{
	t_node	*f;
	t_node	*aux;
	int		i;

	if (ft_lst_size(*head) > 1)
	{
		aux = *head;
		f = ft_lst_last(*head);
		i = ft_lst_size(aux);
		while (aux->next && i > 2)
		{
			aux = aux->next;
			i--;
		}
		aux->next = NULL;
		f->next = *head;
		head = &f;
	}
}

void	rra(t_node **a, int checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, int checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
