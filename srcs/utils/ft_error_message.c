/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:13:33 by aaespino          #+#    #+#             */
/*   Updated: 2023/11/07 19:14:53 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//1 not valid input
//2 input is not a digit
//3 duplicated digits
//4 number exceeds int MIN
//5 number exceeds int MAX
int	ft_error_message(char num)
{
	if (num)
	{
		if (num == '0')
			ft_putstr_fd("Error\n", 2);
		if (num == '1')
			ft_putstr_fd("Error\n", 2);
		if (num == '2')
			ft_putstr_fd("Error\n", 2);
		if (num == '3')
			ft_putstr_fd("Error\n", 2);
		if (num == '4')
			ft_putstr_fd("Error\n", 2);
		if (num == '5')
			ft_putstr_fd("Error\n", 2);
		return (1);
	}
	else
		return (0);
}
