/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:41:18 by aaespino          #+#    #+#             */
/*   Updated: 2023/11/06 12:42:25 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_back(t_node *a, t_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(b, a, 'b');
}

void	ft_move_back(t_node **a, t_node **b)
{
	finish_rotation(a, (*b)->target, 'a');
	pa(b, a);
}
