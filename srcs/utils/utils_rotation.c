/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:28:32 by aaronespino       #+#    #+#             */
/*   Updated: 2023/09/29 18:00:55 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "action_defs.h"

static void fill_list(t_list **lst, int amount, int *value)
{
    t_list  *aux;
    int     *n;

    aux = *lst;
    while (amount)
    {
        n = malloc(sizeof(int));
        *n = *value;
        if (!aux->content)
            aux->content = n;
        else
            ft_lstadd_back(lst, ft_lstnew(n));
        amount--;
    }
}

void    *calc_rot(t_list *lst, int *value, int stack, t_list **action)
{
    int n;
    int i;

    i = 0;
    if (ft_lstpos(lst, value) >= 1)
    {
        if (ft_lstpos(lst, value) < ft_lstsize(lst) / 2)
        {
            i = ft_lstpos(lst, value);
            n = ROTATE_B;
            if (stack < 1)
                n = ROTATE_A;
        }
        else
        {
            i = ft_lstsize(lst) - ft_lstpos(lst, value);
            n = REV_ROTATE_B;
            if (stack < 1)
                n = REV_ROTATE_A;
        }
        fill_list(action, i , &n);
    }
    return (*action);
}

void    add_push(t_list **action, int stack)
{
    int n;

    n = PUSH_A;
    if (stack < 1)
        n = PUSH_B;
    fill_list(action, 1, &n);
}

int ft_atol(const char *str)
{
    int     i;
    long    j;

    i = 0;
    j = 0;
    while (*str == ' ' || *str == '\t' || *str == '\n'
        || *str == '\v' || *str == '\f' || *str == '\r')
            str++;
    while (*str == '-' || *str == '+')
    {
        if (*str == '-')
            i++;
        if (*(str + 1) == '+' || *(str + 1) == '-')
            return (0);
        str++;
    }
    while (ft_isdigit(*str))
    {
        j = (j * 10) + (*str - '0');
        str++;
    }
    if (i > 0)
        j *= -1;
    return (check_limits(j));
}