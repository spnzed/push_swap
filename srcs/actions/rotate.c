/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:29:40 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/30 18:15:24 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **head)
{
	t_node *first;
	t_node *aux;
	
    if (ft_lst_size(*head) > 1)
    {
        first = (*head);
        aux = NULL;
	    if (first->next)
	 	    aux = (first)->next;
        (first)->next = NULL;
        ft_lstadd_blinked(&aux, first);
        *head = aux;
    }
    else
        return ;
}

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
