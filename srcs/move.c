/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:54:53 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/22 11:13:13 by aaespino         ###   ########.fr       */
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

void    parse_move(t_stack *stk, t_list *actions)
{
    t_list  *aux;
    int     *act;

    aux = actions;
    while (aux)
    {
        act = aux->content;
        if (*act == PUSH_A)
            push_a(stk, 1);
        else if (*act == PUSH_B)
            push_b(stk, 1);
        else if (*act == ROTATE_A)
            rotate_a(stk, 1);
        else if (*act == ROTATE_B)
            rotate_b(stk, 1);
        else if (*act == ROTATE_R)
            rotate_r(stk, 1);
        else if (*act == REV_ROTATE_A)
            reverse_rotate_a(stk, 1);
        else if (*act == REV_ROTATE_B)
            reverse_rotate_b(stk, 1);
        else if (*act == REV_ROTATE_R)
            reverse_rotate_r(stk, 1);
        aux = aux->next;
    }
}
