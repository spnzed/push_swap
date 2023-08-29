/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:50:31 by aaespino          #+#    #+#             */
/*   Updated: 2023/08/29 17:55:51 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void error_message(char num)
{
	if (num == '1')
		ft_putstr_fd("Error, not valid digit\n", 2);
	if (num == '2')
		ft_putstr_fd("Error, input is not a digit\n", 2);
	if (num == '3')
		ft_putstr_fd("Error, duplicated digits\n", 2);
	if (num == '4')
		ft_putstr_fd("Error, not able to work with input\n", 2);
}