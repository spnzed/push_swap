/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:28:32 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/24 21:30:26 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void rotate_finish(t_stack *stk)
{
    int     *limits;
    int     size;
    t_list  *aux;

    limits = NULL;
    aux = stk->stack_a;
    limits = stk_limits(aux);
    size = ft_lstsize(stk->stack_a) / 2;
    while (finish_check(stk) < 1)
    {
        if (ft_lstpos(stk->stack_a, &limits[0]) < size)
            rotate_a(stk, 1);
        else if (ft_lstpost(stk->stack_a, &limits[0]) >= size)
            reverse_rotate_a(stk, 1);
    }
    free(limits);
}

static void fill_list(t_list **lst, int amount, int *value)
{
    t_list  *aux;
    int     *n;

    aux = *lst;
    while (amount)
    {
        n = malloc(sizeof(int));
        *n = *value;
        if (!aux->content)
            aux->content = n;
        else
            ft_lstadd_back(lst, ft_lstnew(n));
        amount--;
    }
}

void    *calc_rot(t_list *lst, int *value, int stack, t_list **action)
{
    int n;
    int i;

    i = 0;
    if (ft_lstpos(lst, value) >= 1)
    {
        if (ft_lstpos(lst, value) < ft_lstsize(lst) / 2)
        {
            i = ft_lstpos(lst, value);
            n = ROTATE_B;
            if (stack < 1)
                n = ROTATE_A;
        }
        else
        {
            i = ft_lstsize(lst) - ft_lstpos(lst, value);
            n = REV_ROTATE_B;
            if (stack < 1)
                n = REV_ROTATE_A;
        }
        fill_list(action, i , &n);
    }
    return (*action);
}

void    add_push(t_list **action, int stack)
{
    int n;

    n = PUSH_A;
    if (stack < 1)
        n = PUSH_B;
    fill_list(action, 1, &n);
}
