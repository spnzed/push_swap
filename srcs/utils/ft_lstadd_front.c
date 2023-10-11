/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:14:34 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/11 16:26:26 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

typedef struct s_node
{
	int 			value;
	int 			current_position;
	int 			final_index;
	int 			push_price;
	struct node		*target;
	struct node		*next;
	struct node		*prev;
}	t_node;

void	ft_lstadd_flinked(t_node **lst, t_node *new)
{
	t_node	*aux;

	if (!*lst)
		*lst = new;
	else
	{
		aux = new;
		aux->next = *lst;
		aux->prev = NULL;
		*lst = aux;
	}
}