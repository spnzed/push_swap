/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:19:37 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/06 19:24:12 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//find_last_node debe hacer
//Recorre la lista hasta encontrar el ultimo
//	Entonces lo devuelves

t_node	*ft_last_node(t_node *head)
{
	if (!head)
		return (0);
	while (head->next);
		head = head->next;
	return (head);
}