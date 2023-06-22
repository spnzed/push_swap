/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:14:01 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/03 22:14:26 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void    push_a(t_stack *stk, int print)
{
    t_list *lst;

    if (ft_lstsize(stk->stack_b) > 0)
    {
        lst = stk->stack_b;
        stk->stack_b = stk->stack_b->next;
        lst->next = NULL;
        ft_lstadd_front(&stk->stack_a, lst);
    }
    if (print > 0)
        ft_printf("pa\n");
}

void    push_b(t_stack *stk, int print)
{
    t_list *lst;

    if (ft_lstsize(stk->stack_a) > 0)
    {
        lst = stk->stack_a;
        stk->stack_a = stk->stack_a->next;
        lst->next = NULL;
        ft_lstadd_front(&stk->stack_b, lst);
    }
    if (print > 0)
        ft_printf("pb\n");
}
