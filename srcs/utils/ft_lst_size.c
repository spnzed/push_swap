/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:07:37 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/19 16:48:29 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_size(t_node *node)
{
	int i;

	i = 0;
	if (!node)
		return (0);
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
