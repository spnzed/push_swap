/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:11:45 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/01 11:15:43 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstpos(t_list *lst, int *value)
{
    int i;
    int *tmp;

    i = 0;
    tmp = lst->content;
    while (lst)
    {
        if (*tmp == *value)
            return (i);
        lst = lst->next;
        tmp = lst->content;
        i++;
    }
    return (i);
}