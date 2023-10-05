/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:29:41 by aaronespino       #+#    #+#             */
/*   Updated: 2023/10/05 17:39:57 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int error_message(char num)
{
    if (num)
    {
        if (num == '0')
            ft_putstr_fd("Error\n", 2); 
	    if (num == '1')
		    ft_putstr_fd("Error, not valid digit\n", 2);
	    if (num == '2')
		    ft_putstr_fd("Error, duplicated digits\n", 2);
	    if (num == '3')
		    ft_putstr_fd("Error, input is not a digit\n", 2);
	    if (num == '4')
		    ft_putstr_fd("Error, not able to work with input\n", 2);
        return (1);
    }
    else
        return (0);
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
    gen_stack (&stack_a, argv + 1);
    if (!stack_sorted(stack_a))
    {
        
    }
    free(stack_a);
}
