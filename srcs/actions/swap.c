/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:31:21 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/03 22:38:37 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

static t_list   *swap(t_list *stack)
{
    t_list  *aux;
    t_list  *first;
    t_list  *second;

    first = stack;
    second = stack->next;
    aux = NULL;
    if (second->next)
        aux = second->next;
    first->next = NULL;
    second->next = NULL;
    ft_lstadd_front(&aux, first);
    ft_lstadd_front(&aux, second);
    return(aux);
}

void    swap_a(t_stack *stk, int print)
{
    if (ft_lstsize(stk->stack_a) > 1)
        stk->stack_a = swap(stk->stack_a);
    if (print > 0)
        ft_printf("sa\n");
}

void    swap_b(t_stack *stk, int print)
{
    if (ft_lstsize(stk->stack_b) > 1)
        stk->stack_b = swap(stk->stack_b);
    if (print > 0)
        ft_printf("sb\n");
}

void    swap_s(t_stack *stk, int print)
{
    swap_a(stk, 0);
    swap_b(stk, 0);
    if (print > 0)
        ft_printf("ss\n");
}
