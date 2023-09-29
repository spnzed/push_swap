/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:29:41 by aaronespino       #+#    #+#             */
/*   Updated: 2023/09/29 16:28:27 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "action_defs.h"
#include <stdlib.h>
#include <stdio.h>

void error_message(char num)
{
    if (num == '0')
        ft_putstr_fd("Error\n", 2); 
	if (num == '1')
		ft_putstr_fd("Error, not valid digit\n", 2);
	if (num == '2')
		ft_putstr_fd("Error, input is not a digit\n", 2);
	if (num == '3')
		ft_putstr_fd("Error, duplicated digits\n", 2);
	if (num == '4')
		ft_putstr_fd("Error, not able to work with input\n", 2);
}

void    push_swap(char **str)
{
    int size;
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (0);
    stack->stack_a =  parsing_input(str);
    if (stack->stack_a)
    {
        stack->stack_b = NULL;
        size = ft_lstsize(stack->stack_a);
        if (size > 1 && size <= 3)
            sort_3(stack);
        else
            sort_algorithm(stack);
        ft_lstclear(&stack->stack_b, (void *)ft_delete);
    }
    if (stack->stack_a)
        ft_lstclear(&stack->stack_a, (void *)ft_delete);
    free(stack);
}

int main(int argc, char *argv[])
{
    if (argc > 1)
        push_swap(argv);
    else
        error_message('0');
    return (0);
}