/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:54:53 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/24 21:00:17 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "action_defs.h"

static void move(t_stack *stk)
{
    t_list  *actions;
    int     *limits;

    while (ft_lstsize(stk->stack_a) > 3)
    {
        limits = stk_limits(stk->stack_b);
        actions = calculate_moves(stk, limits, 0);
        parse_move(stk, actions);
        free(limits);
        ft_lstclear(&actions, (void *) ft_delete);
    }
    sort_3(stk);
    while (ft_lstsize(stk->stack_b) > 0)
    {
        limits = stk_limits(stk->stack_a);
        actions  = calculate_moves(stk, limits, 1);
        parse_move(stk, actions);
        free(limits);
        ft_lstclear(&actions, (void *)ft_delete);
    }
    rotate_finish(stk);
}

void    init_sort(t_stack *stk)
{
    if (finish_check(stk) < 1)
    {
        push_b(stk, 1);
        if (ft_lstsize(stk->stack_a) > 3)
            push_b(stk, 1);
        move(stk);
    }
}