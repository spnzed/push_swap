/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:33:35 by aaespino          #+#    #+#             */
/*   Updated: 2023/09/29 17:00:01 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>

int last_check(t_stack *stk)
{
    int *max;
    int *min;
    int *n;
    t_list  *lst;

    lst = stk->stack_a;
    max = lst->content;
    min = lst->content;
    while (lst->next)
    {
        n = lst->next->content;
        if (*n > *max && *n > *min)
        {
            max = lst->next->content;
            lst = lst->next;
        }
        else
            return (0);
    }
    return (1);
}

char    *check_zeros(char *input)
{
    char c;

    while (*input == ' ')
        input++;
    if ((input[0] == '-' || input[0] == '+') && input[1] == '0')
    {
        c = input[0];
        while (*(input + 1) == '0' && *(input + 2))
            input++;
        if (c == '+')
            input++;
        else if (input[1] != '0')
            input[0] = c;
        else
            input[0] = '0';
    }
    return (input);
}

int check_duplicates(t_list *stack)
{
    t_list  *aux;
    t_list  *current;
    int     *j;

    current = stack;
    aux = current->next;
    while (aux)
    {
        j = aux->content;
        if (*(int *) current->content == *j)
            return (0);
        if (aux->next)
            aux = aux->next;
        else if (current->next)
        {
            current = current->next;
            aux = current->next;
        }
    }
    return (1);
}

int check_digits(char *str)
{
    int i;

    i = 0;
    while (*(str + i))
    {
        if (i > 0 && ft_isdigit(*(str + i -1))
        && (*(str + i) == '-' || (*(str + i) == '+')))
            return(0);
        else if (ft_isdigit(*(str + 1)) || *(str + 1) == ' '
        || ((*(str + i) == '-') && ft_isdigit(*(str + i + 1)))
        || ((*(str + i) == '+') && ft_isdigit(*(str + i + 1))))
        i++;
        else
            return (0);
    }
    return (1);
}

static int	check_limits(long j)
{
	int	i;

	if (j > INT_MAX || j < INT_MIN)
		return (0);
	else
	{
		i = (int)j;
		return (i);
	}
}
