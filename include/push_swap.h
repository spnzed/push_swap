/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:48:55 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/06 08:50:20 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct lst_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack;

static  char     *join_input(char **input);
static  t_list   *convert_to_tlist(char **input);
t_list          *parsing_i(char **str);
char            *check_zeros(char *input);
int             check_duplicates(t_list *stack);
int             check_digits(char *str);
static int      check_limits(long j);
int             ft_atol(const char *str);
int 			*stk_limits(t_list *lst);
static t_list   *get_temp(t_stack *stk, int *aux, int *limits, int id);
static int 		*find_p(int n, t_list *lst, int phase);
void    		push_swap(char **str);
static void 	fill_list(t_list **lst, int amount, int *value);
void    		*calc_rot(t_list *lst, int *value, int stack, t_list **action);
void    		init_sort(t_stack *stk);
void    		sort_3(t_stack *stk);
int 			finish_check(t_stack *stk);


#endif
