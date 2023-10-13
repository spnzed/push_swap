/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:29:41 by aaronespino       #+#    #+#             */
/*   Updated: 2023/10/13 20:53:16 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_stack(t_node *stack)
{
    while (stack->next)
    {
        printf("%d", stack->value);
        stack = stack->next;
    }
}

int main (int argc, char **argv)
{
    t_node *stack_a;
    t_node *stack_b;

    stack_a = NULL;
    stack_b = NULL;

    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    printf("fff");
    gen_stack (&stack_a, &argv[1], argc);
    printf("ddd");
    ft_print_stack(stack_a);
    // if (!stack_sorted(stack_a))
    // {
        
    // }
    free(stack_a);
}
