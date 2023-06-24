/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:18:16 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/25 01:16:38 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "action_defs.h"
# include "libft.h"

int *stk_limits(t_list *lst)
{
    t_list *aux;
    int *limits;

    limits = malloc(sizeof(int) * 2);
    aux = lst;
    limits[0] = *(int *)aux->content;
    limits[1] = *(int *)aux->content;
    while (aux)
    {
        if (*(int *)aux->content > limits[1])
            limits[1] = *(int *)aux->content;
        else if (*(int *)aux->content < limits[0])
            limits[0] = *(int *)aux->content;
    }
    return (limits);
}
