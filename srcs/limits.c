/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:08:58 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/06 08:15:52 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
