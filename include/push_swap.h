/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:48:55 by aaronespino       #+#    #+#             */
/*   Updated: 2023/09/29 17:01:35 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

typedef struct lst_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack;

void			push_swap(char **str);
void 			error_message(char num);

t_list 			*parsing_input(char **str);
//util_parsing
int				check_digits(char *str);
int				check_duplicates(t_list *stack);
int				ft_atol(const char *str);
char			*check_zeros(char *input);
void 			error_message(char num);

//sorts
void			sort_3(t_stack *stk);
void			sort_algorithm(t_stack *stk);

//sort_3
int				last_check(t_stack *stk);

//sort_algorithm
int				*stk_limits(t_list *lst);
t_list			*calculate_moves(t_stack *stk, int *limits, int id);
void			*calc_rot(t_list *lst, int *value, int stack, t_list **action);
void			check_merge(t_list **lst);
void			add_push(t_list **action, int stack);

void			parse_move(t_stack *stk, t_list *actions);



#endif