/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_flinked.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:55:04 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/30 19:19:48 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_flinked(t_node **lst, t_node *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		new->prev = NULL;
		(*lst)->prev = new;
		*lst = new;
	}
}