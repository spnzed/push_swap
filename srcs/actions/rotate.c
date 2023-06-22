/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:24:30 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/03 22:31:02 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void    rotate_a(t_stack *stk, int print)
{
    t_list  *aux;
    t_list  *f;

    if (ft_lstsize(stk->stack_a) > 1)
    {
        aux = stk->stack_a;
        stk->stack_a = stk->stack_a->next;
        f = ft_lstlast(stk->stack_a);
        aux->next = NULL;
        f->next = aux;
    }
    if (print > 0)
        ft_printf("ra\n");
}

void    rotate_b(t_stack *stk, int print)
{
    t_list  *aux;
    t_list  *f;

    if (ft_lstsize(stk->stack_b) > 1)
    {
        aux = stk->stack_b;
        stk->stack_b = stk->stack_b->next;
        f = ft_lstlast(stk->stack_b);
        aux->next = NULL;
        f->next = aux;
    }
    if (print > 0)
        ft_printf("rb\n");
}

void    rotate_r(t_stack *stk, int print)
{
    rotate_a(stk, 0);
    rotate_b(stk, 0);
    if (print > 0)
        ft_printf("rr\n");
}
