/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:48:55 by aaronespino       #+#    #+#             */
/*   Updated: 2023/11/01 16:17:27 by aaespino         ###   ########.fr       */
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
	int 			index;
	int 			price;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
	bool			exceeds_center;
	bool			cheapest;
	bool			is_end;
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
	void 			ft_error_free(t_node **stack, char **argv, bool argc2);
	int 			ft_error_syntax(char *num);
	int 			ft_error_max(char *str);
	int 			ft_error_duplicate(t_node *node, int num);
//	gen_stack.c
	void			merge_nodes(t_node **stack, int nbr);
	void			gen_stack(t_node **stack, char **nums, bool argc2);
//	sort.c
	void 			ft_lil_sort(t_node **stack);
	void 			ft_sort(t_node **a, t_node **b);
//	nodes_init.c
	void 			set_current_position(t_node *stack);
	void			set_target_node(t_node *a, t_node *b, char which);
	void			ft_init_nodes(t_node *a, t_node *b);
	void			ft_init_back(t_node *a, t_node *b);
//	nodes_move.c
	void			ft_move_nodes(t_node **a, t_node **b);
	void			ft_move_back(t_node **a, t_node **b);
	void			finish_rotation(t_node **stack, t_node *top, char which);
//	utils
	int				ft_atoi(const char *str);
	long			ft_atol(const char *str);
	char	**ft_split(char *str, char separator);
	size_t			ft_strlen(const char *str);
//	new utils
	int 			ft_error_message(char num);
	void			ft_free_argv(char **argv);
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
	t_node			*ft_find_biggest(t_node *stack);


#endif
