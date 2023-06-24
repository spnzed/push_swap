/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 10:20:01 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/24 20:47:18 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int finish_check(t_stack *stk)
{
    int *max;
    int *min;
    int *n;
    t_list  *lst;

    lst = stk->stack_a;
    max = lst->content;
    min = lst->content;
    while (lst->next)
    {
        n = lst->next->content;
        if (*n > *max && *n > *min)
        {
            max = lst->next->content;
            lst = lst->next;
        }
        else
            return (0);
    }
    return (1);
}

void    sort_3(t_stack *stk)
{
    int     *i;
    int     *j;
    int     *k;

    while (finish_check(stk) < 1)
    {
        if (ft_lstsize(stk->stack_a) < 3)
            swap_a(stk, 1);
        else
        {
            i = stk->stack_a->content;
            j = stk->stack_a->next->content;
            k = stk->stack_a->next->next->content;
            if (*j > *i && *j > *k)
                reverse_rotate_a(stk, 1);
            else if (*i > *j && *i > *k)
                rotate_a(stk, 1);
            else if (*i > *j && *i < *k)
                swap_a(stk, 1);
        }
    }
}
