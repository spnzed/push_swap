/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:24:40 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/24 21:30:21 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    parse_move(t_stack *stk, t_list *actions)
{
    t_list  *aux;
    int     *act;

    aux = actions;
    while (aux)
    {
        act = aux->content;
        if (*act == PUSH_A)
            push_a(stk, 1);
        else if (*act == PUSH_B)
            push_b(stk, 1);
        else if (*act == ROTATE_A)
            rotate_a(stk, 1);
        else if (*act == ROTATE_B)
            rotate_b(stk, 1);
        else if (*act == ROTATE_R)
            rotate_r(stk, 1);
        else if (*act == REV_ROTATE_A)
            reverse_rotate_a(stk, 1);
        else if (*act == REV_ROTATE_B)
            reverse_rotate_b(stk, 1);
        else if (*act == REV_ROTATE_R)
            reverse_rotate_r(stk, 1);
        aux = aux->next;
    }
}

static void add_actions(t_list **lst, int action, int times)
{
    t_list  *aux;
    int     *tmp;

    aux = *lst;
    while (times)
    {
        tmp = malloc(sizeof(int));
        *tmp = action;
        if (!aux->content)
            aux->content = tmp;
        else
            ft_lstadd_back(lst, ft_lstnew(tmp));
        times--;
    }
}

static t_list   *merge_actions(t_actions **acts)
{
    t_list      *lst;
    t_actions   *actions;

    actions = *acts;
    lst = ft_lstnew(NULL);
	if (*actions->ra > 0)
		add_actions(&lst, ROTATE_A, *actions->ra);
	if (*actions->rb > 0)
		add_actions(&lst, ROTATE_B, *actions->rb);
	if (*actions->rra > 0)
		add_actions(&lst, REV_ROTATE_A, *actions->rra);
	if (*actions->rrb > 0)
		add_actions(&lst, REV_ROTATE_B, *actions->rrb);
	if (*actions->rr > 0)
		add_actions(&lst, ROTATE_R, *actions->rr);
	if (*actions->rrr > 0)
		add_actions(&lst, REV_ROTATE_R, *actions->rrr);
    return (lst);
}

static void check_merge_2(t_list **lst, t_actions **acts)
{
    t_list      *aux;
    t_actions   *actions;

    aux = *lst;
    actions = *acts;
    while (*actions->ra > 0 && *actions->rb > 0)
    {
        *actions->rr += 1;
        *actions->ra -= 1;
        *actions->rb -= 1;
    }
    while (*actions->rra > 0 && *actions->rrb > 0)
    {
        *actions->rrr += 1;
        *actions->rra -= 1;
        *actions->rrb -= 1;
    }
    if (*actions->rr > 0 || *actions->rrr > 0)
    {
        *lst = merge_actions(acts);
        ft_lstclear(&aux, (void *)ft_delete);
    }
}

void    check_merge(t_list **lst)
{
    int         *tmp;
    t_list      *aux;
    t_actions   *actions;

    aux = *lst;
    actions = malloc(sizeof(t_actions));
    actions_init(&actions);
    while (aux)
    {
        tmp = aux->content;
        if (tmp && actions)
        {
            if (*tmp == ROTATE_A)
                *actions->ra += 1;
            else if (*tmp == ROTATE_B)
                *actions->rb += 1;
            else if (*tmp == REV_ROTATE_A)
                *actions->rra += 1;
            else if (*tmp == REV_ROTATE_A)
                *actions->rrb += 1;
        }
        aux = aux->next;
    }
    check_merge_2(lst, &actions);
    actions_clear(&actions);
}