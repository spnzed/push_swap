/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:18:16 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/25 00:08:46 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int *find_p(int n, t_list *lst, int phase)
{
    t_list  *aux;
    int     *i;
    int     *target;

    aux = lst;
    target = NULL;
    while (aux)
    {
        i = aux->content;
        if (!target)
        {
            if ((phase == 0 && *i < n) || (phase == 1 && *i > n))
                target = i;
        }
        else
        {
            if ((phase == 0 && *i < n && *i > *target)
            || (phase == 1 && *i > n && *i < *target))
            target = i;
        }
        aux = aux->next;
    }
    return (target);
}

static t_list *get_cheapest(t_list *tmp_act, t_list *cheapest_act, int stack)
{
    if (ft_lstsize(tmp_act) > 1)
        check_merge(&tmp_act);
    add_push(&tmp_act, stack);
    if (!cheapest_act)
        cheapest_act = tmp_act;
    else if (ft_lstsize(cheapest_act) > ft_lstsize(tmp_act))
    {
        ft_lstclear(&cheapest_act, (void *)ft_delete);
        cheapest_act = tmp_act;
    }
    else
        ft_lstclear(&tmp_act, (void *)ft_delete);
    return (cheapest_act);
}

static t_list   *get_temp(t_stack *stk, int *aux, int *limits, int id)
{
    t_list  *tmp;

    tmp = ft_lstnew(NULL);
    if (id == 0 && (*aux > limits[1] || *aux < limits[0]))
    {
        calc_rot(stk->stack_b, &limits[1], 1, &tmp);
        calc_rot(stk->stack_a, aux, 0, &tmp);
    }
    else if (id == 0)
    {
        calc_rot(stk->stack_b, find_p(*aux, stk->stack_b, 0), 1, &tmp);
        calc_rot(stk->stack_a, aux, 0, &tmp);
    }
    else if (id == 1 && (*aux > limits[1] || *aux < limits[0]))
    {
        calc_rot(stk->stack_a, &limits[0], 0, &tmp);
        calc_rot(stk->stack_b, aux, 1, &tmp);
    }
    else if (id == 1)
    {
        calc_rot(stk->stack_a, find_p(*aux, stk->stack_a, 1), 0, &tmp);
        calc_rot(stk->stack_b, aux, 1, &tmp);
    }
    return (tmp);
}

t_list  *calculate_moves(t_stack *stk, int *limits, int id)
{
    t_list  *cheap;
    t_list  *tmp;
    t_list  *aux;

    aux = stk->stack_a;
    if (id == 1)
        aux = stk->stack_b;
    cheap = NULL;
    while (aux)
    {
        tmp = get_temp(stk, aux->content, limits, id);
        cheap = get_cheapest(tmp, cheap, id);
        aux = aux->next;
    }
    return (cheap);
}
