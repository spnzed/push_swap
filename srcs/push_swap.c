/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:29:41 by aaronespino       #+#    #+#             */
/*   Updated: 2023/10/16 23:51:02 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void ft_print_stack(t_node *stack)
// {
//     while (stack->next)
//     {
//         printf("%d", stack->value);
//         stack = stack->next;
//     }
// }

int main (int argc, char **argv)
{
    t_node *stack_a;

    stack_a = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    gen_stack (&stack_a, argv + 1);
    ft_free_stack(&stack_a);
    return(0);
}
