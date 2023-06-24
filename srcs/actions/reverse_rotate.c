/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:59:22 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/25 01:11:29 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "action_lst.h"

void    reverse_rotate_a(t_stack *stk, int print)
{
    t_list  *lst;
    t_list  *aux;
    int     i;

    if (ft_lstsize(stk->stack_a) > 1)
    {
        aux = stk->stack_a;
        lst = ft_lstlast(aux);
        i = ft_lstsize(aux);
        while (aux->next && i > 2)
        {
            aux = aux->next;
            i--;
        }
        aux->next = NULL;
        lst->next = stk->stack_a;
        stk->stack_a = lst;
    }
    if (print > 0)
        ft_printf("rra\n");
}

void    reverse_rotate_b(t_stack *stk, int print)
{
    t_list  *lst;
    t_list  *aux;
    int     i;

    if (ft_lstsize(stk->stack_b) > 1)
    {
        aux = stk->stack_b;
        lst = ft_lstlast(aux);
        i = ft_lstsize(aux);
        while (aux->next && i > 2)
        {
            aux = aux->next;
            i--;
        }
        aux->next = NULL;
        lst->next = stk->stack_b;
        stk->stack_b = lst;
    }
    if (print > 0)
        ft_printf("rrb\n");
}

void    reverse_rotate_r(t_stack *stk, int print)
{
    reverse_rotate_a(stk, 0);
    reverse_rotate_b(stk, 0);
    if (print > 0)
        ft_printf("rrr\n");
}