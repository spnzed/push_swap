/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:59:22 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/03 22:24:01 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void    reverse_rotate_a(t_stack *stk, int print)
{
    t_list  *lst;
    t_list  *aux;
    int     i;

    if (ft_lstsize(stk->stack_a) > 1)
    {
        aux = stk->stack_a;
        lst = ft_lstlast(aux);
        i = ft_lstsize;
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
        i = ft_lstsize;
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