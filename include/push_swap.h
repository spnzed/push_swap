/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:48:55 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/22 12:11:27 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define SWAP_A 'A'
# define PUSH_A 'B'
# define ROTATE_A 'C'
# define REV_ROTATE_A 'D'
# define SWAP_B 'E'
# define PUSH_B 'F'
# define ROTATE_B 'G'
# define REV_ROTATE_B 'H'
# define SWAP_S 'I'
# define ROTATE_R 'J'
# define REV_ROTATE_R 'K'

typedef struct lst_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack;

typedef struct lst_actions
{
	int	*ra;
	int	*rb;
	int	*rra;
	int	*rrb;
	int	*rr;
	int	*rrr;
}	t_actions;

void	actions_init(t_actions **actions);
void	actions_clear(t_actions **actions);

// 1. PARSING :
// Join inputs (Check zeros, digits) -> Convert to t_list (atol) -> Check_duplicates
t_list          *parsing_i(char **str);
// Join inputs (Check zeros, digits)
static  char    *join_input(char **input);
char            *check_zeros(char *input);
int             check_digits(char *str);
// Convert to t_list (atol)
static  t_list  *convert_to_tlist(char **input);
int             ft_atol(const char *str);
static int		check_limits(long j);
// Check_duplicates
int             check_duplicates(t_list *stack);

//stack_a == parsing_i / stack_b == NULL
//size == lst_size(stack_a)

//if 1<size<=3 -> sort_3 // else -> init_sort
// 2. SORT_3
void    		sort_3(t_stack *stk);
int 			finish_check(t_stack *stk);
//if lst_size(stack_a) < 3
// SWAP
static t_list   *swap(t_list *stack);
// else
void    		reverse_rotate_a(t_stack *stk, int print);
void    		rotate_a(t_stack *stk, int print);
void    		swap_a(t_stack *stk, int print);

// 3. ALGORITHM (init_sort)
void    		init_sort(t_stack *stk);


static void 	move(t_stack *stk);
int 			*stk_limits(t_list *lst);
t_list  		*calculate_moves(t_stack *stk, int *limits, int id);
static t_list   *get_temp(t_stack *stk, int *aux, int *limits, int id);
void    		*calc_rot(t_list *lst, int *value, int stack, t_list **action);
static void		fill_list(t_list **lst, int amount, int *value);
static int 		*find_p(int n, t_list *lst, int phase);
static t_list 	*get_cheapest(t_list *tmp_act, t_list *cheapest_act, int stack);
void    		check_merge(t_list **lst);
static t_list   *merge_actions(t_actions **acts);
static void 	add_actions(t_list **lst, int action, int times);
void    		add_push(t_list **action, int stack);
void    		parse_move(t_stack *stk, t_list *actions);
static void 	rotate_finish(t_stack *stk);

void    		push_swap(char **str);
static void 	fill_list(t_list **lst, int amount, int *value);

#endif
