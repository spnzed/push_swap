/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:44:35 by aaespino          #+#    #+#             */
/*   Updated: 2023/09/29 18:11:24 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static char *join_input(char **input)
{
    char    *out;
    char    *aux;
    int     i;

    i = 1;
    out = malloc(sizeof(char *) * (ft_strlen(input[1] + 1)));
    ft_strlcpy(out, input[1], ft_strlen(input[1] + 1));
    while (input[i])
    {
        aux = out;
        input[i] = check_zeros(input[i]);
        out = ft_strjoin(out, " ");
        free(aux);
        aux = out;
        out = ft_strjoin(out, input[i]);
        free(aux);
        aux = out;

        i++;
    }
    return (out);
}

static t_list *convert_to_tlist(char **input)
{
    int i;
    int *k;
    t_list  *stack;

    i = 0;
    stack = NULL;
    while (input[i])
    {
        k = malloc(sizeof(int));
        *k = ft_atol(input[i]);
        if (*k || input[i][0] == '0')
            ft_lstadd_back(&stack, ft_lstnew(k));
        else
        {
            while (input[i])
                free(input[i++]);
            ft_lstclear(&stack, (void *)ft_delete);
            error_message('1');
            exit (1);
        }
        free(input[i]);
        i++;
    }
    return (stack);
}

t_list *parsing_input(char **str)
{
    char    *input;
    char    **out;
    t_list  *stack;

    input = join_input(str);
    if (!input)
	{
		error_message('4');
		return (NULL);
	}
    if (check_digits(input) < 1)
    {
        error_message('2');
        free(input);
        return (NULL);
    }
    out = ft_split(input, ' ');
    if (!out)
        return (NULL);
    free(input);
    stack = convert_to_tlist(out);
    free(out);
    if (check_duplicates(stack) < 1)
    {
        error_message('3');
        ft_lstclear(&stack, (void *)ft_delete);
        return (NULL);
    }
    return (stack);
}
