/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:27:34 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/01 11:30:57 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list  *ft_lstnew(void *content)
{
    t_list  *new_list;

    new_list = malloc(sizeof(t_list));
    if (!new_list)
        return (NULL);
    new_list->content = content;
    new_list->next = NULL;
    return (new_list);
}