/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_blinked.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:55:04 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/18 21:10:45 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_blinked(t_node **lst, t_node *new)
{
	t_node	*aux;

	aux = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
}
