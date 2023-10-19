/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:29:41 by aaronespino       #+#    #+#             */
/*   Updated: 2023/10/19 16:13:15 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_stack(t_node *stack)
{
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

int main (int argc, char **argv)
{
    t_node *stack_a;
    t_node *stack_b;

    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    stack_a = malloc(sizeof(t_node));
    if (!stack_a)
        return (1);
    stack_b = malloc(sizeof(t_node));
    if (!stack_b)
    {
        ft_free_stack(&stack_a);
        return (1);
    }
    else if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        gen_stack (&stack_a, argv, argc == 2);
    }
    else
        gen_stack (&stack_a, argv + 1, false);
    ft_print_stack(stack_b);
    ft_free_stack(&stack_a);
    return(0);
}
