/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:29:41 by aaronespino       #+#    #+#             */
/*   Updated: 2023/08/29 15:55:05 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void    push_swap(char **str)
{
    int size;
    t_stack *stk;

    stk = malloc(sizeof(t_stack));
    stk->stack_a = parsing_i(str);
    if (stk->stack_a)
    {
        stk->stack_b = NULL;
        size = ft_lstsize(stk->stack_a);
        if (size > 1 && size <= 3)
            sort_3(stk);
        else
            init_sort(stk);
        ft_lstclear(&stk->stack_b, (void *)ft_delete);
    }
    if (stk->stack_a)
        ft_lstclear(&stk->stack_a, (void *)ft_delete);
    free(stk);
}

int main(int argc, char *argv[])
{
    if (argv[1] == 0)
    {
        ft_putstr_fd("Error\n", 2);
        return (0);
    }
    if (argc > 1)
        push_swap(argv);
    return (0);
}