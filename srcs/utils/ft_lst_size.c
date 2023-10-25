/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:07:37 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/25 16:56:24 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_size(t_node *node)
{
	int i;

	if (!node)
		return (0);
	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
