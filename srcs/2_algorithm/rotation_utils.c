/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:28:32 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/24 23:37:27 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "action_defs.h"

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
