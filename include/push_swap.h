/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:48:55 by aaronespino       #+#    #+#             */
/*   Updated: 2023/10/23 18:12:10 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_node
{
	int 			value;
	int 			current_position;
	int 			final_index;
	int 			push_price;
	bool			exceeds_center;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// actions

void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);

void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);

void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);

void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);

//	main
//	error_free.c
	void			ft_error_free(t_node **stack);
	int 			ft_error_syntax(char *num);
	int 			ft_error_max(char *str);
	void			ft_free_argv(char **argv);
	int 			ft_error_duplicate(t_node *node, int num);
//	gen_stack.c
	void			merge_nodes(t_node **stack, int nbr, int mode);
	void			gen_stack(t_node **stack, char **nums, bool argc_2);
//	sort.c
	void 			ft_lil_sort(t_node **stack);
//	utils
	int				ft_atoi(const char *str);
	long			ft_atol(const char *str);
	char			**ft_split(char const *s, char c);
	size_t			ft_strlen(const char *str);
//	new utils
	int 			ft_error_message(char num);
	void 			ft_free_stack(t_node **stack);
	int 			ft_num_begins(char *str);
	void			ft_lstadd_flinked(t_node **lst, t_node *new);
	void			ft_lstadd_blinked(t_node **lst, t_node *new);
	int				ft_lst_size(t_node *node);
	bool 			ft_lst_sorted(t_node *stack);
	t_node 			*ft_lst_last(t_node *node);
	void			ft_putstr_fd(char *s, int fd);
	int				ft_isdigit(int i);
	void 			ft_print_stack(t_node *stack);
	t_node			*ft_find_smallest(t_node *stack);


#endif
