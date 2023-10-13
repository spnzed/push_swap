/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:13:33 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/13 18:41:26 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_error_message(char num)
{
    if (num)
    {
        if (num == '0')
            ft_putstr_fd("Error\n", 2); 
	    if (num == '1')
		    ft_putstr_fd("Error, not valid input\n", 2);
	    if (num == '2')
		    ft_putstr_fd("Error, input is not a digit\n", 2);
	    if (num == '3')
		    ft_putstr_fd("Error, duplicated digits\n", 2);
        if (num == '4')
		    ft_putstr_fd("Error, number exceeds int MIN\n", 2);
        if (num == '5')
		    ft_putstr_fd("Error, number exceeds int MAX\n", 2);
        return (1);
    }
    else
        return (0);
}
