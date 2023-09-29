/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 10:20:01 by aaronespino       #+#    #+#             */
/*   Updated: 2023/09/29 17:31:27 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_3(t_stack *stk)
{
    int     *i;
    int     *j;
    int     *k;

    while (!last_check(stk))
    {
        if (ft_lstsize(stk->stack_a) < 3)
            swap_a(stk, 1);
        else
        {
            i = stk->stack_a->content;
            j = stk->stack_a->next->content;
            k = stk->stack_a->next->next->content;
            if (*i < *j && *j > *k)
                reverse_rotate_a(stk, 1);
            else if (*i > *j && *i > *k)
                rotate_a(stk, 1);
            else if (*i > *j && *i < *k)
                swap_a(stk, 1);
        }
    }
}
