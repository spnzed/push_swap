/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:27:26 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/19 19:10:36 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_node **head)
{
	t_node *aux;
	t_node *first;
	t_node *second;

	first = *head;
	second = (*head)->next;
	aux = NULL;
	if (second->next)
	 	aux = second->next;
	first->next = NULL;
	ft_lstadd_flinked(&aux, first);
	ft_lstadd_flinked(&aux, second);
    *head = aux;
}

void	sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
