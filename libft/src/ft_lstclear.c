/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:59:53 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/01 11:06:35 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void    ft_lstclear(t_list **lst, void(*del)(void *))
{
    t_list  *aux;

    aux = *lst;
    while (aux)
    {
        *lst = aux->next;
        (*del) (aux->content);
        free(aux);
        aux = *lst;
    }
    *lst = NULL;
}