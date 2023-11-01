/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:29:41 by aaronespino       #+#    #+#             */
/*   Updated: 2023/11/01 16:31:41 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node *init_stacks(t_node *stack_a, t_node *stack_b, bool flag)
{
    stack_a = malloc(sizeof(t_node));
    if (!stack_a)
        return (NULL);
    else if (flag == false)
        return (stack_a);
    stack_b = malloc(sizeof(t_node));
    if (!stack_b)
    {
        ft_free_stack(&stack_a);
        return (NULL);
    }
    return (stack_b);
}

static void arguments_check(int argc, char **argv)
{
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return ;
}

static void fill_stack(int argc, char **argv, t_node **stack_a)
{
    if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        gen_stack (stack_a, argv + 1, true);
    }
    else
        gen_stack (stack_a, argv, false);
}

static void init_sorts (t_node **stack_a, t_node **stack_b)
{
    if (!ft_lst_sorted(*stack_a))
    {
        if (ft_lst_size(*stack_a) == 2)
            sa(stack_a);
        else if (ft_lst_size(*stack_a) == 3)
            ft_lil_sort(stack_a);
        else
            ft_sort(stack_a, stack_b);
    }
}

int main (int argc, char **argv)
{
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;

    arguments_check(argc, argv);
    stack_a = init_stacks(stack_a, stack_b, false);
    stack_b = init_stacks(stack_a, stack_b, true);
    stack_a->is_end = true;
    stack_b->is_end = true;
    fill_stack(argc, argv, &stack_a);
    init_sorts(&stack_a, &stack_b);
    ft_print_stack(stack_a);
    ft_free_stack(&stack_a);
    return(0);
}
